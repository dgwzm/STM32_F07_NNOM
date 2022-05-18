'''
    Copyright (c) 2018-2020
    Jianjia Ma
    majianjia@live.com
    SPDX-License-Identifier: Apache-2.0
    Change Logs:
    Date           Author       Notes
    2019-02-12     Jianjia Ma   The first version
'''


import matplotlib.pyplot as plt
import os
import struct
nnscript = os.path.abspath(r'D:\BaiduYunDownload\LITS_data\nnom-master\nnom-master\scripts')
os.sys.path.append(nnscript)

from tensorflow.keras import *
from tensorflow.keras.datasets import mnist
from tensorflow.keras.layers import *
from tensorflow.keras.activations import *
from tensorflow.keras.models import load_model, save_model
import tensorflow as tf
import numpy as np
from nnom import *

model_name = r'D:\BaiduYunDownload\LITS_data\nnom-master\nnom-master\STM32_F4_nnom\mnist_f4.h5'
save_dir = model_name #os.path.join(os.getcwd(), model_name)

def dense_block(x, k):
    x1 = Conv2D(k, kernel_size=(3, 3), strides=(1,1), padding="same")(x)
    x1 = BatchNormalization()(x1)
    x1 = ReLU()(x1)

    x2 = concatenate([x, x1],axis=-1)
    x2 = Conv2D(k, kernel_size=(3, 3), strides=(1,1), padding="same")(x2)
    x2 = BatchNormalization()(x2)
    x2 = ReLU()(x2)

    x3 = concatenate([x, x1, x2],axis=-1)
    x3 = Conv2D(k, kernel_size=(3, 3), strides=(1,1), padding="same")(x3)
    x3 = BatchNormalization()(x3)
    x3 = ReLU()(x3)

    x4 = concatenate([x, x1, x2, x3],axis=-1)
    x4 = Conv2D(k, kernel_size=(3, 3), strides=(1,1), padding="same")(x4)
    x4 = BatchNormalization()(x4)
    x4 = ReLU()(x4)
    
    x5 = concatenate([x, x1, x2, x3, x4], axis=-1)
    return x5

def train(x_train, y_train, x_test, y_test, batch_size= 64, epochs = 100):

    inputs = Input(shape=x_train.shape[1:])
    x = Conv2D(4, kernel_size=(3, 3), strides=(1, 1), padding='same')(inputs)
    x = BatchNormalization()(x)
    x = ReLU()(x)
    x = MaxPool2D((2,2), strides=(2,2))(x)

    # bottleneck
    x = Conv2D(12, kernel_size=(3, 3), strides=(1, 1), padding="same")(x)
    x = BatchNormalization()(x)
    x = ReLU()(x)
    x = MaxPool2D((2, 2), strides=(2, 2))(x)

    x = Conv2D(12, kernel_size=(3, 3), strides=(1, 1), padding="same")(x)
    x = Dropout(0.3)(x)
    x = Flatten()(x)

    x = Dense(128)(x)
    x = Dropout(0.2)(x)
    x = Dense(10)(x)

    predictions = Softmax()(x)

    model = Model(inputs=inputs, outputs=predictions)

    model.compile(loss='categorical_crossentropy',
                  optimizer='adam',
                  metrics=['accuracy'])

    model.summary()

    # save best
    history = model.fit(x_train, y_train,
              batch_size=batch_size,
              epochs=epochs,
              verbose=2,
              validation_data=(x_test, y_test),
              shuffle=True)

    # free the session to avoid nesting naming while we load the best model after.
    save_model(model, save_dir)
    del model
    tf.keras.backend.clear_session()
    return history

def train_2(x_train, y_train, x_test, y_test, batch_size= 64, epochs = 100):

    inputs = Input(shape=x_train.shape[1:])
    x = Conv2D(4, kernel_size=(5, 5), strides=(1, 1), padding='same')(inputs)
    x = BatchNormalization()(x)
    x = ReLU()(x)
    x = MaxPool2D((2,2), strides=(2,2))(x)

    # dense block 1
    x = dense_block(x, k=8)

    # bottleneck
    x = Conv2D(12, kernel_size=(1, 1), strides=(1, 1), padding="same")(x)
    x = BatchNormalization()(x)
    x = ReLU()(x)
    x = MaxPool2D((2, 2), strides=(2, 2))(x)

    # dense block 2
    x = dense_block(x, k=16)

    x = Conv2D(24, kernel_size=(3, 3), strides=(1, 1), padding="same")(x)
    x = Dropout(0.3)(x)
    x = Flatten()(x)
    x = Dense(10)(x)

    predictions = Softmax()(x)

    model = Model(inputs=inputs, outputs=predictions)

    model.compile(loss='categorical_crossentropy',
                  optimizer='adam',
                  metrics=['accuracy'])

    model.summary()

    # save best
    history = model.fit(x_train, y_train,
              batch_size=batch_size,
              epochs=epochs,
              verbose=2,
              validation_data=(x_test, y_test),
              shuffle=True)

    # free the session to avoid nesting naming while we load the best model after.
    save_model(model, save_dir)
    del model
    tf.keras.backend.clear_session()
    return history

def main(weights):
    epochs = 100 # reduced for CI
    num_classes = 10

    # select different dataset as you wish
    dataset = 'mnist'
    #dataset = 'cifar'
    if(dataset in 'mnist'):
        (x_train, y_train), (x_test, y_test) = mnist.load_data()
        # add channel dimension for mnist data
        x_train = x_train.reshape(x_train.shape[0], x_train.shape[1], x_train.shape[2], 1)
        x_test = x_test.reshape(x_test.shape[0], x_test.shape[1], x_test.shape[2], 1)
    else:
        (x_train, y_train), (x_test, y_test) = tf.keras.cifar10.load_data()

    print(x_train.shape[0], 'train samples')
    print(x_test.shape[0], 'test samples')

    # Convert class vectors to binary class matrices.
    y_train = tf.keras.utils.to_categorical(y_train, num_classes)
    y_test = tf.keras.utils.to_categorical(y_test, num_classes)

    # quantize the range to 0~1
    x_test = x_test.astype('float32')/255
    x_train = x_train.astype('float32')/255
    print("data range", x_test.min(), x_test.max())

    # train
    history = train(x_train,y_train, x_test, y_test, batch_size=128, epochs=epochs)

    # get best model
    model = load_model(save_dir)
    
    acc = history.history['accuracy']
    val_acc = history.history['val_accuracy']
    plt.figure(1)
    plt.plot(range(0, epochs), acc, color='red', label='Training acc')
    plt.plot(range(0, epochs), val_acc, color='green', label='Validation acc')
    plt.title('Training and validation accuracy')
    plt.xlabel('Epochs')
    plt.ylabel('Loss')
    plt.legend()
    
    loss = history.history['loss']
    val_loss = history.history['val_loss']
    plt.figure(2)
    plt.plot(range(0, epochs), loss, color='red', label='Training loss')
    plt.plot(range(0, epochs), val_loss, color='green', label='Validation loss')
    plt.title('Training and validation loss')
    plt.xlabel('Epochs')
    plt.ylabel('Loss')
    plt.legend()
    plt.show()
    # evaluate
    # evaluate_model(model, x_test, y_test)

    # convert to model on nnom
    #generate_model(model, np.vstack((x_train, x_test)), name=weights)

    #return model,x_train,y_train,x_test,y_test

def show_loss():
    file_path=r"D:\BaiduYunDownload\LITS_data\nnom-master\nnom-master\STM32_F4_nnom\loss.txt"
    f=open(file_path,'r')
    data_list=f.readlines()
    train_loss_list=[]
    val_loss_list=[]
    data_len=0
    for i in data_list:
        if len(i)>80:
            data_len=data_len+1
            d=i.split(" ")
            train_loss=d[5]
            val_loss=d[11]
            train_loss_list.append(float(train_loss))
            val_loss_list.append(float(val_loss))
            
    plt.plot(range(0, data_len), train_loss_list, color='red', label='Training loss')
    plt.plot(range(0, data_len), val_loss_list, color='green', label='Validation loss')
    plt.title('Training and validation loss')
    plt.xlabel('Epochs')
    plt.ylabel('Loss')
    plt.legend()
    plt.show()


if __name__ == "__main__":
    show_loss()
    #weights=r"D:\BaiduYunDownload\LITS_data\nnom-master\nnom-master\STM32_F4_nnom\STM32_F4.h"
    #get_data()
    #main(weights)
    
    

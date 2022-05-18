import cv2
import os
import numpy as np
import struct

def generate_bin(x, y, file_name='test_data_with_label.bin',label_name='label.bin'):
    data_file = open(file_name,'wb')#二进制写模式
    label_file=open(label_name,'wb')#二进制写模式
    for d in range(len(x)):
        for i in x[d]:
            for j in i:
                a = struct.pack('B',j)
                data_file.write(a)
                
        ab= struct.pack('B',y[d])
        label_file.write(ab)
        
    label_file.close()
    data_file.close()

def get_data():
    (x_train, y_train), (x_test, y_test) = mnist.load_data()
    num_classes = 10

    x_test = x_test.astype('float32')/255
    x_test = x_test[:1000]
    y_test = y_test[:1000]
    x_test=x_test*127
    x_test=x_test.astype('int')
    generate_bin(x_test,y_test,
    file_name=r"D:\BaiduYunDownload\LITS_data\nnom-master\nnom-master\examples\mnist-densenet\test_data_2.bin",
    label_name=r"D:\BaiduYunDownload\LITS_data\nnom-master\nnom-master\examples\mnist-densenet\test_label_2.bin")
    
    print('x_train shape:', x_train.shape)
    print('y_train shape:', y_train.shape)
    print('x_test shape:', x_test.shape)
    print('y_test shape:', y_test.shape)

def resize(jpeg_buf):
    new_jpeg=jpeg_buf.reshape(224*224)
    getimage=np.zeros((28*28),dtype=np.uint8)
    max_val=30
    print(getimage.shape)
    for k in range(28*28):
        num=0;
        for m in range(8):
            for n in range(8):
                max=64*(int)(k/28)*28+(k-(int)(k/28)*28)*8+m*224+n;
                if(new_jpeg[max]==0):
                    num=num+1
        if(num>=max_val):
            getimage[k]=127
        else:
            getimage[k]=0

    return getimage,getimage.reshape(28,28)
    
def show_image_pixel(img):
    # 使用numpy方式创建一个二维数组
    height,width,shendu=img.shape
    new_img=np.zeros((224,224),dtype=np.uint8)
    for i in range(height):
        for j in range(width):
            R,G,B=img[i,j,0],img[i,j,1],img[i,j,2]
            val=R*0.5+G*0.8+B*0.2
            if(val>150):
                new_img[i][j]=225
            else:
                new_img[i][j]=0
    imgs,imgs_show=resize(new_img)
    #cv2.imshow("Picture", img)
    #cv2.imshow("Picture_2", new_img)
    #cv2.imshow("Resize Picture", imgs_show)
    #cv2.waitKey(0)
    
    return imgs_show
    #print('\n')

def get_new_pic():
    dir_path=r"D:\BaiduYunDownload\LITS_data\nnom-master\nnom-master\examples\mnist-densenet\pic"
    new_dir_path=r"D:\BaiduYunDownload\LITS_data\nnom-master\nnom-master\examples\mnist-densenet\new_pic"
    pic_list=os.listdir(dir_path)
    for i in pic_list:
        pic_path=os.path.join(dir_path,i)
        img = cv2.imread(pic_path)
        new_img = cv2.resize(img, (224,224))
        cv2.imwrite(os.path.join(new_dir_path,i), new_img)
    print("OK")
    
    
def read_jpg():
    dir_path=r"D:\BaiduYunDownload\LITS_data\nnom-master\nnom-master\examples\mnist-densenet\new_pic"
    file_name=r"D:\BaiduYunDownload\LITS_data\nnom-master\nnom-master\examples\mnist-densenet\shoot_pic.bin"
    label_name=r"D:\BaiduYunDownload\LITS_data\nnom-master\nnom-master\examples\mnist-densenet\shoot_label.bin"
    pic_list=os.listdir(dir_path)
    data_list=[]
    label_list=[]
    for i in pic_list:
        label=int(i.split("-")[1][:-4])
        if(label>10):
            assert "error"
        pic_path=os.path.join(dir_path,i)
        resize_imgs=show_image_pixel(cv2.imread(pic_path))
        data_list.append(resize_imgs)
        label_list.append(label)
        
    generate_bin(data_list,label_list,file_name,label_name)
    
    
if __name__ == "__main__":
    read_jpg()
    
    
    
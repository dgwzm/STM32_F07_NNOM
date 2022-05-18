import sys
data_str = sys.stdin.readline().split("\n")[0]
data=[
[1,1,1,1,1,1,0],
[0,0,1,1,0,0,0],
[0,1,1,0,1,1,1],
[0,1,1,1,1,0,1],
[1,0,1,1,0,0,1],
[1,1,0,1,1,0,1],
[1,1,0,1,1,1,1],
[0,1,1,1,0,0,0],
[1,1,1,1,1,1,1],
[1,1,1,1,1,0,1],
[0,0,0,0,0,0,0]
]

def get_change(list_1,list_2):
    num=0
    for i,j in zip(list_1,list_2):
        if i != j:
            num=num+1
    return num
all_num=get_change(data[10],data[int(data_str[0])])
for i in range(0,len(data_str)-1):
    num=get_change(data[int(data_str[i])],data[int(data_str[i+1])])
    all_num=all_num+num
print(all_num)

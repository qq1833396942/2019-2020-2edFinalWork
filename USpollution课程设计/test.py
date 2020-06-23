'''
@Author: your name
@Date: 2020-06-24 02:25:33
@LastEditTime: 2020-06-24 05:06:57
'''
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import xlwt #需要的模块
Hou=[]
Nyk=[]
Dc=[]


def question_1():
    data = pd.read_csv('3.pollution_us_5city_2006_2010_O3.csv')
    print(data.head(5))
    print(data.iloc[53218])
    print("------------------------------------------------------------------")
    print(data.iloc[53219])

def question_2():
    yearData = []
    data = pd.read_csv('3.pollution_us_5city_2006_2010_O3.csv')
    data = data.values.tolist()
    i=0
    while(i<len(data)):
        date = str(data[i][8]).split("/")
        year = int(date[0])
        if year>=2007 and year<=2009:
            yearData.append(data[i])
        i+=1
    name = ['ID','State Code','County Code','Site Num','Address',
            'State','County','City','DateLocal','O3 Units','O3 Mean',
            'O3 1st Max Value','O3 1st Max Hour','O3 AQI']
    test=pd.DataFrame(columns=name,data=yearData)#数据有三列，列名分别为one,two,three
    test.to_csv('pollution_us_5city_2007_2009_O3.csv',encoding='utf-8')

def text_save(filename, data):#filename为写入CSV文件的路径，data为要写入数据列表.
    file = open(filename,mode='w')
    for i in data:
        s = ",".join('%s' %id for id in i)
        file.write(s)
        file.write('\n')
    file.close()

def question_3():
    hou=[]
    nyk=[]
    dc=[]
    i=0
    data = pd.read_csv('pollution_us_5city_2007_2009_O3.csv')
    data = data.values.tolist()
    while(i<len(data)):
        if data[i][8] == "Houston":
            hou.append(data[i])
        elif data[i][8] == "New York":
            nyk.append(data[i])
        elif data[i][8] == "Washington":
            dc.append(data[i])
        i+=1
    text_save("pollution_us_Houston_2007_2009_O3.txt",hou)
    text_save("pollution_us_NewYork_2007_2009_O3.txt",nyk)
    text_save("pollution_us_Washington_2007_2009_O3.txt",dc)

def txt2xls(filename,xlsname):  #文本转换成xls的函数，filename 表示一个要被转换的txt文本，xlsname 表示转换后的文件名
    f = open(filename)   #打开txt文本进行读取
    x = 0                #在excel开始写的位置（y）
    y = 0                #在excel开始写的位置（x）
    xls=xlwt.Workbook()
    sheet = xls.add_sheet('sheet1',cell_overwrite_ok=True) #生成excel的方法，声明excel
    while True:  #循环，读取文本里面的所有内容
        line = f.readline() #一行一行读取
        if not line:  #如果没有内容，则退出循环
            break
        for i in line.split('\t'):#读取出相应的内容写到x
            item=i.strip()
            sheet.write(x,y,item)
            y += 1 #另起一列
        x += 1 #另起一行
        y = 0  #初始成第一列
    f.close()
    xls.save(xlsname+'.xls') #保存

def question_4():
    txt2xls("pollution_us_Houston_2007_2009_O3.txt","pollution_us_Houston_2007_2009_O3")
    txt2xls("pollution_us_NewYork_2007_2009_O3.txt","pollution_us_NewYork_2007_2009_O3")
    txt2xls("pollution_us_Washington_2007_2009_O3.txt","pollution_us_Washington_2007_2009_O3")

def question_5():
    hou1=[]
    hou2=[]
    hou3=[]
    nyk1=[]
    nyk2=[]
    nyk3=[]
    dc1=[]
    dc2=[]
    dc3=[]
    file = open("pollution_us_Houston_2007_2009_O3.txt")
    for line in file:
        list = line.split(",")
        hou1.append(float(list[11]))
        hou2.append(float(list[12].rstrip("\n")))
        hou3.append(float(list[13]))
    file.close()
    file = open("pollution_us_NewYork_2007_2009_O3.txt")
    for line in file:
        list = line.split(",")
        nyk1.append(float(list[11]))
        nyk2.append(float(list[12].rstrip("\n")))
        nyk3.append(float(list[13]))
    file.close()
    file = open("pollution_us_Washington_2007_2009_O3.txt")
    for line in file:
        list = line.split(",")
        dc1.append(float(list[13]))
        dc2.append(float(list[15].rstrip("\n")))
        dc3.append(float(list[16]))
    file.close()
    print(len(hou1),len(hou2),len(hou3))
    print(len(dc1),len(dc2),len(dc3))
    print(len(nyk1),len(nyk2),len(nyk3))
    start = 2007
    for i in range(0,8330):
        start+=2/8330
        Hou.append(start)
    start = 2007
    for i in range(0,4238):
        start += 2/4238
        Dc.append(start)
    start = 2007
    for i in range(0,9848):
        start+=2/9848
        Nyk.append(start)
    fig = plt.figure(figsize=(20, 4))
    plt.plot(Hou,hou1,color="blue",label="Houston")
    plt.plot(Nyk,nyk1,color="red",label="New York")
    plt.plot(Dc,dc1,color="green",label="DC")
    plt.title("o3_mean")
    plt.savefig("o3_mean.png", dpi=600)
    plt.show()
    fig = plt.figure(figsize=(20, 4))
    plt.plot(Hou,hou2,color="blue",label="Houston")
    plt.plot(Nyk,nyk2,color="red",label="New York")
    plt.plot(Dc,dc2,color="green",label="DC")
    plt.title("o3_1st_max_hour")
    plt.savefig("o3_1st_max_hour.png", dpi=600)
    plt.show()
    fig = plt.figure(figsize=(20, 4))
    plt.plot(Hou,hou3,color="blue",label="Houston")
    plt.plot(Nyk,nyk3,color="red",label="New York")
    plt.plot(Dc,dc3,color="green",label="DC")
    plt.title("o3_AQI")
    plt.savefig("o3_AQI.png", dpi=600)
    plt.show()
    

def main():
    a=input("请选择：1,2,3,4,5")
    if int(a)==1:
        question_1()
    elif int(a)==2:
        question_2()
    elif int(a)==3:
        question_3()
    elif int(a)==4:
        question_4()
    elif int(a)==5:
        question_5()

if __name__ == "__main__":
    main()
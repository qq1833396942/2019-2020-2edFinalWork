import pandas as p
from pandas.core.frame import DataFrame
import sys
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.pyplot import MultipleLocator
plt.rcParams['font.sans-serif'] = 'SimHei' #显示中文不乱码
plt.rcParams['axes.unicode_minus'] = False #显示负数不乱码

def A1(list):
    print("list长度为",len(list))
    i = 1   #跳过表头
    A1_data = []    #建立预存列表
    #小于长度是一个条件
    while(i<len(list)):
        #当小于11没有办法求前十个，直接累加到自己
        if(i<11):
            j = 0
            count = 1
            while(count<=i):
                j+=float(list[count][5])
                count+=1
            i+=1
            A1_data.append(float(list[count][5])/(count/i))
        #正常情况就很安全，累加到十个
        else:
            j = 0
            for count in range(i - 10, i):
                j += float(list[count][5])
            i+=1
            A1_data.append(float(list[count][5]) / (count / 10))
    #测试，查看长度
    result = {"A1":A1_data}
    result = DataFrame(result)  #算到dataframe写入到csv文件
    result.to_csv('A1_result.csv')
    print(result)

def A2(list):
    print("list长度为", len(list))
    A2_data = [0]   #创建列表
    i = 2
    #以长度为限制条件
    while(i<len(list)):
        #用append函数添加至尾巴
        A2_data.append((float(list[i][5]) - float(list[i-1][5])) / float(list[i-1][5]))
        i+=1
    #print(A2_data)
    result = {"A2": A2_data}
    result = DataFrame(result)
    result.to_csv('A2_result.csv')
    print(result)

def A3(list):
    print("list长度为", len(list))
    i = 1  # 跳过表头
    A3_data = []
    while (i < len(list)):
        if (i < 11):
            j = 0
            count = 1
            while (count <= i):
                j += float(list[count][5])
                count += 1
            i += 1
            A3_data.append(float(list[count][3]) / (count / i))
        else:
            j = 0
            for count in range(i - 10, i):
                j += float(list[count][5])
            i += 1
            A3_data.append(float(list[count][3]) / (count / 10))
    # 测试，查看长度
    #print(A3_data)
    result = {"A3": A3_data}
    result = DataFrame(result)
    result.to_csv('A3_result.csv')
    print(result)

def A4(list):
    i = 1
    A4_data = []
    while(i<len(list)):
        #当小于整个长度的时候求极差，加入列表
        A4_data.append(float(list[i][3])-float(list[i][4]))
        i+=1
    #print(A4_data)
    #写入csv文件
    result = {"A4": A4_data}
    result = DataFrame(result)
    result.to_csv('A4_result.csv')
    print(result)

def Y(list):
    Y_data=[]
    print(len(list))
    for i in range(1,len(list)):
        #在长度内
        if i != 245:
            if(float(list[i + 1][5]) - float(list[i][5]))>0:
                Y_data.append(1)    #大于0写入1
            else:
                Y_data.append(-1)   #小于等于0写入-1
        #最后一天没法判断，直接写入-1
        elif i == 245:
            Y_data.append(-1)
    result = {"Y": Y_data}
    result = DataFrame(result)
    result.to_csv('Y_result.csv')
    print(result)

def printLine(list):
    date = []   #准备一个日期的列表
    startValue = [] #开始的价钱
    endValue = []   #结束的价钱
    for i in range(1,len(list)):
        #把每天的数据录入
        date.append(list[i][1])
        startValue.append(float(list[i][2]))
        endValue.append(float(list[i][5]))

    #设置图片大小
    plt.figure(figsize=(18, 8))  #设置title
    plt.title("沪深300指数2019年全年交易日开盘价收盘价对比")

    ax = plt.gca()  #实例化坐标系
    x_major_locator = MultipleLocator(4)    #设置x轴间隔
    y_major_locator = MultipleLocator(100)  #设置y轴间隔
    ax.xaxis.set_major_locator(x_major_locator)
    ax.yaxis.set_major_locator(y_major_locator)

    plt.xticks(size = 9,rotation = 90)
    plt.ylim(1500, 3800)    #设置y轴区间

    plt.plot(date, startValue, c='green',label='开盘价')    #开盘价-绿色
    plt.plot(date, endValue, c='blue',label='收盘价')       #收盘价-蓝色
    plt.legend()
    plt.savefig("开盘价与收盘价对比.png", dpi=600)  #保存图片
    plt.show()

def printHistogram(list):
    date = []
    quality = []
    for i in range(1,len(list)):
        date.append(list[i][1])
        quality.append(float(list[i][6]))
    plt.figure(figsize=(20, 8)) #大小
    plt.title("沪深300指数2019年全年交易量")    #title

    #设置以4分段
    ax = plt.gca()
    ax.xaxis.set_major_locator(MultipleLocator(4))
    plt.xticks(size=9, rotation=90) #翻转九十度
    plt.ylim(0, 8000000)    #y轴区间
    plt.bar(date, quality, width=0.5, align="center")   #直方图
    plt.savefig("成交量直方图.png", dpi=600)    #保存图片
    plt.show()

def function(list):
    print("1.计算A1")   #打印菜单
    print("2.计算A2")
    print("3.计算A3")
    print("4.计算A4")
    print("5.计算Y")
    print("6.沪深300指数2019年全年交易日开盘价收盘价对比")
    print("7.沪深300指数2019年全年交易量")
    print("8.结束程序")
    choice = input("请选择执行哪一步操作：")
    print('\n')
    if choice == '1':
        A1(list)
    elif choice == '2':
        A2(list)
    elif choice == '3':
        A3(list)
    elif choice == '4':
        A4(list)
    elif choice == '5':
        Y(list)
    elif choice == '6':
        printLine(list)
    elif choice == '7':
        printHistogram(list)
    elif choice == "8":
        print("程序结束")
        sys.exit(0)

def main():
    #读取数据
    data = p.read_csv('沪深300指数2019年交易数据_5.csv', header=None)
    #dataframe类型编程列表类型
    list = data.values.tolist()
    print(data)
    while(True):
        function(list)
        answer = input('是否结束程序？[y/n]')
        if answer == 'y':
            sys.exit(0)
        else:
            continue


if __name__ == '__main__':
    main()

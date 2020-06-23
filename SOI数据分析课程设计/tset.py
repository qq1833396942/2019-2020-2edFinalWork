'''
@Author: your name
@Date: 2020-06-23 17:15:45
@LastEditTime: 2020-06-23 18:57:02
@LastEditors: Please set LastEditors
'''
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
maxValue = "1"
minValue = "2"

def question_1():
    data = pd.read_csv('15.soi.long.data.csv')
    #准备构建月份字典
    columnNum = [1,2,3,4,5,6,7,8,9,10,11,12]
    columnName = data.columns.tolist()  
    columnName.pop(0)
    columnDict = dict(zip(columnName,columnNum))
    #连接字符串
    fileName = input("请输入文件名称：")
    file = open(fileName+".txt", mode='a', encoding='utf-8')
    print("Date,SOI", file=file)
    for i in range(0,153):
        year = data.iloc[[i],[0]]
        yearStr = np.array(year)
        for j in range(0,12):
            SOI = data.iloc[[i],[j+1]]
            SOIvalue = np.array(SOI)
            print(str(yearStr[0][0])+"-"+str(columnNum[j])+"-1,"+str(SOIvalue[0][0]), file=file)
    file.close()
    print("数据预处理完成")

def question_2():
    SOIvalue = []
    totalValue = 0
    index = -1
    #fileName = input("请输入第二题的目标文件名：")
    fileName = "soi_dropnan"
    file = open(fileName+".txt")
    for line in file:
        if index==-1:
            index=0
            continue
        else:
            list = line.split(",")
            totalValue+=float(list[1])
            SOIvalue.append(float(list[1]))
            index+=1
    file.close()
    print("最大值为："+str(max(SOIvalue)))
    print("最小值为："+str(min(SOIvalue)))
    print("平均值为：" + str(totalValue / index))
    return max(SOIvalue),min(SOIvalue),SOIvalue

def question_3():
    maxVal,minVal,SOIdata = question_2()
    #离散化处理
    nino = 0
    lanina = 0
    bins = [minVal,0,maxVal]
    p_counts = pd.cut(SOIdata, bins, labels =['NinoRelate','LaNinaRelate'])
    for ele in p_counts:
        if ele == "NinoRelate":
            nino+=1
        else:
            lanina+=1
    ninoPercent = round(nino/len(p_counts),5)
    laninaPercent = round(lanina/len(p_counts),5)
    labels = "NinoRelate","LaNinaRelate"
    fracs = [ninoPercent,laninaPercent]
    plt.axes(aspect=1)
    plt.title("Relationship")
    plt.pie(x=fracs,labels=labels,autopct='%.3f%%')
    plt.savefig("soi_ pie.png", dpi=600)
    plt.show()

def question_4():
    yearNum=[]
    maxVal, minVal, SOIdata = question_2()
    data = pd.read_csv('15.soi.long.data.csv')
    for i in range(0, 153):
        year = data.iloc[[i], [0]]
        yearStr = np.array(year)
        yearNum.append(int(yearStr[0][0]))
    lineData = dict(zip(yearNum,SOIdata))
    x = [i for i in lineData.keys()]
    y = [i for i in lineData.values()]

    fig = plt.figure(figsize=(10, 7))
    x_major_locator = plt.MultipleLocator(10)
    y_major_locator = plt.MultipleLocator(0.5)
    ax = plt.gca()
    ax.xaxis.set_major_locator(x_major_locator)
    ax.yaxis.set_major_locator(y_major_locator)
    plt.xlim(1860, 2024)
    plt.ylim(-5.5, 5.6)
    plt.plot(x, y, label="SOI")
    plt.legend()
    plt.show()


def main():
    question_3()


if __name__ == "__main__":
    main()
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def question_1():
    data = pd.read_csv('16.nao.long.data.csv')
    #准备构建月份字典
    columnNum = [1,2,3,4,5,6,7,8,9,10,11,12]
    columnName = data.columns.tolist()
    columnName.pop(0)
    columnDict = dict(zip(columnName,columnNum))
    #连接字符串
    file = open("nao_dropnan.txt", mode='a', encoding='utf-8')
    print("Date,NAO", file=file)
    for i in range(0,195):
        year = data.iloc[[i],[0]]
        yearStr = np.array(year)
        for j in range(0,12):
            NAO = data.iloc[[i],[j+1]]
            NAOvalue = np.array(NAO)
            if NAOvalue[0][0] == -99.99:
                NAOvalue[0][0] = -1
            print(str(yearStr[0][0])+"-"+str(columnNum[j])+"-1,"+str(NAOvalue[0][0]), file=file)

    file.close()
    print("数据预处理完成")

def question_2():
    NAOvalue = []
    totalValue = 0
    index = -1
    fileName = "nao_dropnan.txt"
    file = open(fileName)
    for line in file:
        if index==-1:
            index=0
            continue
        else:
            list = line.split(",")
            totalValue+=float(list[1])
            NAOvalue.append(float(list[1]))
            index+=1
    file.close()
    print("最大值为："+str(max(NAOvalue)))
    print("最小值为："+str(min(NAOvalue)))
    print("平均值为：" + str(totalValue / index))
    return max(NAOvalue),min(NAOvalue),NAOvalue

def question_3():
    maxVal,minVal,NAOdata = question_2()
    #离散化处理
    cold = 0
    warm = 0
    bins = [minVal,0,maxVal]
    p_counts = pd.cut(NAOdata, bins, labels =['ColdRelate','WarmRelate'])

    # 建立新的csv
    date = []
    data = pd.read_csv('16.nao.long.data.csv')
    for i in range(0, 195):
        year = data.iloc[[i],[0]]
        yearStr = np.array(year)
        for j in range(0, 12):
            columnNum = [1,2,3,4,5,6,7,8,9,10,11,12]
            date.append(str(yearStr[0][0]) + "-" + str(columnNum[j]) + "-1")
        date.append(yearStr[0][0])
    # 字典中的key值即为csv中列名
    dataframe = pd.DataFrame({'Date': date, 'NAO': NAOdata, 'Label':p_counts})

    # 将DataFrame存储为csv,index表示是否显示行名，default=True
    dataframe.to_csv("nao_dropnan_result.csv", index=False, sep=',')

    #绘图
    for ele in p_counts:
        if ele == "ColdRelate":
            cold+=1
        else:
            warm+=1
    coldPercent = round(cold/len(p_counts),5)
    warmPercent = round(warm/len(p_counts),5)
    labels = "ColdRelate","WarmRelate"
    fracs = [coldPercent,warmPercent]
    plt.axes(aspect=1)
    plt.title("Relationship")
    plt.pie(x=fracs,labels=labels,autopct='%.3f%%')
    plt.savefig("soi_ pie.png", dpi=600)
    plt.show()

def question_4():
    yearNum=[]
    maxVal, minVal, NAOdata = question_2()
    data = pd.read_csv('16.nao.long.data.csv')
    for i in range(0, 195):
        year = data.iloc[[i], [0]]
        yearStr = np.array(year)
        yearNum.append(int(yearStr[0][0]))
    lineData = dict(zip(yearNum,NAOdata))
    x = [i for i in lineData.keys()]
    y = [i for i in lineData.values()]

    fig = plt.figure(figsize=(10, 7))
    x_major_locator = plt.MultipleLocator(10)
    y_major_locator = plt.MultipleLocator(0.5)
    ax = plt.gca()
    ax.xaxis.set_major_locator(x_major_locator)
    ax.yaxis.set_major_locator(y_major_locator)
    plt.xlim(1820, 2024)
    plt.ylim(-5.5, 5.6)
    plt.plot(x, y, label="NAO")
    plt.legend()
    plt.show()

def main():
    #question_1()
    #警告！！！每次运行前question_2函数前务必务必删除.txt文件
    #question_2()
    question_4()

if __name__ == '__main__':
    main()
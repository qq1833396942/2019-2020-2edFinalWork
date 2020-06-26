import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import csv
import xlwt #需要的模块

def question_1():
    data = pd.read_csv('6.PRSA_data_2010.1.1-2014.12.31.csv')
    print("前五行信息如下：")
    print(data.head(5))
    print("后两行信息如下：")
    print(data.iloc[43822])
    print("----------------------------------------------")
    print(data.iloc[43823],"\n")

def question_2():
    with open("6.PRSA_data_2010.1.1-2014.12.31.csv") as f:
        f_csv = csv.reader(f)
        with open("pm25_data_2010.1.1-2014.12.31.csv", "w+", newline='') as f_1:
            f_1_csv = csv.writer(f_1)
            for row in f_csv:
                if row[5] == "NA":
                    continue
                else:
                    f_1_csv.writerow([row[0],row[1],row[2],row[3],row[4],row[5]])
            f_1.close()
        f.close()
    print("写入完成\n")

def question_3():
    data = pd.read_csv("pm25_data_2010.1.1-2014.12.31.csv")
    file = open("pm25_hazardous_data_2010.1.1-2014.12.31.txt", mode='a', encoding='utf-8')
    for i in range(0,len(data)):
        pm2_5 = data.iloc[[i],[5]]
        pm2_5Str = np.array(pm2_5)
        if pm2_5Str[0][0]>300:
            msg=""
            for j in range(0,6):
                singleData = data.iloc[[i],[j]]
                singleDataStr = np.array(singleData)
                if j < 5:
                    msg += str(singleDataStr[0][0])+","
                else:
                    msg += str(singleDataStr[0][0])+"\n"
            print(msg,file = file)
        else:
            continue

def question_4():
    txtname = 'pm25_hazardous_data_2010.1.1-2014.12.31.txt'
    excelname = 'pm25_hazardous_data_2010.1.1-2014.12.31.xls'
    #打开文件，逐行读取
    fopen = open(txtname, 'r')
    lines = fopen.readlines()
    file = xlwt.Workbook(encoding='utf-8', style_compression=0)
    # 新建一个sheet
    sheet = file.add_sheet('data')

    i = 0
    for line in lines:
        line = line.strip('\n')
        line = line.split(',')
        No = line[0]
        year = line[1]
        month = line[2]
        day = line[3]
        hour = line[4]
        pm2_5 = line[5]

        sheet.write(i, 0, No)
        sheet.write(i, 1, year)
        sheet.write(i, 2, month)
        sheet.write(i, 3, day)
        sheet.write(i, 4, hour)
        sheet.write(i, 5, pm2_5)
        i = i + 1

    file.save(excelname)

def question_5():
    csvFile = open("data.csv", 'w', newline='', encoding='utf-8')
    writer = csv.writer(csvFile)
    csvRow = []

    f = open("pm25_hazardous_data_2010.1.1-2014.12.31.txt", 'r', encoding='GB2312')
    for line in f:
        csvRow = line.strip("\n")
        csvRow = csvRow.split(",")
        writer.writerow(csvRow)
    f.close()
    csvFile.close()

    #读取csv文件，并为其添加表头label
    data = pd.read_csv('data.csv',header=None,names=['No','year','month','day','hour','pm2_5'])
    print("月份（month）出现次数降序排列如下")
    print(data.loc[:,'month'].value_counts(),"\n")  #value_counts()函数，统计该列中元素出现的次数
    print("日期（day）出现次数降序排列如下")
    print(data.loc[:,'day'].value_counts(),"\n")
    print("小时（hour）出现次数降序排列如下")
    print(data.loc[:,'hour'].value_counts(),"\n")
    #通过得到的序列构建字典,并直接进行按日期时间顺序排序处理
    a = data.loc[:, 'month'].value_counts().to_dict()
    aOrder = sorted(a.items(),key=lambda x:x[0],reverse=False)
    b = data.loc[:, 'day'].value_counts().to_dict()
    bOrder = sorted(b.items(), key=lambda x: x[0], reverse=False)
    c = data.loc[:, 'hour'].value_counts().to_dict()
    cOrder = sorted(c.items(), key=lambda x: x[0], reverse=False)
    #把字典的key与value分离，准备绘制直方图
    aKeys,bKeys,cKeys = list(a.keys()),list(b.keys()),list(c.keys())
    aValues,bValues,cValues = list(a.values()),list(b.values()),list(c.values())

    # 第一行第一列图形
    ax1 = plt.subplot(2, 2, 1)
    # 第一行第二列图形
    ax2 = plt.subplot(2, 2, 2)
    # 第二行
    ax3 = plt.subplot(2, 1, 2)

    plt.sca(ax1)
    plt.bar(aKeys,aValues, label='month',color='red')
    plt.legend()
    plt.xlabel('month')
    plt.ylabel('count')
    plt.sca(ax2)
    plt.bar(cKeys, cValues, label='hour',color='green')
    plt.legend()
    plt.xlabel('hour')
    plt.ylabel('count')
    plt.sca(ax3)
    plt.bar(bKeys, bValues, label='month',color='blue')
    plt.legend()
    plt.xlabel('day')
    plt.ylabel('count')
    plt.savefig("pm25_hazardous_month_day_hour.png", dpi=400)
    plt.show()

def main():
    while True:
        a = int(input("请输入选择运行的题号"))
        if a == 1:
            question_1()
        elif a == 2:
            question_2()
        elif a == 3:
            question_3()
        elif a == 4:
            question_4()
        elif a == 5:
            question_5()



if __name__ == '__main__':
    main()
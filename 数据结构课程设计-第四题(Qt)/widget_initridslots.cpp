#include <direct.h>
#include <windows.h>

#include <QBrush>
#include <QDebug>
#include <QDesktopServices>
#include <QFile>
#include <QFont>
#include <QMessageBox>
#include <QUrl>

#include "crawler.h"
#include "rid.h"
#include "ui_widget.h"
#include "widget.h"

void Widget::slotInitRidComplete(const QString &filename, int state) {
    working = false;
    qDebug() << "倒排索引建立完成";
    qDebug() << filename + QString::fromStdString(RID_NOTICE[state]);
    QString text = "倒排索引建立完成";
    ui->labelStatus->setText(text);
}

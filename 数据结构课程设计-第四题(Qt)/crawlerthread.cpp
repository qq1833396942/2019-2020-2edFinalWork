#include "crawlerthread.h"

#include "crawler.h"

CrawlerThread::CrawlerThread(QObject *parent) : QThread(parent) {}

void CrawlerThread::run() {
    int pageCount = crawler();
    emit crawlComplete(pageCount);
}

void CrawlerThread::slotCrawlParameter(const QString &str, int maxNumber) {
    entry = str;
    MAXFILECOUNT = maxNumber;
}

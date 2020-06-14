#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T11:06:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CUGSo
TEMPLATE = app
RC_ICONS = globe_search.ico

SOURCES += \
    main.cpp \
    widget.cpp \
    crawlerthread.cpp \
    widget_crawlslots.cpp \
    widget_funcs.cpp \
    crawler3.1.cpp \
    widget_initridslots.cpp \
    initridthread.cpp \
    rid2.1.cpp \
    expr.cpp

HEADERS  += \
    widget.h \
    cppjieba/include/cppjieba/Jieba.hpp \
    cppjieba/deps/limonp/ArgvContext.hpp \
    cppjieba/deps/limonp/BlockingQueue.hpp \
    cppjieba/deps/limonp/BoundedBlockingQueue.hpp \
    cppjieba/deps/limonp/BoundedQueue.hpp \
    cppjieba/deps/limonp/Closure.hpp \
    cppjieba/deps/limonp/Colors.hpp \
    cppjieba/deps/limonp/Condition.hpp \
    cppjieba/deps/limonp/Config.hpp \
    cppjieba/deps/limonp/FileLock.hpp \
    cppjieba/deps/limonp/ForcePublic.hpp \
    cppjieba/deps/limonp/LocalVector.hpp \
    cppjieba/deps/limonp/Logging.hpp \
    cppjieba/deps/limonp/Md5.hpp \
    cppjieba/deps/limonp/MutexLock.hpp \
    cppjieba/deps/limonp/NonCopyable.hpp \
    cppjieba/deps/limonp/StdExtension.hpp \
    cppjieba/deps/limonp/StringUtil.hpp \
    cppjieba/deps/limonp/Thread.hpp \
    cppjieba/deps/limonp/ThreadPool.hpp \
    cppjieba/include/cppjieba/DictTrie.hpp \
    cppjieba/include/cppjieba/FullSegment.hpp \
    cppjieba/include/cppjieba/HMMModel.hpp \
    cppjieba/include/cppjieba/HMMSegment.hpp \
    cppjieba/include/cppjieba/KeywordExtractor.hpp \
    cppjieba/include/cppjieba/MixSegment.hpp \
    cppjieba/include/cppjieba/MPSegment.hpp \
    cppjieba/include/cppjieba/PosTagger.hpp \
    cppjieba/include/cppjieba/PreFilter.hpp \
    cppjieba/include/cppjieba/QuerySegment.hpp \
    cppjieba/include/cppjieba/SegmentBase.hpp \
    cppjieba/include/cppjieba/SegmentTagged.hpp \
    cppjieba/include/cppjieba/TextRankExtractor.hpp \
    cppjieba/include/cppjieba/Trie.hpp \
    cppjieba/include/cppjieba/Unicode.hpp \
    crawlerthread.h \
    rid.h \
    crawler.h \
    initridthread.h \
    mystack.h \
    expr.h
FORMS    += widget.ui

CONFIG += c++11

DISTFILES +=

LIBS += -lws2_32

DEFINES-= UNICODE #for ExecuteShellA's use

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

test {
    message(Test build)
    isEmpty(CATCH_INCLUDE_DIR): CATCH_INCLUDE_DIR=$$(CATCH_INCLUDE_DIR)
    # set by Qt Creator wizard
    isEmpty(CATCH_INCLUDE_DIR): CATCH_INCLUDE_DIR= $$PWD
    !isEmpty(CATCH_INCLUDE_DIR): INCLUDEPATH *= $${CATCH_INCLUDE_DIR}

    isEmpty(CATCH_INCLUDE_DIR): {
            message("CATCH_INCLUDE_DIR is not set, assuming Catch2 can be found automatically in your system")
    }

    TARGET = demo-test
    INCLUDEPATH += $$PWD/include/test

    QT += testlib
    SOURCES += \
        test/main.cpp \
        test/tst_testsuite.cpp

    HEADERS += \
        test/abc.h \
        settings.h

} else {
    message(Normal build)

    SOURCES += \
        main.cpp \
        mainwindow.cpp \
        settings.cpp

    HEADERS += \
        mainwindow.h \
        settings.h

    FORMS += \
        mainwindow.ui

    # Default rules for deployment.
    qnx: target.path = /tmp/$${TARGET}/bin
    else: unix:!android: target.path = /opt/$${TARGET}/bin
    !isEmpty(target.path): INSTALLS += target

}


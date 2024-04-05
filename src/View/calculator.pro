QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Controller/s21_Controller.cpp \
    ../Model/s21_credit_cacl.cpp \
    ../Model/s21_model_calc.cpp \
    ../Model/s21_vklad_cacl.cpp \
    credit_calc.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    vklad_calc.cpp

HEADERS += \
    ../Model/s21_model_calc.h \
    ../Controller/s21_Controller.h \
    credit_calc.h \
    mainwindow.h \
    qcustomplot.h \
    vklad_calc.h

FORMS += \
    credit_calc.ui \
    mainwindow.ui \
    vklad_calc.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    calculator.app

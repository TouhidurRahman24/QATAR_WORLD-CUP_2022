QT       += core gui sql printsupport
QT += webview
QT += multimedia
qtmultimedia5-dev
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    group.cpp \
    lineup.cpp \
    main.cpp \
    main_menu.cpp \
    roadmap.cpp \
    ticket.cpp \
    venue.cpp

HEADERS += \
    group.h \
    lineup.h \
    main_menu.h \
    roadmap.h \
    ticket.h \
    venue.h

FORMS += \
    group.ui \
    lineup.ui \
    main_menu.ui \
    roadmap.ui \
    ticket.ui \
    venue.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    worldcup.qrc


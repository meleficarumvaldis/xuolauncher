VERSION = 1.0.2

DEFINES += APP_VERSION=\\\"$$VERSION\\\"

CONFIG(release, debug|release) {
    DEFINES += USE_RELEASE=1
}
CONFIG(debug, debug|release) {
    DEFINES += USE_DEBUG=1
}
unix:!macx {
    DEFINES += USE_RELAUNCH=1 BUILD_LINUX=1 BUILD_MACOS=0 BUILD_WINDOWS=0
}
win32|win64 {
    DEFINES += USE_RELAUNCH=1 BUILD_WINDOWS=1 BUILD_LINUX=0 BUILD_MACOS=0
}
macx {
    DEFINES += BUILD_MACOS=1 BUILD_LINUX=0 BUILD_WINDOWS=0
}

QT       += core gui  network widgets
# concurrent
TARGET = xuolauncher
TEMPLATE = app

CONFIG += c++17

# Include common updater module
include($$PWD/../common/updater/updater.pri)

SOURCES += $$PWD/main.cpp\
        $$PWD/launcherwindow.cpp \
        $$PWD/serverlistitem.cpp \
        $$PWD/proxylistitem.cpp \
        $$PWD/changelogform.cpp

HEADERS  += $$PWD/launcherwindow.h \
        $$PWD/serverlistitem.h \
        $$PWD/proxylistitem.h \
        $$PWD/changelogform.h

FORMS    += $$PWD/launcherwindow.ui \
    $$PWD/changelogform.ui

OTHER_FILES += $$PWD/launcher.rc

RC_FILE = $$PWD/launcher.rc

RESOURCES += \
    $$PWD/../common/resources/res.qrc

INCLUDEPATH += $$PWD/../common

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
TARGET = xuomanager
TEMPLATE = app

CONFIG += c++17

include($$PWD/../common/updater/updater.pri)

SOURCES += $$PWD/manager.cpp\
        $$PWD/managerwindow.cpp

HEADERS  += $$PWD/managerwindow.h

FORMS    += $$PWD/managerwindow.ui

# RC_FILE seems to point to launcher.rc in the original file, which is weird for manager.
# But let's keep it if it shares the icon, but launcher.rc is in launcher folder.
# I will comment it out or point to the one in launcher if needed, but for now let's assume it was copy paste or shared.
# Given it was in root, and now launcher.rc is in src/launcher/launcher.rc.
# I'll try to use it from there if it exists.
# But manager probably needs its own RC or none.
# The original file had `OTHER_FILES += launcher.rc` and `RC_FILE = launcher.rc`.
# Since I moved launcher.rc to src/launcher, I should probably point to it there or copy it?
# Let's point to it.

RC_FILE = $$PWD/../launcher/launcher.rc

RESOURCES += \
    $$PWD/../common/resources/res.qrc

INCLUDEPATH += $$PWD/../common

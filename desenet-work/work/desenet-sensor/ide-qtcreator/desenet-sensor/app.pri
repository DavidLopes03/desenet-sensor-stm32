PRI_PATH = $$PWD

SENSOR_SRC_PATH = "$${PRI_PATH}/../../src"
APP_SRC_PATH = "$${SENSOR_SRC_PATH}/app"

INCLUDEPATH += \
    "$${SENSOR_SRC_PATH}"

HEADERS += \
    $${APP_SRC_PATH}/accelerometerapplication.h \
    $${APP_SRC_PATH}/factory.h
    $${APP_SRC_PATH}/joystickapplication.h

SOURCES += \
    $${APP_SRC_PATH}/accelerometerapplication.cpp \
    $${APP_SRC_PATH}/factory.cpp
    $${APP_SRC_PATH}/joystickapplication.cpp

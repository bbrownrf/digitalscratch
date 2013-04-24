######################################################################
# Automatically generated by qmake (2.01a) Sun May 24 19:31:29 2009
######################################################################

VERSION = 1.2.0
DEFINES += VERSION=$${VERSION}

##############################
# Paths
unix {
    BIN_PATH = $${PREFIX}/bin
}
win32 {
    BIN_PATH = .
}

# Installation paths and files.
target.path = $${BIN_PATH}
INSTALLS += target
##############################

TEMPLATE = app
QT += sql
CONFIG(test) {
    QT       += testlib
    TARGET    = digitalscratch-test
    CONFIG   += console
    CONFIG   -= app_bundle
}
else {
    TARGET = digitalscratch
}
DEPENDPATH += . src include/gui include/player src/gui src/player
INCLUDEPATH += . include/player include/gui include


# Input
HEADERS += include/gui/config_dialog.h \
           include/gui/gui.h \
           include/gui/waveform.h \
           include/gui/vertical_waveform.h \
           include/gui/remaining_time.h \
           include/gui/application_settings.h \
           include/player/audio_file_decoding_process.h \
           include/player/audio_track.h \
           include/player/audio_track_playback_process.h \
           include/player/sound_card_access_rules.h \
           include/player/timecode_analyzis_process.h \
           include/player/playback_parameters.h \
           include/player/sound_capture_and_playback_process.h \
           include/player/data_persistence.h \
           include/utils.h \
           include/application_const.h \
           include/singleton.h
           
SOURCES += src/main.cpp \
           src/gui/config_dialog.cpp \
           src/gui/gui.cpp \
           src/gui/waveform.cpp \
           src/gui/vertical_waveform.cpp \
           src/gui/remaining_time.cpp \
           src/gui/application_settings.cpp \
           src/player/audio_file_decoding_process.cpp \
           src/player/audio_track.cpp \
           src/player/audio_track_playback_process.cpp \
           src/player/sound_card_access_rules.cpp \
           src/player/timecode_analyzis_process.cpp \
           src/player/playback_parameters.cpp \
           src/player/sound_capture_and_playback_process.cpp \
           src/player/data_persistence.cpp \
           src/utils.cpp

CONFIG(test) {
    INCLUDEPATH += test

    SOURCES -= src/main.cpp

    HEADERS += test/audio_track_test.h \
               test/audio_file_decoding_process_test.h \
               test/utils_test.h \
               test/data_persistence_test.h \

    SOURCES += test/main_test.cpp \
               test/audio_track_test.cpp \
               test/audio_file_decoding_process_test.cpp \
               test/utils_test.cpp \
               test/data_persistence_test.cpp
}


#############################
# External libraries for audio decoding
win32 {
    LIBS += -L$$PWD/win-external/mpg123/lib/ -llibmpg123
    INCLUDEPATH += $$PWD/win-external/mpg123/include
    DEPENDPATH += $$PWD/win-external/mpg123/include
}
unix {
    LIBS += -lmpg123
}
win32 {
    LIBS += -L$$PWD/win-external/flac-1.2.1-devel-win/lib/ -llibFLAC
    INCLUDEPATH += $$PWD/win-external/flac-1.2.1-devel-win/include
    DEPENDPATH += $$PWD/win-external/flac-1.2.1-devel-win/include
}
unix {
    LIBS += -lFLAC
}
#############################

#############################
# DigitalScratch library
win32 {
    LIBS += -L$$PWD/win-external/libdigitalscratch/lib/ -ldigitalscratch1
    INCLUDEPATH += $$PWD/win-external/libdigitalscratch/include
    DEPENDPATH += $$PWD/win-external/libdigitalscratch/include
}
unix {
    LIBS += -ldigitalscratch
}
#############################

#############################
# Lib sample rate
win32 {
    LIBS += -L$$PWD/win-external/samplerate-0.1.8/lib/ -llibsamplerate-0
    INCLUDEPATH += $$PWD/win-external/samplerate-0.1.8/include
    DEPENDPATH += $$PWD/win-external/samplerate-0.1.8/include
}
unix {
    LIBS += -lsamplerate
}
#############################

#############################
# Jack lib
DEFINES += USE_JACK
win32 {
    LIBS += -L$$PWD/win-external/jack-1.9.9/lib/ -llibjack
    INCLUDEPATH += $$PWD/win-external/jack-1.9.9/includes
    DEPENDPATH += $$PWD/win-external/jack-1.9.9/includes
}
unix {
    LIBS += -ljack -lpthread -lrt
}
#############################

#############################
# Enable for release and debug mode.
CONFIG += debug_and_release
DEFINES += QT_NO_DEBUG_OUTPUT QT_NO_WARNING_OUTPUT
CONFIG(debug, debug|release) {
}
else {
    DEFINES += QT_NO_DEBUG_OUTPUT QT_NO_WARNING_OUTPUT
}
#############################

#############################
# Enable multi-threading support for QT
CONFIG += qt thread
#############################

############################
# Icon for Windows build
############################
win32:RC_FILE = digitalscratch_resource.rc

############################
# Copy necessary files to run on windows
win32 {
    DLLS = \
        $${PWD}/win-external/mpg123/lib/libmpg123.dll \
        $${PWD}/win-external/flac-1.2.1-devel-win/lib/libFLAC.dll \
        $${PWD}/win-external/libdigitalscratch/lib/digitalscratch1.dll \
        $${PWD}/win-external/samplerate-0.1.8/lib/libsamplerate-0.dll \
        $${PWD}/win-external/jack-1.9.9/lib/libjack.dll
    DESTDIR_WIN = $${DESTDIR}
    CONFIG(debug, debug|release) {
        DESTDIR_WIN += debug
        DLLS += %QTDIR%/bin/QtCored4.dll \
                %QTDIR%/bin/QtGuid4.dll \
                %QTDIR%/bin/QtSqld4.dll
        CONFIG(test) {
           DLLS += %QTDIR%/bin/QtTestd4.dll
        }
    } else {
        DESTDIR_WIN += release
        DLLS += %QTDIR%/bin/QtCore4.dll \
                %QTDIR%/bin/QtGui4.dll \
                %QTDIR%/bin/QtSql4.dll
        CONFIG(test) {
           DLLS += %QTDIR%/bin/QtTest4.dll
        }
    }
    DLLS ~= s,/,\\,g
    DESTDIR_WIN ~= s,/,\\,g
    for(FILE, DLLS){
        QMAKE_POST_LINK += $${QMAKE_COPY} $$quote($${FILE}) $$quote($${DESTDIR_WIN}) $$escape_expand(\\n\\t)
    }
}
############################

OTHER_FILES += \
    TODO \
    README \
    NEWS \
    INSTALL \
    COPYING \
    AUTHORS \
    debian/changelog \
    debian/rules \
    debian/README \
    debian/generate_digitalscratch_deb.sh \
    debian/docs \
    debian/digitalscratch.desktop \
    debian/copyright \
    debian/control \
    debian/compat

RESOURCES += \
    digitalscratch.qrc

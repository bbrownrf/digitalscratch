#include <QtTest>
#include "playlist_persistence_test.h"
#include "playlist_persistence.h"
#include <iostream>

#define DATA_DIR          "./test/data/"
#ifdef WIN32
    #define URI_PREFIX    "file:///"
#else
    #define URI_PREFIX    "file://"
#endif
#define PLAYLIST_M3U_FILE "playlist.m3u"
#define PLAYLIST_M3U      "#EXTM3U\n"\
                          "#EXTINF:2316,\n"\
                          "# full path\n"\
                          "<DATA_DIR>/track_1.mp3\n"\
                          "#EXTINF:2316, -\n"\
                          "# relative path\n"\
                          "track_2.mp3\n"\
                          "#EXTINF:2316, -\n"\
                          "# duplicate path\n"\
                          "track_2.mp3\n"\
                          "#EXTINF:2316, -\n"\
                          "# file does not exists\n"\
                          "<URI_PREFIX><DATA_DIR>/track_does_not_exists.mp3\n"\
                          "#EXTINF:2316, -\n"\
                          "# uri style path\n"\
                          "<URI_PREFIX><DATA_DIR>/track_%C3%A9%C3%A8%C3%A0%40%C3%B9%26_3.mp3\n"\
                          "#EXTINF:2316, -\n"\
                          "# special chars\n"\
                          "track_éèà@ù&_4.mp3"

Playlist_persistence_Test::Playlist_persistence_Test()
{

}

void Playlist_persistence_Test::initTestCase()
{
    // Init playlist and persistence process.
    this->playlist         = new Playlist("base_path", "playlist");
    this->playlist_persist = new Playlist_persistence();

    // Create a test playlist file.
    QString m3u(PLAYLIST_M3U);
    m3u.replace("<DATA_DIR>",   QDir(DATA_DIR).absolutePath());
    m3u.replace("<URI_PREFIX>", URI_PREFIX);
    QFile m3u_file(QDir(DATA_DIR).filePath(PLAYLIST_M3U_FILE));
    if (m3u_file.open(QIODevice::WriteOnly | QIODevice::Text) == true)
    {
         QTextStream m3u_stream(&m3u_file);
         m3u_stream << m3u.toUtf8();
         m3u_file.close();
    }
}

void Playlist_persistence_Test::cleanupTestCase()
{
    // Cleanup.
    delete this->playlist;
    delete this->playlist_persist;
}

void Playlist_persistence_Test::testCaseReadM3u()
{
    // Read playlist.
    QString playlist_fullfilename = QDir(DATA_DIR).filePath(PLAYLIST_M3U_FILE);
    QVERIFY2(this->playlist_persist->read_m3u(playlist_fullfilename, this->playlist) == true, "Read M3U");

    // Check tracklist.
    QStringList tracklist = this->playlist->get_tracklist();
    QVERIFY2(tracklist.count() == 4, "number of tracks");
    QVERIFY2(tracklist[0]      == QDir(DATA_DIR).absoluteFilePath("track_1.mp3"),        "name of track 1");
    QVERIFY2(tracklist[1]      == QDir(DATA_DIR).absoluteFilePath("track_2.mp3"),        "name of track 2");
    QVERIFY2(tracklist[2]      == QDir(DATA_DIR).absoluteFilePath("track_éèà@ù&_3.mp3"), "name of track 3");
    QVERIFY2(tracklist[3]      == QDir(DATA_DIR).absoluteFilePath("track_éèà@ù&_4.mp3"), "name of track 4");
}

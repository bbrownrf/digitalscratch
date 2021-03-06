/*============================================================================*/
/*                                                                            */
/*                                                                            */
/*                           Digital Scratch Player                           */
/*                                                                            */
/*                                                                            */
/*-----------------------------------------------( playlist_persistence.cpp )-*/
/*                                                                            */
/*  Copyright (C) 2003-2013                                                   */
/*                Julien Rosener <julien.rosener@digital-scratch.org>         */
/*                                                                            */
/*----------------------------------------------------------------( License )-*/
/*                                                                            */
/*  This program is free software: you can redistribute it and/or modify      */
/*  it under the terms of the GNU General Public License as published by      */
/*  the Free Software Foundation, either version 3 of the License, or         */
/*  (at your option) any later version.                                       */
/*                                                                            */
/*  This package is distributed in the hope that it will be useful,           */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             */
/*  GNU General Public License for more details.                              */
/*                                                                            */
/*  You should have received a copy of the GNU General Public License         */
/*  along with this program. If not, see <http://www.gnu.org/licenses/>.      */
/*                                                                            */
/*------------------------------------------------------------( Description )-*/
/*                                                                            */
/*         File persistence methods for a Playlist (m3u, pls,...)             */
/*                                                                            */
/*============================================================================*/


#include <iostream>
#include <QtDebug>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QTextCodec>
#include <QUrl>
#include <QDesktopServices>
#include "playlist_persistence.h"

Playlist_persistence::Playlist_persistence()
{
    qDebug() << "Playlist_persistence::Playlist_persistence: create object...";

    qDebug() << "Playlist_persistence::Playlist_persistence: create object done";

    return;
}


Playlist_persistence::~Playlist_persistence()
{
    qDebug() << "Playlist_persistence::~Playlist_persistence: delete object...";

    qDebug() << "Playlist_persistence::~Playlist_persistence: delete object done.";

    return;
}

bool Playlist_persistence::read_m3u(QString in_file_name, Playlist *&io_playlist)
{
    qDebug() << "Playlist_persistence::read_m3u...";

    // Check parameters.
    if (io_playlist == NULL)
    {
        return false;
    }
    if (QFile::exists(in_file_name) == false)
    {
        return false;
    }

    // Get path of playlist file.
    QFileInfo file_info(in_file_name);
    QString   path(file_info.absolutePath());

    // Populate list of audio track.
    QFile file(in_file_name);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text) == true)
    {
        // Set current path to the one from the playlist file. Needed for relative track file path.
        QString old_path = QDir::currentPath();
        QDir::setCurrent(path);

        // Iterate over lines in playlist file.
        QTextStream stream(&file);
        while (stream.atEnd() == false)
        {
            // Get line.
            QString line = stream.readLine();

            // Skip comment lines.
            if (line.startsWith("#") == false)
            {
                // Check if file exists.
                QFileInfo line_info(line);
                if (line_info.exists() == true)
                {
                    // Add track path to playlist object.
                    io_playlist->add_track(line_info.absoluteFilePath());
                }
                else
                {
                    // File does not exist, maybe because path is a URI.
                    line = QUrl::fromUserInput(line).toLocalFile();
                    if (line.length() > 0)
                    {
                        // Try to check again if it exists.
                        QFileInfo uri_info(line);
                        if (uri_info.exists() == true)
                        {
                            // Add track path to playlist object.
                            io_playlist->add_track(uri_info.absoluteFilePath());
                        }
                    }
                }
            }
        }

        // Put back the current path;
        QDir::setCurrent(old_path);
    }
    file.close();

    qDebug() << "Playlist_persistence::read_m3u done.";

    return true;
}

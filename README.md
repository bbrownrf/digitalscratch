Digital-Scratch
--------------

### A vinyl turntable emulation software for DJ

[Digital-Scratch](http://www.digital-scratch.org/ "Digital-scratch") is a free software for DJs. It analyzes motions (rotation speed and direction) of a vinyl disc played by a turntable. It also provide a nice and simple player that plays digital tracks allowing you to mix as you would do it with regular records.  

__In other words__: with Digital-Scratch you can mix your digital file collection with regular vinyl turntables.

* More informations at [http://www.digital-scratch.org](http://www.digital-scratch.org).
* Mailing list: digitalscratch@googlegroups.com (to subscribe, send a mail to digitalscratch+subscribe@googlegroups.com)

### Requirements

* 1 or 2 timecoded vinyl disc, ([Serato Scratch Live](http://serato.com/scratchlive), [Final Scratch](http://en.wikipedia.org/wiki/Final_Scratch),...)
* 1 or 2 vinyl turntables and a mixer
* A GNU/Linux or MS Windows computer
* A sound card driven by [JACK](http://jackaudio.org/) providing 1 or 2 stereo inputs

### Software architecture

The core motion detection is done by an SDK built as a shared library: _libdigitalscratch_. It can be integrated with various kind of controllable software player.

Digital-Scratch also provides a player which uses the library: _digitalscratch_. This player is able to play one or two tracks. The playback parameters (speed and direction) could be changed in real time. It also provides a simplistic file explorer used to select tracks to play.

### Software dependencies

_libdigitalscratch_ (motion detection) is based on:
* [Qt 5.x](http://qt-project.org)

_digitalscratch_ (audio player) is based on:
* [Qt 5.x](http://qt-project.org)
* [mpg123](http://www.mpg123.de/)
* [FLAC](http://flac.sourceforge.net/)
* [Sample rate library](http://www.mega-nerd.com/SRC/)
* [JACK](http://jackaudio.org/)
* [LibKeyFinder](http://www.ibrahimshaath.co.uk/keyfinder/)

Install
--------------

### Ubuntu
    sudo add-apt-repository ppa:julien-rosener/digitalscratch
    sudo apt-get update
    sudo apt-get install digitalscratch

### MS Windows
See the download page: [http://www.digital-scratch.org/download.html](http://www.digital-scratch.org/download.html)

Build
--------------

### Ubuntu 13.04 (raring)

#### Install build tools
    sudo apt-add-repository ppa:julien-rosener/digitalscratch
    sudo apt-get update
    sudo apt-get install build-essential qt5-default libmpg123-dev libjack-jackd2-dev libsamplerate0-dev libflac-dev libkeyfinder-dev

#### Compile and install _libdigitalscratch_
    cd libdigitalscratch
    qmake
    make
    sudo make install

#### Compile and install _digitalscratch_ player
    cd ../digitalscratch
    qmake
    make
    sudo make install
    
### MS Windows

#### Install build environment
* Install the [Microsoft Windows SDK 7.1](http://www.microsoft.com/en-us/download/details.aspx?id=8279)
* Install [Qt 5.x for Windows 32-bit (VS 2010, OpenGL), including QtCreator](http://qt-project.org/downloads)
    
#### Compile _libdigitalscratch_ and _digitalscratch_ player
* Start Qt Creator
* Load project `libdigitalscratch.pro` and `digitalscratch.pro`
* For each projects, use a build kit with Windows SDK 7.1 as compiler and click on "Configure project"
* Then in "Project >> Build" section uncheck "Shadow build" for debug and release.
* Right click on project libdigitalscratch and digitalscratch, then "Run qmake", then "build"

License
--------------

Digital-Scratch player and library are released under [GNU GPL](http://www.gnu.org/copyleft/gpl.html) license.

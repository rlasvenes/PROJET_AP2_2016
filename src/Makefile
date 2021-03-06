#############################################################################
# Makefile for building: Runner
# Generated by qmake (2.01a) (Qt 4.8.6) on: Fri May 13 15:47:56 2016
# Project:  Runner.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -spec /usr/share/qt4/mkspecs/linux-g++-64 CONFIG+=debug -after  SOURCES-=TU.cc -o Makefile Runner.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT
CFLAGS        = -m64 -pipe -g -Wall -W $(DEFINES)
CXXFLAGS      = -m64 -pipe -std=c++11 -Wall -Wextra -g -Wall -W $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I.
LINK          = g++
LFLAGS        = -m64
LIBS          = $(SUBLIBS)   -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -lboost_unit_test_framework 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		View.cpp \
		Model.cpp \
		Ball.cpp \
		GraphicElement.cpp \
		TcpClient.cpp \
		MovableElement.cpp \
		Menu.cpp \
		SlidingBackground.cpp \
		Color.cpp \
		LogFile.cpp \
		XOR_EncryptDecryption.cpp 
OBJECTS       = main.o \
		View.o \
		Model.o \
		Ball.o \
		GraphicElement.o \
		TcpClient.o \
		MovableElement.o \
		Menu.o \
		SlidingBackground.o \
		Color.o \
		LogFile.o \
		XOR_EncryptDecryption.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		deployment.pri \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Runner.pro
QMAKE_TARGET  = Runner
DESTDIR       = 
TARGET        = Runner

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9][^0-9]*\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: Runner.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		deployment.pri \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++-64 CONFIG+=debug -after  SOURCES-=TU.cc -o Makefile Runner.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
deployment.pri:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++-64 CONFIG+=debug -after  SOURCES-=TU.cc -o Makefile Runner.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Runner1.0.0 || $(MKDIR) .tmp/Runner1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Runner1.0.0/ && (cd `dirname .tmp/Runner1.0.0` && $(TAR) Runner1.0.0.tar Runner1.0.0 && $(COMPRESS) Runner1.0.0.tar) && $(MOVE) `dirname .tmp/Runner1.0.0`/Runner1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Runner1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: main.cpp View.h \
		Ball.h \
		MovableElement.h \
		Model.h \
		GraphicElement.h \
		SlidingBackground.h \
		TcpClient.h \
		Menu.h \
		Audio.h \
		LogFile.h \
		XOR_EncryptDecryption.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

View.o: View.cpp View.h \
		Ball.h \
		MovableElement.h \
		Model.h \
		GraphicElement.h \
		SlidingBackground.h \
		TcpClient.h \
		Menu.h \
		Audio.h \
		LogFile.h \
		XOR_EncryptDecryption.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o View.o View.cpp

Model.o: Model.cpp Model.h \
		View.h \
		Ball.h \
		MovableElement.h \
		GraphicElement.h \
		SlidingBackground.h \
		TcpClient.h \
		Menu.h \
		Audio.h \
		LogFile.h \
		XOR_EncryptDecryption.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Model.o Model.cpp

Ball.o: Ball.cpp Ball.h \
		View.h \
		Model.h \
		GraphicElement.h \
		SlidingBackground.h \
		TcpClient.h \
		Menu.h \
		Audio.h \
		LogFile.h \
		XOR_EncryptDecryption.h \
		MovableElement.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Ball.o Ball.cpp

GraphicElement.o: GraphicElement.cpp GraphicElement.h \
		View.h \
		Ball.h \
		MovableElement.h \
		Model.h \
		SlidingBackground.h \
		TcpClient.h \
		Menu.h \
		Audio.h \
		LogFile.h \
		XOR_EncryptDecryption.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GraphicElement.o GraphicElement.cpp

TcpClient.o: TcpClient.cpp TcpClient.h \
		View.h \
		Ball.h \
		MovableElement.h \
		Model.h \
		GraphicElement.h \
		SlidingBackground.h \
		Menu.h \
		Audio.h \
		LogFile.h \
		XOR_EncryptDecryption.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TcpClient.o TcpClient.cpp

MovableElement.o: MovableElement.cpp MovableElement.h \
		View.h \
		Ball.h \
		Model.h \
		GraphicElement.h \
		SlidingBackground.h \
		TcpClient.h \
		Menu.h \
		Audio.h \
		LogFile.h \
		XOR_EncryptDecryption.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MovableElement.o MovableElement.cpp

Menu.o: Menu.cpp Menu.h \
		View.h \
		Ball.h \
		MovableElement.h \
		Model.h \
		GraphicElement.h \
		SlidingBackground.h \
		TcpClient.h \
		Audio.h \
		LogFile.h \
		XOR_EncryptDecryption.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Menu.o Menu.cpp

SlidingBackground.o: SlidingBackground.cpp SlidingBackground.h \
		View.h \
		Ball.h \
		MovableElement.h \
		Model.h \
		GraphicElement.h \
		TcpClient.h \
		Menu.h \
		Audio.h \
		LogFile.h \
		XOR_EncryptDecryption.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o SlidingBackground.o SlidingBackground.cpp

Color.o: Color.cpp Color.h \
		View.h \
		Ball.h \
		MovableElement.h \
		Model.h \
		GraphicElement.h \
		SlidingBackground.h \
		TcpClient.h \
		Menu.h \
		Audio.h \
		LogFile.h \
		XOR_EncryptDecryption.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Color.o Color.cpp

LogFile.o: LogFile.cpp LogFile.h \
		View.h \
		Ball.h \
		MovableElement.h \
		Model.h \
		GraphicElement.h \
		SlidingBackground.h \
		TcpClient.h \
		Menu.h \
		Audio.h \
		XOR_EncryptDecryption.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o LogFile.o LogFile.cpp

XOR_EncryptDecryption.o: XOR_EncryptDecryption.cpp XOR_EncryptDecryption.h \
		View.h \
		Ball.h \
		MovableElement.h \
		Model.h \
		GraphicElement.h \
		SlidingBackground.h \
		TcpClient.h \
		Menu.h \
		Audio.h \
		LogFile.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o XOR_EncryptDecryption.o XOR_EncryptDecryption.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/opt/Runner/bin/ || $(MKDIR) $(INSTALL_ROOT)/opt/Runner/bin/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(INSTALL_ROOT)/opt/Runner/bin/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/opt/Runner/bin/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/opt/Runner/bin/ 


install:  install_target  FORCE

uninstall: uninstall_target   FORCE

FORCE:


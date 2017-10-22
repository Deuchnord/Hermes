#############################################################################
# Makefile for building: deuchnord-hermes
# Generated by qmake (3.1) (Qt 5.9.2)
# Project:  deuchnord-hermes.pro
# Template: app
# Command: /usr/sbin/qmake -o Makefile deuchnord-hermes.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -march=x86-64 -mtune=generic -O2 -pipe -fstack-protector-strong -fno-plt -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -march=x86-64 -mtune=generic -O2 -pipe -fstack-protector-strong -fno-plt -std=gnu++11 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -isystem /usr/include/qt -isystem /usr/include/qt/QtWidgets -isystem /usr/include/qt/QtGui -isystem /usr/include/qt/QtXml -isystem /usr/include/qt/QtNetwork -isystem /usr/include/qt/QtCore -I. -isystem /usr/include/libdrm -I. -I/usr/lib/qt/mkspecs/linux-g++
QMAKE         = /usr/sbin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/sbin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/sbin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = deuchnord-hermes1.0.0
DISTDIR = /home/jerome/CloudStation/Hermes\ 0.7/hermes/.tmp/deuchnord-hermes1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-O1,--sort-common,--as-needed,-z,relro,-z,now
LIBS          = $(SUBLIBS) -lQt5Widgets -lQt5Gui -lQt5Xml -lQt5Network -lQt5Core -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		produititem.cpp \
		infosproduitdialog.cpp \
		aboutdialog.cpp \
		scannerdialog.cpp \
		settingsdialog.cpp \
		manufacturersmanager.cpp qrc_resources.cpp \
		moc_mainwindow.cpp \
		moc_produititem.cpp \
		moc_infosproduitdialog.cpp \
		moc_aboutdialog.cpp \
		moc_scannerdialog.cpp \
		moc_settingsdialog.cpp
OBJECTS       = main.o \
		mainwindow.o \
		produititem.o \
		infosproduitdialog.o \
		aboutdialog.o \
		scannerdialog.o \
		settingsdialog.o \
		manufacturersmanager.o \
		qrc_resources.o \
		moc_mainwindow.o \
		moc_produititem.o \
		moc_infosproduitdialog.o \
		moc_aboutdialog.o \
		moc_scannerdialog.o \
		moc_settingsdialog.o
DIST          = /usr/lib/qt/mkspecs/features/spec_pre.prf \
		/usr/lib/qt/mkspecs/common/unix.conf \
		/usr/lib/qt/mkspecs/common/linux.conf \
		/usr/lib/qt/mkspecs/common/sanitize.conf \
		/usr/lib/qt/mkspecs/common/gcc-base.conf \
		/usr/lib/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/qt/mkspecs/common/g++-base.conf \
		/usr/lib/qt/mkspecs/common/g++-unix.conf \
		/usr/lib/qt/mkspecs/qconfig.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designer.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designer_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_help.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_help_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_location.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_location_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimedia_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_positioning.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_positioning_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickcontrols2.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_script.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_script_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_scripttools.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_scripttools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sensors.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sensors_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_svg.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_svg_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uiplugin.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uitools.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uitools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webchannel.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webchannel_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webengine.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webengine_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webenginecore.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webenginecore_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webenginecoreheaders_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webenginewidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkit.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_x11extras.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_x11extras_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		/usr/lib/qt/mkspecs/features/qt_functions.prf \
		/usr/lib/qt/mkspecs/features/qt_config.prf \
		/usr/lib/qt/mkspecs/linux-g++/qmake.conf \
		/usr/lib/qt/mkspecs/features/spec_post.prf \
		/usr/lib/qt/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt/mkspecs/features/toolchain.prf \
		/usr/lib/qt/mkspecs/features/default_pre.prf \
		/usr/lib/qt/mkspecs/features/resolve_config.prf \
		/usr/lib/qt/mkspecs/features/default_post.prf \
		/usr/lib/qt/mkspecs/features/warn_on.prf \
		/usr/lib/qt/mkspecs/features/qt.prf \
		/usr/lib/qt/mkspecs/features/resources.prf \
		/usr/lib/qt/mkspecs/features/moc.prf \
		/usr/lib/qt/mkspecs/features/unix/opengl.prf \
		/usr/lib/qt/mkspecs/features/uic.prf \
		/usr/lib/qt/mkspecs/features/unix/thread.prf \
		/usr/lib/qt/mkspecs/features/qmake_use.prf \
		/usr/lib/qt/mkspecs/features/file_copies.prf \
		/usr/lib/qt/mkspecs/features/testcase_targets.prf \
		/usr/lib/qt/mkspecs/features/exceptions.prf \
		/usr/lib/qt/mkspecs/features/yacc.prf \
		/usr/lib/qt/mkspecs/features/lex.prf \
		deuchnord-hermes.pro mainwindow.h \
		produititem.h \
		infosproduitdialog.h \
		aboutdialog.h \
		scannerdialog.h \
		settingsdialog.h \
		manufacturersmanager.h main.cpp \
		mainwindow.cpp \
		produititem.cpp \
		infosproduitdialog.cpp \
		aboutdialog.cpp \
		scannerdialog.cpp \
		settingsdialog.cpp \
		manufacturersmanager.cpp
QMAKE_TARGET  = deuchnord-hermes
DESTDIR       = 
TARGET        = deuchnord-hermes


first: all
####### Build rules

$(TARGET): ui_mainwindow.h ui_produititem.h ui_infosproduitdialog.h ui_aboutdialog.h ui_scannerdialog.h ui_settingsdialog.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: deuchnord-hermes.pro /usr/lib/qt/mkspecs/linux-g++/qmake.conf /usr/lib/qt/mkspecs/features/spec_pre.prf \
		/usr/lib/qt/mkspecs/common/unix.conf \
		/usr/lib/qt/mkspecs/common/linux.conf \
		/usr/lib/qt/mkspecs/common/sanitize.conf \
		/usr/lib/qt/mkspecs/common/gcc-base.conf \
		/usr/lib/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/qt/mkspecs/common/g++-base.conf \
		/usr/lib/qt/mkspecs/common/g++-unix.conf \
		/usr/lib/qt/mkspecs/qconfig.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designer.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designer_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_help.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_help_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_location.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_location_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimedia_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_positioning.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_positioning_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickcontrols2.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_script.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_script_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_scripttools.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_scripttools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sensors.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sensors_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_svg.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_svg_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uiplugin.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uitools.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uitools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webchannel.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webchannel_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webengine.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webengine_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webenginecore.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webenginecore_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webenginecoreheaders_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webenginewidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkit.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_x11extras.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_x11extras_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		/usr/lib/qt/mkspecs/features/qt_functions.prf \
		/usr/lib/qt/mkspecs/features/qt_config.prf \
		/usr/lib/qt/mkspecs/linux-g++/qmake.conf \
		/usr/lib/qt/mkspecs/features/spec_post.prf \
		/usr/lib/qt/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt/mkspecs/features/toolchain.prf \
		/usr/lib/qt/mkspecs/features/default_pre.prf \
		/usr/lib/qt/mkspecs/features/resolve_config.prf \
		/usr/lib/qt/mkspecs/features/default_post.prf \
		/usr/lib/qt/mkspecs/features/warn_on.prf \
		/usr/lib/qt/mkspecs/features/qt.prf \
		/usr/lib/qt/mkspecs/features/resources.prf \
		/usr/lib/qt/mkspecs/features/moc.prf \
		/usr/lib/qt/mkspecs/features/unix/opengl.prf \
		/usr/lib/qt/mkspecs/features/uic.prf \
		/usr/lib/qt/mkspecs/features/unix/thread.prf \
		/usr/lib/qt/mkspecs/features/qmake_use.prf \
		/usr/lib/qt/mkspecs/features/file_copies.prf \
		/usr/lib/qt/mkspecs/features/testcase_targets.prf \
		/usr/lib/qt/mkspecs/features/exceptions.prf \
		/usr/lib/qt/mkspecs/features/yacc.prf \
		/usr/lib/qt/mkspecs/features/lex.prf \
		deuchnord-hermes.pro \
		resources.qrc \
		/usr/lib/libQt5Widgets.prl \
		/usr/lib/libQt5Gui.prl \
		/usr/lib/libQt5Xml.prl \
		/usr/lib/libQt5Network.prl \
		/usr/lib/libQt5Core.prl
	$(QMAKE) -o Makefile deuchnord-hermes.pro
/usr/lib/qt/mkspecs/features/spec_pre.prf:
/usr/lib/qt/mkspecs/common/unix.conf:
/usr/lib/qt/mkspecs/common/linux.conf:
/usr/lib/qt/mkspecs/common/sanitize.conf:
/usr/lib/qt/mkspecs/common/gcc-base.conf:
/usr/lib/qt/mkspecs/common/gcc-base-unix.conf:
/usr/lib/qt/mkspecs/common/g++-base.conf:
/usr/lib/qt/mkspecs/common/g++-unix.conf:
/usr/lib/qt/mkspecs/qconfig.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_core.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_designer.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_designer_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_designercomponents_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_help.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_help_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_location.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_location_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_multimedia.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_multimedia_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_network.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_packetprotocol_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_positioning.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_positioning_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qml.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qml_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qmldebug_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qmldevtools_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qmltest.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qmltest_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quick.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quick_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quickcontrols2.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quickparticles_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_script.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_script_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_scripttools.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_scripttools_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_sensors.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_sensors_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_svg.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_svg_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_uiplugin.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_uitools.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_uitools_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webchannel.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webchannel_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webengine.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webengine_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webenginecore.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webenginecore_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webenginecoreheaders_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webenginewidgets.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webenginewidgets_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webkit.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_x11extras.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_x11extras_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
/usr/lib/qt/mkspecs/features/qt_functions.prf:
/usr/lib/qt/mkspecs/features/qt_config.prf:
/usr/lib/qt/mkspecs/linux-g++/qmake.conf:
/usr/lib/qt/mkspecs/features/spec_post.prf:
/usr/lib/qt/mkspecs/features/exclusive_builds.prf:
/usr/lib/qt/mkspecs/features/toolchain.prf:
/usr/lib/qt/mkspecs/features/default_pre.prf:
/usr/lib/qt/mkspecs/features/resolve_config.prf:
/usr/lib/qt/mkspecs/features/default_post.prf:
/usr/lib/qt/mkspecs/features/warn_on.prf:
/usr/lib/qt/mkspecs/features/qt.prf:
/usr/lib/qt/mkspecs/features/resources.prf:
/usr/lib/qt/mkspecs/features/moc.prf:
/usr/lib/qt/mkspecs/features/unix/opengl.prf:
/usr/lib/qt/mkspecs/features/uic.prf:
/usr/lib/qt/mkspecs/features/unix/thread.prf:
/usr/lib/qt/mkspecs/features/qmake_use.prf:
/usr/lib/qt/mkspecs/features/file_copies.prf:
/usr/lib/qt/mkspecs/features/testcase_targets.prf:
/usr/lib/qt/mkspecs/features/exceptions.prf:
/usr/lib/qt/mkspecs/features/yacc.prf:
/usr/lib/qt/mkspecs/features/lex.prf:
deuchnord-hermes.pro:
resources.qrc:
/usr/lib/libQt5Widgets.prl:
/usr/lib/libQt5Gui.prl:
/usr/lib/libQt5Xml.prl:
/usr/lib/libQt5Network.prl:
/usr/lib/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile deuchnord-hermes.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents resources.qrc $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib/qt/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents mainwindow.h produititem.h infosproduitdialog.h aboutdialog.h scannerdialog.h settingsdialog.h manufacturersmanager.h $(DISTDIR)/
	$(COPY_FILE) --parents main.cpp mainwindow.cpp produititem.cpp infosproduitdialog.cpp aboutdialog.cpp scannerdialog.cpp settingsdialog.cpp manufacturersmanager.cpp $(DISTDIR)/
	$(COPY_FILE) --parents mainwindow.ui produititem.ui infosproduitdialog.ui aboutdialog.ui scannerdialog.ui settingsdialog.ui $(DISTDIR)/
	$(COPY_FILE) --parents strings.ts $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all: qrc_resources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_resources.cpp
qrc_resources.cpp: resources.qrc \
		/usr/bin/rcc \
		icon-hermes.png \
		no-picture.jpg \
		scanner.png \
		add.png \
		remove.png \
		icon-search.png
	/usr/bin/rcc -name resources resources.qrc -o qrc_resources.cpp

compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /usr/lib/qt/mkspecs/features/data/dummy.cpp
	g++ -pipe -O2 -march=x86-64 -mtune=generic -O2 -pipe -fstack-protector-strong -fno-plt -std=gnu++11 -Wall -W -dM -E -o moc_predefs.h /usr/lib/qt/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_mainwindow.cpp moc_produititem.cpp moc_infosproduitdialog.cpp moc_aboutdialog.cpp moc_scannerdialog.cpp moc_settingsdialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_produititem.cpp moc_infosproduitdialog.cpp moc_aboutdialog.cpp moc_scannerdialog.cpp moc_settingsdialog.cpp
moc_mainwindow.cpp: produititem.h \
		infosproduitdialog.h \
		scannerdialog.h \
		mainwindow.h \
		moc_predefs.h \
		/usr/bin/moc
	/usr/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/qt/mkspecs/linux-g++ -I'/home/jerome/CloudStation/Hermes 0.7/hermes' -I/usr/include/qt -I/usr/include/qt/QtWidgets -I/usr/include/qt/QtGui -I/usr/include/qt/QtXml -I/usr/include/qt/QtNetwork -I/usr/include/qt/QtCore -I/usr/include/c++/7.2.0 -I/usr/include/c++/7.2.0/x86_64-pc-linux-gnu -I/usr/include/c++/7.2.0/backward -I/usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include -I/usr/local/include -I/usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include-fixed -I/usr/include mainwindow.h -o moc_mainwindow.cpp

moc_produititem.cpp: infosproduitdialog.h \
		produititem.h \
		scannerdialog.h \
		produititem.h \
		moc_predefs.h \
		/usr/bin/moc
	/usr/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/qt/mkspecs/linux-g++ -I'/home/jerome/CloudStation/Hermes 0.7/hermes' -I/usr/include/qt -I/usr/include/qt/QtWidgets -I/usr/include/qt/QtGui -I/usr/include/qt/QtXml -I/usr/include/qt/QtNetwork -I/usr/include/qt/QtCore -I/usr/include/c++/7.2.0 -I/usr/include/c++/7.2.0/x86_64-pc-linux-gnu -I/usr/include/c++/7.2.0/backward -I/usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include -I/usr/local/include -I/usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include-fixed -I/usr/include produititem.h -o moc_produititem.cpp

moc_infosproduitdialog.cpp: produititem.h \
		infosproduitdialog.h \
		scannerdialog.h \
		infosproduitdialog.h \
		moc_predefs.h \
		/usr/bin/moc
	/usr/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/qt/mkspecs/linux-g++ -I'/home/jerome/CloudStation/Hermes 0.7/hermes' -I/usr/include/qt -I/usr/include/qt/QtWidgets -I/usr/include/qt/QtGui -I/usr/include/qt/QtXml -I/usr/include/qt/QtNetwork -I/usr/include/qt/QtCore -I/usr/include/c++/7.2.0 -I/usr/include/c++/7.2.0/x86_64-pc-linux-gnu -I/usr/include/c++/7.2.0/backward -I/usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include -I/usr/local/include -I/usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include-fixed -I/usr/include infosproduitdialog.h -o moc_infosproduitdialog.cpp

moc_aboutdialog.cpp: aboutdialog.h \
		moc_predefs.h \
		/usr/bin/moc
	/usr/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/qt/mkspecs/linux-g++ -I'/home/jerome/CloudStation/Hermes 0.7/hermes' -I/usr/include/qt -I/usr/include/qt/QtWidgets -I/usr/include/qt/QtGui -I/usr/include/qt/QtXml -I/usr/include/qt/QtNetwork -I/usr/include/qt/QtCore -I/usr/include/c++/7.2.0 -I/usr/include/c++/7.2.0/x86_64-pc-linux-gnu -I/usr/include/c++/7.2.0/backward -I/usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include -I/usr/local/include -I/usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include-fixed -I/usr/include aboutdialog.h -o moc_aboutdialog.cpp

moc_scannerdialog.cpp: scannerdialog.h \
		moc_predefs.h \
		/usr/bin/moc
	/usr/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/qt/mkspecs/linux-g++ -I'/home/jerome/CloudStation/Hermes 0.7/hermes' -I/usr/include/qt -I/usr/include/qt/QtWidgets -I/usr/include/qt/QtGui -I/usr/include/qt/QtXml -I/usr/include/qt/QtNetwork -I/usr/include/qt/QtCore -I/usr/include/c++/7.2.0 -I/usr/include/c++/7.2.0/x86_64-pc-linux-gnu -I/usr/include/c++/7.2.0/backward -I/usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include -I/usr/local/include -I/usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include-fixed -I/usr/include scannerdialog.h -o moc_scannerdialog.cpp

moc_settingsdialog.cpp: settingsdialog.h \
		moc_predefs.h \
		/usr/bin/moc
	/usr/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/qt/mkspecs/linux-g++ -I'/home/jerome/CloudStation/Hermes 0.7/hermes' -I/usr/include/qt -I/usr/include/qt/QtWidgets -I/usr/include/qt/QtGui -I/usr/include/qt/QtXml -I/usr/include/qt/QtNetwork -I/usr/include/qt/QtCore -I/usr/include/c++/7.2.0 -I/usr/include/c++/7.2.0/x86_64-pc-linux-gnu -I/usr/include/c++/7.2.0/backward -I/usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include -I/usr/local/include -I/usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include-fixed -I/usr/include settingsdialog.h -o moc_settingsdialog.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_produititem.h ui_infosproduitdialog.h ui_aboutdialog.h ui_scannerdialog.h ui_settingsdialog.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_produititem.h ui_infosproduitdialog.h ui_aboutdialog.h ui_scannerdialog.h ui_settingsdialog.h
ui_mainwindow.h: mainwindow.ui \
		/usr/bin/uic
	/usr/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_produititem.h: produititem.ui \
		/usr/bin/uic
	/usr/bin/uic produititem.ui -o ui_produititem.h

ui_infosproduitdialog.h: infosproduitdialog.ui \
		/usr/bin/uic
	/usr/bin/uic infosproduitdialog.ui -o ui_infosproduitdialog.h

ui_aboutdialog.h: aboutdialog.ui \
		/usr/bin/uic
	/usr/bin/uic aboutdialog.ui -o ui_aboutdialog.h

ui_scannerdialog.h: scannerdialog.ui \
		/usr/bin/uic
	/usr/bin/uic scannerdialog.ui -o ui_scannerdialog.h

ui_settingsdialog.h: settingsdialog.ui \
		/usr/bin/uic
	/usr/bin/uic settingsdialog.ui -o ui_settingsdialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_predefs_clean compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		produititem.h \
		infosproduitdialog.h \
		scannerdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		produititem.h \
		infosproduitdialog.h \
		scannerdialog.h \
		aboutdialog.h \
		settingsdialog.h \
		ui_mainwindow.h \
		manufacturersmanager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

produititem.o: produititem.cpp produititem.h \
		infosproduitdialog.h \
		scannerdialog.h \
		ui_produititem.h \
		mainwindow.h \
		manufacturersmanager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o produititem.o produititem.cpp

infosproduitdialog.o: infosproduitdialog.cpp infosproduitdialog.h \
		produititem.h \
		scannerdialog.h \
		ui_infosproduitdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o infosproduitdialog.o infosproduitdialog.cpp

aboutdialog.o: aboutdialog.cpp aboutdialog.h \
		ui_aboutdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o aboutdialog.o aboutdialog.cpp

scannerdialog.o: scannerdialog.cpp scannerdialog.h \
		ui_scannerdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o scannerdialog.o scannerdialog.cpp

settingsdialog.o: settingsdialog.cpp settingsdialog.h \
		ui_settingsdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o settingsdialog.o settingsdialog.cpp

manufacturersmanager.o: manufacturersmanager.cpp manufacturersmanager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o manufacturersmanager.o manufacturersmanager.cpp

qrc_resources.o: qrc_resources.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_resources.o qrc_resources.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_produititem.o: moc_produititem.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_produititem.o moc_produititem.cpp

moc_infosproduitdialog.o: moc_infosproduitdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_infosproduitdialog.o moc_infosproduitdialog.cpp

moc_aboutdialog.o: moc_aboutdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_aboutdialog.o moc_aboutdialog.cpp

moc_scannerdialog.o: moc_scannerdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_scannerdialog.o moc_scannerdialog.cpp

moc_settingsdialog.o: moc_settingsdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_settingsdialog.o moc_settingsdialog.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:


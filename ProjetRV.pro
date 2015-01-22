FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h \
    fonctionOSG.h \
    ViewerWidget.h \
    shpcontent.h \
    sldcontent.h

SOURCES += \
    mainwindow.cpp \
    main.cpp \
    fonctionOSG.cpp \
    ViewerWidget.cpp \
    shpcontent.cpp \
    sldcontent.cpp

LIBS+=-losg -losgGA -losgDB -losgViewer -losgText -losgUtil -lOpenThreads -losgWidget -losgQt -lshp -ltinyxml2

QT += opengl

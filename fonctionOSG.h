#ifndef FONCTIONOSG_H
#define FONCTIONOSG_H

#include <osg/Group>
#include <osg/Geometry>

#include <osgDB/ReadFile>
#include <osgUtil/Optimizer>
#include <osgViewer/Viewer>

#include <iostream>

#include "shpcontent.h"
#include "mainwindow.h"

#endif // FONCTIONOSG_H

osg::Node* creerScene(Ui::MainWindow * ui);

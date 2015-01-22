#ifndef FONCTIONOSG_H
#define FONCTIONOSG_H

#include <osg/Group>
#include <osg/Geometry>
#include <osg/ShapeDrawable>

#include <osgDB/ReadFile>
#include <osgUtil/Optimizer>
#include <osgViewer/Viewer>

#include <iostream>
#include <cmath>

#include "shpcontent.h"
#include "sldcontent.h"
#include "mainwindow.h"

#endif // FONCTIONOSG_H

osg::Node* creerScene(Ui::MainWindow * ui);

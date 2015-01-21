#ifndef SHPCONTENT_H
#define SHPCONTENT_H

#include <fstream>
#include <string>
#include <iostream>
#include <shapefil.h>
#include <vector>
#include <string>

typedef struct MyPoint
{
 double dX;
 double dY;
 double dZ;

}MyPoint;

typedef struct MyLineString
{
 std::vector<MyPoint> vPointList;

}MyLineString;

typedef struct MyPolygon
{
 std::vector<MyPoint> vPointList;

}MyPolygon;

typedef struct SBoundingBox
{
    float fMaxX;
    float fMaxY;
    float fMinX;
    float fMinY;

}SBoundingBox;


class SHPContent
{
public:
    SHPContent(std::string path);

    //Holds Coordinates of Point Shapefile
    std::vector<MyPoint> vPoints;
    //Holds Coordinates of Line Shapefile
    std::vector<MyLineString> vLines;
    //Holds Coordinates of Polygon Shapefile
    std::vector<MyPolygon> vPolygons;
    //Bounding Box of Shapefile
    SBoundingBox sBoundingBox;

    int shapeType;
};

#endif // SHPCONTENT_H

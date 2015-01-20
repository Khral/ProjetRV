#ifndef SHPCONTENT_H
#define SHPCONTENT_H

#include <fstream>
#include <string>
#include <iostream>
#include <shapefil.h>
#include <vector>
#include <string>

typedef struct MyPoint2D
{
 double dX;
 double dY;

}MyPoint2D;

typedef struct MyLineString2D
{
 std::vector<MyPoint2D> vPointList;

}MyLineString2D;

typedef struct MyPolygon2D
{
 std::vector<MyPoint2D> vPointList;

}MyPolygon2D;

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
    std::vector<MyPoint2D> vPoints;
    //Holds Coordinates of Line Shapefile
    std::vector<MyLineString2D> vLines;
    //Holds Coordinates of Polygon Shapefile
    std::vector<MyPolygon2D> vPolygons;
    //Bounding Box of Shapefile
    SBoundingBox sBoundingBox;

    int shapeType;
};

#endif // SHPCONTENT_H

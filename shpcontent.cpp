#include "shpcontent.h"

using namespace std;

SHPContent::SHPContent(string path)
{
    int pnEntities[200]; //Ceci n'a aucun sens mais ca marche
    int pnShapeType[200]; //Fun fact : si on remplace 1 par 0 ca marche aussi et j'ai toujours aucune idée de pourquoi...
    double padfMinBound[200];
    double padfMaxBound[200];

    SHPHandle file = NULL;

    file = SHPOpen(path.c_str(),"rb");

    ifstream fichier( path.c_str() );
    if(fichier.fail())
        cerr << path  << " : Fichier introuvable" << endl;

    SHPGetInfo(file, pnEntities,pnShapeType, padfMinBound, padfMaxBound);

    //Read Bounding Box of Shapefile
    sBoundingBox.fMaxX=padfMaxBound[0];
    sBoundingBox.fMaxY=padfMaxBound[1];

    sBoundingBox.fMinX=padfMinBound[0];
    sBoundingBox.fMinY=padfMinBound[1];

    if(*pnShapeType == SHPT_NULL) return;

    shapeType = *pnShapeType;

    //Point Shapefile
    if(*pnShapeType == SHPT_POINT)
    {
        SHPObject *psShape;
        for(int i=0;i<*pnEntities;i++)
        {
            psShape = SHPReadObject(file, i);

            double fX = psShape->padfX[0];
            double fY = -psShape->padfY[0];

            //Plot these points
            MyPoint2D pt;
            pt.dX=fX;
            pt.dY=-fY;
            vPoints.push_back(pt);
        }
    }


    //Line Shapefile
    else if(*pnShapeType == SHPT_ARC)
    {
        SHPObject *psShape;
        for(int i=0;i<*pnEntities;i++)
        {
            psShape = SHPReadObject(file, i);
            vector<MyPoint2D> tempPointArray;

            for(int j=0;j<psShape->nVertices;j++)
            {
                double fX = psShape->padfX[j];
                double fY = psShape->padfY[j];
                MyPoint2D pt;
                pt.dX=fX;
                pt.dY=fY;
                tempPointArray.push_back(pt);
            }

            MyLineString2D linestring;
            linestring.vPointList=tempPointArray;
            vLines.push_back(linestring);

        }
    }

    //Polygon Shapefile
    if(*pnShapeType == SHPT_POLYGON)
    {
        SHPObject *psShape;
        for(int i=0;i<*pnEntities;i++)
        {
            psShape = SHPReadObject(file, i);
            vector<MyPoint2D> tempPointArray;

            for(int j=0;j<psShape->nVertices;j++)
            {
                double fX = psShape->padfX[j];
                double fY = psShape->padfY[j];
                MyPoint2D pt;
                pt.dX=fX;
                pt.dY=fY;
                tempPointArray.push_back(pt);
            }
            MyPolygon2D polygon;
            polygon.vPointList=tempPointArray;
            vPolygons.push_back(polygon);
        }

    }

    SHPClose(file);
}

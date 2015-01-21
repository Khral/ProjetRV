#include "fonctionOSG.h"

osg::Node* creerScene(Ui::MainWindow * ui)
{
    SHPContent fileSHP(ui->label_pathSHP->text().toStdString().c_str());

    osg::Geode * geode = new osg::Geode();
    osg::Geometry* geometry;

    osg::Vec3Array* vertices;

    int i, j;
    osg::DrawArrays *da;

    switch(fileSHP.shapeType)
    {
        case SHPT_POINT:
        case SHPT_POINTZ:
        case SHPT_POINTM:
            for(i=0;i<fileSHP.vPoints.size();i++)
            {
                vertices = new osg::Vec3Array;
                geometry = new osg::Geometry();

                if(fileSHP.shapeType==SHPT_POINTZ)
                    vertices->push_back(osg::Vec3(fileSHP.vPoints[i].dX,fileSHP.vPoints[i].dZ,fileSHP.vPoints[i].dY));
                else
                    vertices->push_back(osg::Vec3(fileSHP.vPoints[i].dX,0,fileSHP.vPoints[i].dY));

                geometry->setVertexArray(vertices);
                da = new osg::DrawArrays(osg::PrimitiveSet::LINES,0,vertices->size());
                geometry->addPrimitiveSet(da);
                geode->addDrawable(geometry);
            }
            break;

        case SHPT_ARC:
        case SHPT_ARCM:
        case SHPT_ARCZ:
            for(i=0;i<fileSHP.vLines.size();i++)
            {
                vertices = new osg::Vec3Array;
                geometry = new osg::Geometry();

                for(j=0;j<fileSHP.vLines[i].vPointList.size();j++)
                {
                    if(fileSHP.shapeType==SHPT_ARCZ)
                        vertices->push_back(osg::Vec3(fileSHP.vLines[i].vPointList[j].dX,fileSHP.vLines[i].vPointList[j].dZ,fileSHP.vLines[i].vPointList[j].dY));
                    else
                        vertices->push_back(osg::Vec3(fileSHP.vLines[i].vPointList[j].dX,0,fileSHP.vLines[i].vPointList[j].dY));
                }

                geometry->setVertexArray(vertices);
                da = new osg::DrawArrays(osg::PrimitiveSet::LINES,0,vertices->size());
                geometry->addPrimitiveSet(da);
                geode->addDrawable(geometry);
            }
            break;

        case SHPT_POLYGON:
        case SHPT_POLYGONZ:
        case SHPT_POLYGONM:
            for(i=0;i<fileSHP.vPolygons.size();i++)
            {
                vertices = new osg::Vec3Array;
                geometry = new osg::Geometry();

                for(j=0;j<fileSHP.vPolygons[i].vPointList.size();j++)
                {
                    if(fileSHP.shapeType==SHPT_POLYGONZ)
                        vertices->push_back(osg::Vec3(fileSHP.vPolygons[i].vPointList[j].dX,fileSHP.vPolygons[i].vPointList[j].dZ,fileSHP.vPolygons[i].vPointList[j].dY));
                    else
                        vertices->push_back(osg::Vec3(fileSHP.vPolygons[i].vPointList[j].dX,0,fileSHP.vPolygons[i].vPointList[j].dY));
                }

                geometry->setVertexArray(vertices);
                da = new osg::DrawArrays(osg::PrimitiveSet::LINES,0,vertices->size());
                geometry->addPrimitiveSet(da);
                geode->addDrawable(geometry);
            }
            break;
    }

    geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);


    return geode;
}

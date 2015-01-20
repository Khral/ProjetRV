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
            for(i=0;i<fileSHP.vPoints.size();i++)
            {
                vertices = new osg::Vec3Array;
                geometry = new osg::Geometry();

                vertices->push_back(osg::Vec3(fileSHP.vPoints[i].dX,0,fileSHP.vPoints[i].dY));

                geometry->setVertexArray(vertices);
                da = new osg::DrawArrays(osg::PrimitiveSet::LINES,0,vertices->size());
                geometry->addPrimitiveSet(da);
                geode->addDrawable(geometry);
            }
            break;

        case SHPT_ARC:
            for(i=0;i<fileSHP.vLines.size();i++)
            {
                vertices = new osg::Vec3Array;
                geometry = new osg::Geometry();

                for(j=0;j<fileSHP.vLines[i].vPointList.size();j++)
                {
                    vertices->push_back(osg::Vec3(fileSHP.vLines[i].vPointList[j].dX,0,fileSHP.vLines[i].vPointList[j].dY));
                }

                geometry->setVertexArray(vertices);
                da = new osg::DrawArrays(osg::PrimitiveSet::LINES,0,vertices->size());
                geometry->addPrimitiveSet(da);
                geode->addDrawable(geometry);
            }
            break;

        case SHPT_POLYGON:
            for(i=0;i<fileSHP.vPolygons.size();i++)
            {
                vertices = new osg::Vec3Array;
                geometry = new osg::Geometry();

                for(j=0;j<fileSHP.vPolygons[i].vPointList.size();j++)
                {
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

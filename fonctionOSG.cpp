#include "fonctionOSG.h"

osg::Node* creerScene(Ui::MainWindow * ui)
{
    SHPContent fileSHP(ui->label_pathSHP->text().toStdString().c_str());

    osg::Geode* geode = new osg::Geode();
    osg::Geometry* geometry = new osg::Geometry();

    osg::Vec3Array* vertices = new osg::Vec3Array;

    int i, j;
    osg::DrawArrays *da;

    switch(fileSHP.shapeType)
    {
        case SHPT_POINT:
            /*for(i=0;i<fileSHP.vPoints.size();i++)
            {
                vertices->push_back(osg::Vec3(fileSHP.vPoints[i].dX,fileSHP.vPoints[i].dY,0));
            }
            geometry->setVertexArray(vertices);

            color->push_back(osg::Vec4(1.0,0.0,0.0,1.0));
            geometry->setColorArray(color.get());

            geometry->setColorBinding(osg::Geometry::BIND_PER_PRIMITIVE_SET);
            geometry->addPrimitiveSet(new osg::DrawArrays(GL_LINES,0,2));*/

            break;
        case SHPT_ARC:
            for(i=0;i<fileSHP.vLines.size();i++)
            {
                for(j=0;j<fileSHP.vLines[i].vPointList.size();j++)
                {
                    vertices->push_back(osg::Vec3(fileSHP.vLines[i].vPointList[j].dX,fileSHP.vLines[i].vPointList[j].dY,0));
                }
                geometry->setVertexArray(vertices);
                da = new osg::DrawArrays(osg::PrimitiveSet::LINES,0,vertices->size());
                geometry->addPrimitiveSet(da);
                geode->addDrawable(geometry);
            }

            geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);

            break;
        case SHPT_POLYGON:
            /*for(i=0;i<fileSHP.vPolygons.size();i++)
            {
                for(j=0;j<fileSHP.vPolygons[i].vPointList.size();j++)
                {
                    vertices->push_back(osg::Vec3(fileSHP.vPolygons[i].vPointList[j].dX,fileSHP.vPolygons[i].vPointList[j].dY,0));
                }
            }

            geometry->setVertexArray(vertices);

            geometry->setColorBinding(osg::Geometry::BIND_PER_PRIMITIVE_SET);
            geometry->addPrimitiveSet(new osg::DrawArrays(GL_LINES,0,2));
*/
            break;
    }

    return geode;
}

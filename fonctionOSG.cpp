#include "fonctionOSG.h"

osg::Node* creerScene(Ui::MainWindow * ui)
{
    SHPContent fileSHP(ui->label_pathSHP->text().toStdString().c_str());
    SLDContent fileSLD(ui->label_pathSLD->text().toStdString().c_str());

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
                if(fileSLD.type==SHPT_POINT && fileSLD.forme=="circle") {
                    geometry = new osg::Geometry();
                    int sx = fileSHP.vPoints[i].dX;
                    int sy = fileSHP.vPoints[i].dY;
                    int sz = fileSHP.vPoints[i].dZ;
                    int t = fileSLD.taille;

                    geode->addDrawable(new osg::ShapeDrawable( new osg::Sphere(osg::Vec3(sx,sz,sy),t)));
                }
                else if (fileSLD.type==SHPT_POINT && fileSLD.forme=="square"){
                    vertices = new osg::Vec3Array;
                    geometry = new osg::Geometry();

                    vertices->push_back(osg::Vec3(fileSHP.vPoints[i].dX-fileSLD.taille/2,fileSHP.vPoints[i].dZ,fileSHP.vPoints[i].dY-fileSLD.taille/2));
                    vertices->push_back(osg::Vec3(fileSHP.vPoints[i].dX-fileSLD.taille/2,fileSHP.vPoints[i].dZ,fileSHP.vPoints[i].dY+fileSLD.taille/2));
                    vertices->push_back(osg::Vec3(fileSHP.vPoints[i].dX+fileSLD.taille/2,fileSHP.vPoints[i].dZ,fileSHP.vPoints[i].dY-fileSLD.taille/2));
                    vertices->push_back(osg::Vec3(fileSHP.vPoints[i].dX+fileSLD.taille/2,fileSHP.vPoints[i].dZ,fileSHP.vPoints[i].dY+fileSLD.taille/2));

                    geometry->setVertexArray(vertices);

                    osg::Vec4Array* colors = new osg::Vec4Array;

                    for(int k=0;k<vertices->size();k++)
                    {
                        colors->push_back(osg::Vec4(fileSLD.couleur[0],fileSLD.couleur[1],fileSLD.couleur[2],fileSLD.alpha));
                    }

                    geometry->setColorArray(colors);
                    geometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
                    da = new osg::DrawArrays(osg::PrimitiveSet::QUADS,0,vertices->size());
                    geometry->addPrimitiveSet(da);

                    geode->addDrawable(geometry);
                }
                else if (fileSLD.type==SHPT_POINT && fileSLD.forme=="triangle"){
                    vertices = new osg::Vec3Array;
                    geometry = new osg::Geometry();

                    vertices->push_back(osg::Vec3(fileSHP.vPoints[i].dX-fileSLD.taille/2,fileSHP.vPoints[i].dZ,fileSHP.vPoints[i].dY));
                    vertices->push_back(osg::Vec3(fileSHP.vPoints[i].dX+fileSLD.taille/2,fileSHP.vPoints[i].dZ,fileSHP.vPoints[i].dY));
                    vertices->push_back(osg::Vec3(fileSHP.vPoints[i].dX,fileSHP.vPoints[i].dZ,fileSHP.vPoints[i].dY-fileSLD.taille*1.7/2));

                    geometry->setVertexArray(vertices);

                    osg::Vec4Array* colors = new osg::Vec4Array;

                    for(int k=0;k<vertices->size();k++)
                    {
                        colors->push_back(osg::Vec4(fileSLD.couleur[0],fileSLD.couleur[1],fileSLD.couleur[2],fileSLD.alpha));
                    }

                    geometry->setColorArray(colors);
                    geometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
                    da = new osg::DrawArrays(osg::PrimitiveSet::TRIANGLES,0,vertices->size());
                    geometry->addPrimitiveSet(da);

                    geode->addDrawable(geometry);
                }
                else{
                    vertices = new osg::Vec3Array;
                    geometry = new osg::Geometry();

                    vertices->push_back(osg::Vec3(fileSHP.vPoints[i].dX,fileSHP.vPoints[i].dZ,fileSHP.vPoints[i].dY));

                    geometry->setVertexArray(vertices);

                    osg::Vec4Array* colors = new osg::Vec4Array;

                    for(int k=0;k<vertices->size();k++)
                    {
                        colors->push_back(osg::Vec4(fileSLD.couleur[0],fileSLD.couleur[1],fileSLD.couleur[2],fileSLD.alpha));
                    }

                    geometry->setColorArray(colors);
                    geometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
                    da = new osg::DrawArrays(osg::PrimitiveSet::LINES,0,vertices->size());
                    geometry->addPrimitiveSet(da);

                    geode->addDrawable(geometry);
                }
            }
            break;

        case SHPT_ARC:
        case SHPT_ARCM:
        case SHPT_ARCZ:

        case SHPT_MULTIPOINT:
        case SHPT_MULTIPOINTM:
        case SHPT_MULTIPOINTZ:
            for(i=0;i<fileSHP.vLines.size();i++)
            {
                vertices = new osg::Vec3Array;
                geometry = new osg::Geometry();

                if(fileSLD.type==SHPT_ARC){
                    for(j=0;j<fileSHP.vLines[i].vPointList.size()-1;j++)
                    {
                        float rap = (fileSHP.vLines[i].vPointList[j+1].dY-fileSHP.vLines[i].vPointList[j].dY)*1.0/(fileSHP.vLines[i].vPointList[j+1].dX-fileSHP.vLines[i].vPointList[j].dX)*1.0;
                        vertices->push_back(osg::Vec3(fileSHP.vLines[i].vPointList[j].dX-fileSLD.taille*rap/sqrt(1+pow(rap,2)),fileSHP.vLines[i].vPointList[j].dZ,fileSHP.vLines[i].vPointList[j].dY+fileSLD.taille/sqrt(1+pow(rap,2))));
                        vertices->push_back(osg::Vec3(fileSHP.vLines[i].vPointList[j].dX+fileSLD.taille*rap/sqrt(1+pow(rap,2)),fileSHP.vLines[i].vPointList[j].dZ,fileSHP.vLines[i].vPointList[j].dY-fileSLD.taille/sqrt(1+pow(rap,2))));
                        vertices->push_back(osg::Vec3(fileSHP.vLines[i].vPointList[j+1].dX-fileSLD.taille*rap/sqrt(1+pow(rap,2)),fileSHP.vLines[i].vPointList[j].dZ,fileSHP.vLines[i].vPointList[j+1].dY+fileSLD.taille/sqrt(1+pow(rap,2))));
                        vertices->push_back(osg::Vec3(fileSHP.vLines[i].vPointList[j+1].dX+fileSLD.taille*rap/sqrt(1+pow(rap,2)),fileSHP.vLines[i].vPointList[j].dZ,fileSHP.vLines[i].vPointList[j+1].dY-fileSLD.taille/sqrt(1+pow(rap,2))));
                    }

                    geometry->setVertexArray(vertices);

                    osg::Vec4Array* colors = new osg::Vec4Array;

                    for(int k=0;k<vertices->size();k++)
                    {
                        colors->push_back(osg::Vec4(fileSLD.couleur[0],fileSLD.couleur[1],fileSLD.couleur[2],fileSLD.alpha));
                    }

                    geometry->setColorArray(colors);
                    geometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
                    da = new osg::DrawArrays(osg::PrimitiveSet::QUADS,0,vertices->size());

                    geode->addDrawable(geometry);
                }
                else {
                    for(j=0;j<fileSHP.vLines[i].vPointList.size();j++)
                    {
                        if(fileSHP.shapeType==SHPT_ARCZ)
                            vertices->push_back(osg::Vec3(fileSHP.vLines[i].vPointList[j].dX,fileSHP.vLines[i].vPointList[j].dZ,fileSHP.vLines[i].vPointList[j].dY));
                        else
                            vertices->push_back(osg::Vec3(fileSHP.vLines[i].vPointList[j].dX,0,fileSHP.vLines[i].vPointList[j].dY));
                    }

                    geometry->setVertexArray(vertices);

                    osg::Vec4Array* colors = new osg::Vec4Array;

                    for(int k=0;k<vertices->size();k++)
                    {
                        colors->push_back(osg::Vec4(fileSLD.couleur[0],fileSLD.couleur[1],fileSLD.couleur[2],fileSLD.alpha));
                    }

                    geometry->setColorArray(colors);
                    geometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
                    da = new osg::DrawArrays(osg::PrimitiveSet::LINES,0,vertices->size());
                }

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
                    vertices->push_back(osg::Vec3(fileSHP.vPolygons[i].vPointList[j].dX,fileSHP.vPolygons[i].vPointList[j].dZ,fileSHP.vPolygons[i].vPointList[j].dY));
                }

                geometry->setVertexArray(vertices);

                osg::Vec4Array* colors = new osg::Vec4Array;

                for(int k=0;k<vertices->size();k++)
                {
                    colors->push_back(osg::Vec4(fileSLD.couleur[0],fileSLD.couleur[1],fileSLD.couleur[2],fileSLD.alpha));
                }

                geometry->setColorArray(colors);
                geometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
                da = new osg::DrawArrays(osg::PrimitiveSet::POLYGON,0,vertices->size());
                geometry->addPrimitiveSet(da);

                geode->addDrawable(geometry);
            }
            break;

        case SHPT_MULTIPATCH:
        for(i=0;i<fileSHP.vMultipatchs.size();i++)
        {
            vertices = new osg::Vec3Array;
            geometry = new osg::Geometry();

            for(j=0;j<fileSHP.vMultipatchs[i].vPointList.size();j++)
            {
                vertices->push_back(osg::Vec3(fileSHP.vMultipatchs[i].vPointList[j].dX,fileSHP.vMultipatchs[i].vPointList[j].dZ,fileSHP.vMultipatchs[i].vPointList[j].dY));
            }

            geometry->setVertexArray(vertices);

            osg::Vec4Array* colors = new osg::Vec4Array;

            for(int k=0;k<vertices->size();k++)
            {
                colors->push_back(osg::Vec4(fileSLD.couleur[0],fileSLD.couleur[1],fileSLD.couleur[2],fileSLD.alpha));
            }

            geometry->setColorArray(colors);
            geometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
            da = new osg::DrawArrays(osg::PrimitiveSet::LINES,0,vertices->size());
            geometry->addPrimitiveSet(da);

            geode->addDrawable(geometry);
        }
        break;
    }

    geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);


    return geode;
}

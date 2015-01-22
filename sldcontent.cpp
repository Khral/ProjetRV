#include "sldcontent.h"

SLDContent::SLDContent(std::string path)
{
    tinyxml2::XMLDocument doc;
    doc.LoadFile(path.c_str());

    std::string s;

    if(doc.FirstChildElement("FeatureTypeStyle"))
        explorer(doc.FirstChildElement("FeatureTypeStyle"));

}

void SLDContent::explorer(tinyxml2::XMLElement * elem)
{
    if(elem->FirstChild())
        explorer(elem->FirstChildElement());
    if(elem->NextSibling())
        explorer(elem->NextSiblingElement());

    if(elem->Name()=="PointSymbolizer")
        type = SHPT_POINT;
    if(elem->Name()=="TextSymbolizer")
        texte=true;
    if(elem->Name()=="LineSymbolizer")
        type = SHPT_ARC;
    if(elem->Name()=="PolygonSymbolizer")
        type = SHPT_POLYGON;
    if(elem->Name()=="WellKnownName")
        forme=elem->GetText();
    if(elem->Name()=="Stroke")
        bordure=true;
    if(elem->Name()=="Size")
        taille=atoi(elem->GetText());
    if(elem->Name()=="Rotation")
        rotation=atoi(elem->GetText());
    if(elem->Name()=="CssParameter") {
        if(elem->Attribute("name")=="fill")
            couleur=elem->GetText();
        if(elem->Attribute("name")=="stroke")
            couleurBordure=elem->GetText();
        if(elem->Attribute("name")=="stroke-width")
            tailleBordure=atoi(elem->GetText());
        if(elem->Attribute("name")=="fill-opacity")
            alpha=atoi(elem->GetText());
        if(elem->Attribute("name")=="stroke-dasharray") {
            std::string s = elem->GetText();
            pointille[0]=atof(s.substr(0,s.find(" ",0)).c_str());
            pointille[1]=atof(s.substr(s.find(" ",0)+1,s.size()-(s.find(" ",0)+1)).c_str());
        }
    }
}

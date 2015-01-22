#include "sldcontent.h"

SLDContent::SLDContent(std::string path)
{
    tinyxml2::XMLDocument doc;
    doc.LoadFile(path.c_str());

    std::cerr<<path.c_str()<<std::endl;

    if(doc.FirstChildElement("FeatureTypeStyle"))
        explorer(doc.FirstChildElement("FeatureTypeStyle"));
}

void SLDContent::explorer(tinyxml2::XMLElement * elem)
{
    if(std::string(elem->Name())=="PointSymbolizer")
        type = SHPT_POINT;
    if(std::string(elem->Name())=="TextSymbolizer")
        texte=true;
    if(std::string(elem->Name())=="LineSymbolizer")
        type = SHPT_ARC;
    if(std::string(elem->Name())=="PolygonSymbolizer")
        type = SHPT_POLYGON;
    if(std::string(elem->Name())=="WellKnownName")
        forme=elem->GetText();
    if(std::string(elem->Name())=="Stroke"&&type==SHPT_POINT)
        bordure=true;
    if(std::string(elem->Name())=="Size"){
        taille=atoi(elem->GetText());
    }
    if(std::string(elem->Name())=="Rotation")
        rotation=atoi(elem->GetText());
    if(std::string(elem->Name())=="CssParameter") {
        if(std::string(elem->Attribute("name"))=="fill"){
            std::string s=elem->GetText();

            if((int)s[1]>(int)('a'))
                couleur[0]+=((int)s[1]-(int)('a')+10)*16;
            else if((int)s[1]>(int)('A'))
                couleur[0]+=((int)s[1]-(int)('A')+10)*16;
            else
                couleur[0]+=((int)s[1]-(int)('0'))*16;

            if((int)s[2]>(int)('a'))
                couleur[0]+=((int)s[2]-(int)('a')+10)*1;
            else if((int)s[2]>(int)('A'))
                couleur[0]+=((int)s[2]-(int)('A')+10)*1;
            else
                couleur[0]+=(int)s[2]-(int)('0');

            if((int)s[3]>(int)('a'))
                couleur[1]+=((int)s[3]-(int)('a')+10)*16;
            else if((int)s[3]>(int)('A'))
                couleur[1]+=((int)s[3]-(int)('A')+10)*16;
            else
                couleur[1]+=((int)s[3]-(int)('0'))*16;

            if((int)s[4]>(int)('a'))
                couleur[1]+=((int)s[4]-(int)('a')+10)*1;
            else if((int)s[4]>(int)('A'))
                couleur[1]+=((int)s[4]-(int)('A')+10)*1;
            else
                couleur[1]+=((int)s[4]-(int)('0'))*1;

            if((int)s[5]>(int)('a'))
                couleur[2]+=((int)s[5]-(int)('a')+10)*16;
            else if((int)s[5]>(int)('A'))
                couleur[2]+=((int)s[5]-(int)('A')+10)*16;
            else
                couleur[2]+=((int)s[5]-(int)('0'))*16;

            if((int)s[6]>(int)('a'))
                couleur[2]+=((int)s[6]-(int)('a')+10)*1;
            else if((int)s[6]>(int)('A'))
                couleur[2]+=((int)s[6]-(int)('A')+10)*1;
            else
                couleur[2]+=((int)s[6]-(int)('0'))*1;

            couleur[0]/=255;
            couleur[1]/=255;
            couleur[2]/=255;
        }

        if(std::string(elem->Attribute("name"))=="stroke"){
            if(type==SHPT_POINT){
                std::string s=elem->GetText();

                if((int)s[1]>(int)('a'))
                    couleurBordure[0]+=((int)s[1]-(int)('a')+10)*16;
                else if((int)s[1]>(int)('A'))
                    couleurBordure[0]+=((int)s[1]-(int)('A')+10)*16;
                else
                    couleurBordure[0]+=((int)s[1]-(int)('0'))*16;

                if((int)s[2]>(int)('a'))
                    couleurBordure[0]+=((int)s[2]-(int)('a')+10)*1;
                else if((int)s[2]>(int)('A'))
                    couleurBordure[0]+=((int)s[2]-(int)('A')+10)*1;
                else
                    couleurBordure[0]+=(int)s[2]-(int)('0');

                if((int)s[3]>(int)('a'))
                    couleurBordure[1]+=((int)s[3]-(int)('a')+10)*16;
                else if((int)s[3]>(int)('A'))
                    couleurBordure[1]+=((int)s[3]-(int)('A')+10)*16;
                else
                    couleurBordure[1]+=((int)s[3]-(int)('0'))*16;

                if((int)s[4]>(int)('a'))
                    couleurBordure[1]+=((int)s[4]-(int)('a')+10)*1;
                else if((int)s[4]>(int)('A'))
                    couleurBordure[1]+=((int)s[4]-(int)('A')+10)*1;
                else
                    couleurBordure[1]+=((int)s[4]-(int)('0'))*1;

                if((int)s[5]>(int)('a'))
                    couleurBordure[2]+=((int)s[5]-(int)('a')+10)*16;
                else if((int)s[5]>(int)('A'))
                    couleurBordure[2]+=((int)s[5]-(int)('A')+10)*16;
                else
                    couleurBordure[2]+=((int)s[5]-(int)('0'))*16;

                if((int)s[6]>(int)('a'))
                    couleurBordure[2]+=((int)s[6]-(int)('a')+10)*1;
                else if((int)s[6]>(int)('A'))
                    couleurBordure[2]+=((int)s[6]-(int)('A')+10)*1;
                else
                    couleurBordure[2]+=((int)s[6]-(int)('0'))*1;

                couleurBordure[0]/=255;
                couleurBordure[1]/=255;
                couleurBordure[2]/=255;
            }
            else{
                std::string s=elem->GetText();

                if((int)s[1]>(int)('a'))
                    couleur[0]+=((int)s[1]-(int)('a')+10)*16;
                else if((int)s[1]>(int)('A'))
                    couleur[0]+=((int)s[1]-(int)('A')+10)*16;
                else
                    couleur[0]+=((int)s[1]-(int)('0'))*16;

                if((int)s[2]>(int)('a'))
                    couleur[0]+=((int)s[2]-(int)('a')+10)*1;
                else if((int)s[2]>(int)('A'))
                    couleur[0]+=((int)s[2]-(int)('A')+10)*1;
                else
                    couleur[0]+=(int)s[2]-(int)('0');

                if((int)s[3]>(int)('a'))
                    couleur[1]+=((int)s[3]-(int)('a')+10)*16;
                else if((int)s[3]>(int)('A'))
                    couleur[1]+=((int)s[3]-(int)('A')+10)*16;
                else
                    couleur[1]+=((int)s[3]-(int)('0'))*16;

                if((int)s[4]>(int)('a'))
                    couleur[1]+=((int)s[4]-(int)('a')+10)*1;
                else if((int)s[4]>(int)('A'))
                    couleur[1]+=((int)s[4]-(int)('A')+10)*1;
                else
                    couleur[1]+=((int)s[4]-(int)('0'))*1;

                if((int)s[5]>(int)('a'))
                    couleur[2]+=((int)s[5]-(int)('a')+10)*16;
                else if((int)s[5]>(int)('A'))
                    couleur[2]+=((int)s[5]-(int)('A')+10)*16;
                else
                    couleur[2]+=((int)s[5]-(int)('0'))*16;

                if((int)s[6]>(int)('a'))
                    couleur[2]+=((int)s[6]-(int)('a')+10)*1;
                else if((int)s[6]>(int)('A'))
                    couleur[2]+=((int)s[6]-(int)('A')+10)*1;
                else
                    couleur[2]+=((int)s[6]-(int)('0'))*1;

                couleur[0]/=255;
                couleur[1]/=255;
                couleur[2]/=255;
            }
        }
        if(std::string(elem->Attribute("name"))=="stroke-width"){
            if(type==SHPT_POINT)
                tailleBordure=atoi(elem->GetText());
            else
                taille=atoi(elem->GetText());
        }
        if(std::string(elem->Attribute("name"))=="fill-opacity")
            alpha=atof(elem->GetText());
        if(std::string(elem->Attribute("name"))=="stroke-dasharray") {
            std::string s = elem->GetText();
            pointille[0]=atof(s.substr(0,s.find(" ",0)).c_str());
            pointille[1]=atof(s.substr(s.find(" ",0)+1,s.size()-(s.find(" ",0)+1)).c_str());
        }
    }

    if(elem->FirstChildElement())
        explorer(elem->FirstChildElement());
    if(elem->NextSiblingElement())
        explorer(elem->NextSiblingElement());
}

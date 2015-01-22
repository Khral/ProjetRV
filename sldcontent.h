#ifndef SLDCONTENT_H
#define SLDCONTENT_H

#include <shapefil.h>
#include <string>
#include <tinyxml2.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


class SLDContent
{
public:
    SLDContent(std::string path);

    int type;
    std::string forme;
    float couleur[3] = {0,0,0};
    float alpha = 1;
    int taille;
    int rotation;

    bool bordure;
    int tailleBordure;
    float couleurBordure[3] = {0,0,0};

    bool texte;
    std::string policeTexte;
    int tailleTexte;
    std::string styleTexte;
    int poidsTexte;
    int rotationTexte;
    bool texteSuitLigne;

    int pointille[2];

private:
    void explorer(tinyxml2::XMLElement* elem);
};

#endif // SLDCONTENT_H

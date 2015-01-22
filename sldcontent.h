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
    std::string couleur;
    int alpha;
    int taille;
    int rotation;

    bool bordure;
    int tailleBordure;
    std::string couleurBordure;

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

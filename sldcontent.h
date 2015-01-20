#ifndef SLDCONTENT_H
#define SLDCONTENT_H

#include <shapefil.h>
#include <string>

class SLDContent
{
public:
    SLDContent(std::string path);

    int type;
    int forme;
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
};

#endif // SLDCONTENT_H

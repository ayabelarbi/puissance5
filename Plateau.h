#ifndef PLATEAU_H
#define PLATEAU_H

#include <vector>
#include "Joueur.h"

class Plateau {
private:
    std::vector<std::vector<char>> grille;
    int nbLignes;
    int nbColonnes;

public:
    Plateau(int nbLignes, int nbColonnes);
    bool placerPion(int colonne, const Joueur& joueur);
    bool estPleine() const;
    bool estValideCoup(int colonne) const;
    bool verifierAlignement(const Joueur& joueur) const;
    void afficherPlateau() const;
    int getNbColonnes() const;
};

#endif // PLATEAU_H

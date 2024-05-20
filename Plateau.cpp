#include "Plateau.h"
#include <iostream>

Plateau::Plateau(int nbLignes, int nbColonnes)
    : nbLignes(nbLignes), nbColonnes(nbColonnes) {
    grille.resize(nbLignes, std::vector<char>(nbColonnes, '-'));
}

bool Plateau::placerPion(int colonne, const Joueur& joueur) {
    if (colonne < 0 || colonne >= nbColonnes || grille[0][colonne] != '-') {
        return false;
    }

    for (int ligne = nbLignes - 1; ligne >= 0; ligne--) {
        if (grille[ligne][colonne] == '-') {
            grille[ligne][colonne] = joueur.getCouleur();
            return true;
        }
    }
    return false;
}

bool Plateau::estPleine() const {
    for (int colonne = 0; colonne < nbColonnes; colonne++) {
        if (grille[0][colonne] == '-') {
            return false;
        }
    }
    return true;
}

bool Plateau::estValideCoup(int colonne) const {
    return colonne >= 0 && colonne < nbColonnes && grille[0][colonne] == '-';
}

bool Plateau::verifierAlignement(const Joueur& joueur) const {
    char couleur = joueur.getCouleur();
    const int directions[4][2] = { {0, 1}, {1, 0}, {1, 1}, {1, -1} };

    for (int ligne = 0; ligne < nbLignes; ++ligne) {
        for (int colonne = 0; colonne < nbColonnes; ++colonne) {
            if (grille[ligne][colonne] == couleur) {
                for (const auto& direction : directions) {
                    bool aligne = true;
                    for (int k = 1; k < 5; ++k) {
                        int newLigne = ligne + k * direction[0];
                        int newColonne = colonne + k * direction[1];
                        if (newLigne < 0 || newLigne >= nbLignes || newColonne < 0 || newColonne >= nbColonnes || grille[newLigne][newColonne] != couleur) {
                            aligne = false;
                            break;
                        }
                    }
                    if (aligne) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Plateau::afficherPlateau() const {
    std::cout << "  ";
    for (int colonne = 0; colonne < nbColonnes; colonne++) {
        std::cout << colonne << " ";
    }
    std::cout << std::endl;

    for (int ligne = 0; ligne < nbLignes; ligne++) {
        std::cout << ligne << " ";
        for (int colonne = 0; colonne < nbColonnes; colonne++) {
            std::cout << grille[ligne][colonne] << " ";
        }
        std::cout << std::endl;
    }
}

int Plateau::getNbColonnes() const {
    return nbColonnes;
}

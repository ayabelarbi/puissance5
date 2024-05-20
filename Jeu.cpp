#include "Jeu.h"
#include <stdexcept>
#include <cstdlib>
#include <ctime>

Jeu::Jeu(size_t nbJoueurs, int nbLignes, int nbColonnes, bool modeIA)
    : plateau(nbLignes, nbColonnes), joueurCourant(0), modeIA(modeIA) {
    if (nbJoueurs < 1) {
        throw std::invalid_argument("Au moins un joueur est nécessaire.");
    }
    joueurs.emplace_back("Joueur 1", 'X');
    if (nbJoueurs > 1) {
        joueurs.emplace_back("Joueur 2", 'O');
    } else if (modeIA) {
        joueurs.emplace_back("IA", 'O');
    }
}

bool Jeu::jouerCoup(int colonne) {
    if (!plateau.estValideCoup(colonne)) {
        return false;
    }

    bool coupValide = plateau.placerPion(colonne, joueurs[joueurCourant]);
    if (coupValide && plateau.verifierAlignement(joueurs[joueurCourant])) {
        return true;
    }

    if (plateau.estPleine()) {
        return true;
    }

    passerAuJoueurSuivant();
    return true;
}

Plateau& Jeu::getPlateau() {
    return plateau;
}

const Joueur& Jeu::getJoueurCourant() const {
    return joueurs[joueurCourant];
}

bool Jeu::estIAEnCours() const {
    return modeIA && joueurs[joueurCourant].getNom() == "IA";
}

int Jeu::choisirCoupIA() const {
    std::vector<int> coupsValides;
    for (int col = 0; col < plateau.getNbColonnes(); ++col) {
        if (plateau.estValideCoup(col)) {
            coupsValides.push_back(col);
        }
    }
    srand(time(nullptr));
    return coupsValides[rand() % coupsValides.size()];
}

void Jeu::passerAuJoueurSuivant() {
    joueurCourant = (joueurCourant + 1) % joueurs.size();
}

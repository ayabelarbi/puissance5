#ifndef JEU_H
#define JEU_H

#include <vector>
#include "Plateau.h"
#include "Joueur.h"

class Jeu {
private:
    Plateau plateau;
    std::vector<Joueur> joueurs;
    size_t joueurCourant;
    bool modeIA;

public:
    Jeu(size_t nbJoueurs, int nbLignes, int nbColonnes, bool modeIA = false);
    bool jouerCoup(int colonne);
    Plateau& getPlateau();
    const Joueur& getJoueurCourant() const;
    bool estIAEnCours() const;
    int choisirCoupIA() const;

private:
    void passerAuJoueurSuivant();
};

#endif // JEU_H

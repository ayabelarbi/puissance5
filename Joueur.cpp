#include "Joueur.h"

Joueur::Joueur(const std::string& nom, char couleur) : nom(nom), couleur(couleur) {}

std::string Joueur::getNom() const {
    return nom;
}

char Joueur::getCouleur() const {
    return couleur;
}

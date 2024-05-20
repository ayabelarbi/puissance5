#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

class Joueur {
private:
    std::string nom;
    char couleur;

public:
    Joueur(const std::string& nom, char couleur);
    std::string getNom() const;
    char getCouleur() const;
};

#endif // JOUEUR_H

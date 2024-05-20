#include "Jeu.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>

using namespace std;

void afficherAvecAnimation(const string& ligne, int vitesse = 50) {
    int length = ligne.length();
    int animationSteps = 30;

    for (int i = 0; i < length; ++i) {
        cout << "\r";
        for (int j = 0; j <= i; ++j) {
            cout << ligne[j];
        }
        int numStars = ((i + 1) * animationSteps) / length;
        for (int k = 0; k < animationSteps - numStars; ++k) {
            cout << "*";
        }
        cout << flush;
        this_thread::sleep_for(chrono::milliseconds(vitesse));
    }
}

void presentationDuJeu() {
    afficherAvecAnimation("Bienvenue dans le Puissance 5 !");
    cout << endl;
    afficherAvecAnimation("Le secret pour gagner, il suffit de cinq cases alignées !");
    cout << endl;
    afficherAvecAnimation("By : Gwénolé MARTIN, Aya BELARBI, Eden BAUDIN");
    cout << endl;
}

int lireEntree(const string& prompt) {
    int valeur;
    while (true) {
        afficherAvecAnimation(prompt);
        if (cin >> valeur) {
            break;
        } else {
            cout << "Entrée invalide. Veuillez entrer un nombre entier." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return valeur;
}

void demarrerPartie() {
    presentationDuJeu();

    int run = 1;
    while(run == 1){
        cout<< endl;
        int nbLignes = lireEntree("Entrez le nombre de lignes : ");
        int nbColonnes = lireEntree("Entrez le nombre de colonnes : ");

        int modeIAEntree = lireEntree("Saisir 1 pour 1vsIA ou 0 pour 1vs1 : ");
        bool modeIA = (modeIAEntree == 1);
        int nbJoueurs = modeIA ? 1 : 2;

        cout << endl;
        afficherAvecAnimation("[---Initialisation en cours---]");
        cout << endl;

        Jeu jeu(nbJoueurs, nbLignes, nbColonnes, modeIA);
        Plateau& plateau = jeu.getPlateau();

        while (true) {
            cout << endl << "Tour de " << jeu.getJoueurCourant().getNom() << " (" << jeu.getJoueurCourant().getCouleur() << ")" << endl;
            plateau.afficherPlateau();

            if (jeu.estIAEnCours()) {
                this_thread::sleep_for(chrono::milliseconds(500));
                int coup = jeu.choisirCoupIA();
                jeu.jouerCoup(coup);
            } else {
                int colonne = lireEntree("Entrez le numéro de colonne : ");
                if (!jeu.jouerCoup(colonne)) {
                    cout << "Coup invalide, essayez de nouveau." << endl;
                    continue;
                }
            }

            cout << endl;
            plateau.afficherPlateau();
            if (plateau.verifierAlignement(jeu.getJoueurCourant())) {
                cout << endl << jeu.getJoueurCourant().getNom() << " a gagné !" << endl << endl;
                break;
            } else if (plateau.estPleine()) {
                cout << "Match nul, la grille est pleine !" << endl << endl;
                break;
            }
            cout << "---------------------";
        }
        run = lireEntree("Saisir 1 pour continuer, 0 pour stop : ");
    }
}

int main() {
    demarrerPartie();
    return 0;
}

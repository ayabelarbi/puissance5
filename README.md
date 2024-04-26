# puissance5
Projet Puissance 5  

# Les classe et diagramme de class 
## Classe principales:

Classe Jeu:
    Attributs:
        taille_grille: La taille de la grille (nombre de lignes et de colonnes).
        grille: Une matrice représentant l'état de la grille (pions vides, pions rouges, pions jaunes).
        joueur_actuel: Le joueur qui doit jouer (1 pour rouge, 2 pour jaune).
        gagnant: Le joueur gagnant (0 si pas encore de gagnant).
    Méthodes:
        initialiser(): Initialise la grille avec des pions vides.
        jouer(pion, colonne): Joue un pion dans la colonne spécifiée.
        verifier_victoire(): Vérifie si un joueur a gagné.
        changer_joueur(): Passe au joueur suivant.
        afficher_grille(): Affiche l'état de la grille à l'écran.


Class Pion:
    Attributs:
        couleur: La couleur du pion (rouge ou jaune).
    Méthodes:
        get_couleur(): Renvoie la couleur du pion.

## Classes secondaires:

Classe Grille:
Représente la grille de jeu.
Contient des méthodes pour accéder aux pions et les modifier.

Classe Joueur:
    Représente un joueur humain ou une IA.
    Contient des méthodes pour effectuer un choix de coup.

Classe Interface 
    +afficherPlateau(plateau: Plateau)
    +demanderCoup(joueur: Joueur): int
    +afficherGagnant(joueur: Joueur)

## Diagramme de class
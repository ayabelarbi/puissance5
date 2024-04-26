# puissance5
Projet Puissance 5  

# Les classes et diagramme de class 

    class Jeu {
        -Plateau plateau
        -Joueur joueurActuel
        -EtatJeu etat
        +demarrerJeu()
        +jouerCoup(colonne: int)
        +changerJoueur()
        +verifierGagnant(): bool
    }
    
    class Plateau {
        -Pion[5][5] grille
        +ajouterPion(colonne: int, joueur: Joueur)
        +colonneRemplie(colonne: int): bool
        +verifierGagnant(joueur: Joueur): bool
    }
    
    class Joueur {
        -nom: string
        -couleur: Couleur
        +jouerCoup(plateau: Plateau): int
    }
    
    class IA {
        +jouerCoup(plateau: Plateau): int
    }
    
    class Pion {
        -couleur: Couleur
    }
    
    class Interface {
        +afficherPlateau(plateau: Plateau)
        +demanderCoup(joueur: Joueur): int
        +afficherGagnant(joueur: Joueur)
    }
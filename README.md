# Projet Puissance 5

## Les classes et le diagramme de classes

### Classes principales

#### Classe Jeu
**Attributs :**
- plateau : Plateau
- joueurs : vector<Joueur>
- joueurCourant : size_t
- modeIA : bool

**Méthodes :**
- Jeu(size_t nbJoueurs, int nbLignes, int nbColonnes, bool modeIA = false)
- jouerCoup(int colonne) : bool
- getPlateau() : Plateau&
- getJoueurCourant() const : const Joueur&
- estIAEnCours() const : bool
- choisirCoupIA() const : int
- passerAuJoueurSuivant() : void
  
#### Classe Plateau
**Attributs :**
- grille : vector<vector<char>>
- nbLignes : int
- nbColonnes : int

**Méthodes :**
- Plateau(int nbLignes, int nbColonnes)
- placerPion(int colonne, const Joueur& joueur) : bool
- estPleine() : bool
- estValideCoup(int colonne) : bool
- verifierAlignement(const Joueur& joueur) : bool
- afficherPlateau() : void
- getNbColonnes() : int

#### Classe Joueur
**Attributs :**
- nom : string
- couleur : char

**Méthodes :**
- Joueur(const string& nom, char couleur)
- getNom() : string
- getCouleur() : char

### Diagramme de classes

## Lancer le jeu "Puissance 5"

Pour démarrer le jeu, compilez et exécutez le fichier principal = > main.cpp
Vous serez invité à entrer le nombre de lignes et de colonnes pour la grille, ainsi que le mode de jeu (1 pour 1vsIA ou 0 pour 1vs1).


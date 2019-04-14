#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <QObject>
#include "paintwidget.h"
#include <QWidget>
#include <QLabel>
#include <QRadioButton>

class GameControl : public QObject
{
    Q_OBJECT
public:
    //constructeur
    explicit GameControl(PaintWidget* p = nullptr, QLabel* score = nullptr, QLabel* level = nullptr,
                         QLabel* lines = nullptr, QObject *parent = nullptr);

signals:

public slots:
    void incrementZ();      //slot appellé pour translater le tetramino dans le tableau
    void LeftRequest();     //Requete pour bouger le tetramino a gouche
    void RightRequest();    //Requete pour bouger le tetramino a droite
    void RotateRequest();   //Requete pour rotacioner le tetramino
    void Pause();           //Requete pour faire une pause dans le jeu
    void MoveSlowOrSpeed(); //Requete pour changer la vitesse du jeu

private:
    bool c;  
   int cubeWidth;                                                                           //Largeur de chaque case de la grille
   int grilleWidth;                                                                         //Largeur de la grille
   int grilleHeith;                                                                         //Hauteur de la grille
   int pauseTime_;                                                                          //variable pour stocker la vitesse du jeu
   int maxLine_;                                                                            //Ligne où se situe le dernière tetraminos(plus en haut) pour otimiser la recherche des lignes remplies
   std::vector<int> remplissage_;
   QTimer* timer;                                                                           //Variable pour appeller les foncions à chaque intervale
   PaintWidget* affichage;                                                                  //Variable responsable de l'affichage
   QLabel* score_, *level_, *lines_, *move_;                                                //Labels de l'interface à mettre à jour pour la classe GameControl
   std::vector<Tetramino> tetraminos_;                                                      //Vecteur de tetraminos existants
   std::vector<std::vector<cellule*> > cellules_;                                           //Tableu du jeu

   std::vector< std::vector<std::vector<std::tuple<int, int> > > > AllTetraminos_;          //Ensemble de toutes les tetraminos avec tous ses rotations possibles
   void createTetramino();                                                                  //Fonction pour créer un tetraminos
   void createAllTetraminos();                                                              //Fonction pour créer le tableu que stock toutes les tetraminos possibles à instancier
   void createGrille();                                                                     //Fonction pour créer la grille du jeu

   /*
     fonction qui permet de voir si un tetramino peut bouguer ou pas
   */
   bool canWeMoveDown();
   bool canWeMoveLeft();
   bool canWeMoveRight();
   bool canWeRotate();

   /*
     detecter la fin de la patie
   */
   bool endGame();

   /*
     recommencer la partie
   */
   void RestartGame();

   /*
      Cassé une ligne du tableau qui est remplie
    */
   void RemoveLine(int i);
   std::vector<QString> listeImage;
};

#endif // GAMECONTROL_H

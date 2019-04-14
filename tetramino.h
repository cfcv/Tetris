#ifndef TETRAMINO_H
#define TETRAMINO_H
#include "cellule.h"
#include <QColor>
#include <iostream>
#include<QDebug>

class Tetramino
{
public:
    Tetramino(std::vector<cellule> positions, std::vector< std::vector<std::tuple<int,int> > > rot, QColor c);
    void draw();                    //fonction qui dessine le tetramino
    void rollTetramino();           //fonction qui translate le tetramino vers le bas
    void moveLeft();                //fonction qui translate le tetramino vers la gauche
    void moveRight();               //fonction qui translate le tetramino ver la droite
    void Rotate();                  //fonction qui rotatione le tetramino
    //draw
private:
    QColor color_;                  //couleur du tetramino
    float translate_x ;             //sa translation de l'axe X par rapport au répere de la grille
    float translate_y; 
    float translate_z ;
    int current_rotation_;                                                      //rotation courant
    std::vector<cellule> tetramino_;                                            //son vector de 4 cellules
    std::vector< std::vector<std::tuple<int,int> > > rotations_;                //toutes les rotations possibles du tetramino

public:

    /*
      fonctions qui de translation
    */
    float getTranslateZ();
    float getTranslateX();
    float getTranslateY();
    void translateZ();
    void translateX(QString sens);
    void translateY();


    std::vector<std::tuple<int,int> > afterRotation();      //retourne les coordonnés aprés une rotation hipotetique pour utiliser dans la fonction canWeRotate()
    std::vector<cellule> getCellules();
};

#endif // TETRAMINO_H

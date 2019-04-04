#ifndef TETRAMINO_H
#define TETRAMINO_H
#include "cellule.h"
#include <QColor>
#include <iostream>
#include<QDebug>

class Tetramino
{
public:
    Tetramino(std::vector<cellule> positions, QColor c);
    void draw();
    void rollTetramino();
    void moveLeft();
    void moveRight();
    void Rotate();
    //draw
private:
    QColor color_;
    float translate_x ;
    float translate_y; // on ne vas peut-etre pas l'utiliser( a voir si on a le temps de faire des trucs)
    float translate_z ;
    std::vector<cellule> tetramino_;

public:
    float getTranslateZ();
    float getTranslateX();
    float getTranslateY();
    void translateZ();
    void translateX(QString sens);
    void translateY();
    std::vector<cellule> getCellules();
};

#endif // TETRAMINO_H

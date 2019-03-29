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
    //rotateRight
    //rotateLeft
    //Roll
    //draw
private:
    QColor color_;
    float translate_x = 0;
    float translate_y = 0;
    double translate_z ;
public:
    std::vector<cellule> tetramino_;
    double getTranslateZ();
    void translateZ();
};

#endif // TETRAMINO_H

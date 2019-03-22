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
public:
    std::vector<cellule> tetramino_;
};

#endif // TETRAMINO_H

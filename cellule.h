#ifndef CELLULE_H
#define CELLULE_H

#include<QColor>
#include<qdebug.h>
#include<QVector3D>
#include<iostream>
#include <QWidget>
#include <QGLWidget>
#include <QMouseEvent>
#include <QTimer>
#include <QVector>
#include <GL/glu.h>
#include <QColor>
#include <QOpenGLWidget>
#include<qopenglfunctions.h>
#include<iostream>
class cellule
{
public:
    cellule(QVector3D p1,QVector3D p2,QVector3D p3,QVector3D p4,int ligne,int colonne);

private:
    bool statue_;
    QColor color_;
    int ligne_;
    int colonne_;
    QVector3D center_;
    std::vector<QVector3D> coordinates_;
    float minX;
    float minZ;
    float planY;
    static float cubeWidth;

public:
    bool getStatue(){return  statue_;}
    void setStatue(bool b){statue_=b;}
    void setColor(QColor c){color_=c;}
    int getLigne(){return ligne_;}
    int getColonne(){return colonne_;}
    QVector3D getCenter(){return center_;}
    void rollLigne(){ligne_+=-1;}
    void moveLeft(){colonne_ -= 1;}
    void moveRight(){colonne_ += 1;}
    void rotate(float Xpivot, float Ypivot);
    std::vector<QVector3D> getCoordinates(){return  coordinates_;}
    void draw();

};


#endif // CELLULE_H

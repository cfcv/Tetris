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
    std::vector<QVector3D> coordinates_;

public:
    bool getStatue(){return  statue_;}
    void setStatue(bool b){statue_=b;}
    void setColor(QColor c){color_=c;}
    int getLigne(){return ligne_;}
    int getColonne(){return colonne_;}
    int rollLigne(){ligne_+=-1;}
    std::vector<QVector3D> getCoordinates(){return  coordinates_;}
    void draw();

};


#endif // CELLULE_H

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
    cellule(QVector3D p1,QVector3D p2,QVector3D p3,QVector3D p4);

private:
    bool statue_;
    QColor color_;
public:
    bool getStatue(){return  statue_;}
    void setStatue(bool b){statue_=b;}
    void setColor(QColor c){color_=c;}
    std::vector<QVector3D> coordinates_;
    void draw();
    //double coordinates_[4][3];
  //  std::vector<std::vector<double>> getCoordinates(){return coordinates_;}

   // double** getCoordinates(){return (coordinates_);}
};


#endif // CELLULE_H

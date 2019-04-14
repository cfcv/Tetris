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

    //--------------- Constructeur -----------------

    cellule(QVector3D p1,QVector3D p2,QVector3D p3,QVector3D p4,int ligne,int colonne);

private:

    //--------------- Variables qui pour representer une case de la grille -----------------
    bool statue_;
    QColor color_;
    int ligne_;
    int colonne_;
    QVector3D center_;
    std::vector<QVector3D> coordinates_;
    float minX;
    float minZ;
    float planY;

    //--------------- la taille de nos cub (case du grille) -----------------
    static float cubeWidth;

    //--------------- parametre qui represante la texture -----------------
    QString path;
    QImage texture_;
    GLuint m_TextureID ;

public:

    //--------------- definition des fonctions -----------------
    /*
      permet d'envoyer la statue(un boolean) de la grille (true si la case et occuper sinon false)
    */
    bool getStatue(){return  statue_;}

    /*
      permet de changer la statue de la case
    */
    void setStatue(bool b){statue_=b;}

    /*
      definire la color de la cellule
    */
    void setColor(QColor c){color_=c;}

    /*
      returne la couleur, ligne colonne, coordonner
    */
    QColor getColor(){return color_;}
    int getLigne(){return ligne_;}
    int getColonne(){return colonne_;}
     std::vector<QVector3D> getCoordinates(){return  coordinates_;}

    /*
      recuperer le centre d'un cellule
    */
    QVector3D getCenter(){return center_;}

    /*
      incrementer ou decremanter la ligne ou la colonne
    */
    void rollLigne(){ligne_+=-1;}
    void moveLeft(){colonne_ -= 1;}
    void moveRight(){colonne_ += 1;}
    void rotate(float Xpivot, float Ypivot);

    /*
      dessiner une case
    */
    void draw();

};


#endif // CELLULE_H

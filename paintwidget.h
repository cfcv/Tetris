#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <QMouseEvent>
#include <QTimer>
#include <QVector>
#include <GL/glu.h>
#include <QColor>
#include <QOpenGLWidget>
#include<qopenglfunctions.h>
#include"cellule.h"
#include<iostream>
#include"tetramino.h"
#include<QVector3D>
#include<QDebug>

class PaintWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget* parent = nullptr);

    /*
        Fonctions pour partager des variables entre les classes
    */
    void SetTetraminosVector(std::vector<Tetramino> &v);
    void setGrille(std::vector<std::vector<cellule*> > & grille);
    void setParametersGrille(int gW, int gH, int ml);
protected:
    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent * event);

public slots:
    void moveCircle(int);
private:
    int grilleWidth_;
    int grilleHeith_;
    int maxLine_;
    QTransform transform_;
    int centre_x = 150;
    int centre_y = 150;
    GLdouble translate_x=0;
    GLdouble translate_y=0;
    GLdouble translate_z=0;
   int width = 5; // default width of 5
    int    length = 5; // default length of 5
     int   height = 12; // default height of 12
    std::vector<std::vector<cellule*> > cellules_;
    std::vector<Tetramino> tetraminos_;
    Tetramino *t;
    double cubeWidth=10;

    /*
      fonction qui dessine la grille
    */
    void drawEnvironment();

    /*
      fonction qui dessine les tetraminos
    */
    void drawTetraminos();

    /*
      fonction qui creer les tetraminos
    */
    void creatTetramino();
};

#endif // PAINTWIDGET_H

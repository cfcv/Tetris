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
    void SetTetraminosVector(std::vector<Tetramino> &v);
    void setGrille(std::vector<std::vector<cellule*> > & grille);
protected:
   // void paintEvent(QPaintEvent* event);
    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();



public slots:
    void moveCircle(int);
private:
    QTransform transform_;
    int centre_x = 150;
    int centre_y = 150;
    GLdouble translate_x=0;
    GLdouble translate_y=0;
    GLdouble translate_z=0;
   int width = 5; // default width of 5
    int    length = 5; // default length of 5
     int   height = 12; // default height of 12
    //cellule *cellules_[15][9];
    std::vector<std::vector<cellule*> > cellules_;
    std::vector<Tetramino> tetraminos_;
    Tetramino *t;
    double cubeWidth=10;

    void drawEnvironment();
    void drawTetraminos();
    void creatTetramino();
};

#endif // PAINTWIDGET_H
































//void PaintWidget::drawCube(int ligne, int colonne)
//{
//    glClear(GL_DEPTH_BUFFER_BIT);

//    glLoadIdentity();
//    glTranslatef(0.0, 0.0, -35.0f);

//glBegin(GL_QUADS);
//glColor3ub(0, 0, 255);

// // face d'en bas
//glVertex3f(cellules_[ligne][colonne]->coordinates_[0].x(), cellules_[ligne][colonne]->coordinates_[0].y(), cellules_[ligne][colonne]->coordinates_[0].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[1].x(), cellules_[ligne][colonne]->coordinates_[1].y(), cellules_[ligne][colonne]->coordinates_[1].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[2].x(), cellules_[ligne][colonne]->coordinates_[2].y(), cellules_[ligne][colonne]->coordinates_[2].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[3].x(), cellules_[ligne][colonne]->coordinates_[3].y(), cellules_[ligne][colonne]->coordinates_[3].z());
// //face d'en haux
//glVertex3f(cellules_[ligne][colonne]->coordinates_[0].x(), cellules_[ligne][colonne]->coordinates_[0].y()+10, cellules_[ligne][colonne]->coordinates_[0].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[1].x(), cellules_[ligne][colonne]->coordinates_[1].y()+10, cellules_[ligne][colonne]->coordinates_[1].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[2].x(), cellules_[ligne][colonne]->coordinates_[2].y()+10, cellules_[ligne][colonne]->coordinates_[2].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[3].x(), cellules_[ligne][colonne]->coordinates_[3].y()+10, cellules_[ligne][colonne]->coordinates_[3].z());
//// face en face
//glVertex3f(cellules_[ligne][colonne]->coordinates_[0].x(), cellules_[ligne][colonne]->coordinates_[0].y()+10, cellules_[ligne][colonne]->coordinates_[0].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[1].x(), cellules_[ligne][colonne]->coordinates_[1].y(), cellules_[ligne][colonne]->coordinates_[1].z()+10);
//glVertex3f(cellules_[ligne][colonne]->coordinates_[2].x(), cellules_[ligne][colonne]->coordinates_[2].y(), cellules_[ligne][colonne]->coordinates_[2].z()+10);
//glVertex3f(cellules_[ligne][colonne]->coordinates_[3].x(), cellules_[ligne][colonne]->coordinates_[3].y()+10, cellules_[ligne][colonne]->coordinates_[3].z());
//// face derriere
//glVertex3f(cellules_[ligne][colonne]->coordinates_[0].x(), cellules_[ligne][colonne]->coordinates_[0].y()+10, cellules_[ligne][colonne]->coordinates_[0].z()-10);
//glVertex3f(cellules_[ligne][colonne]->coordinates_[1].x(), cellules_[ligne][colonne]->coordinates_[1].y(), cellules_[ligne][colonne]->coordinates_[1].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[2].x(), cellules_[ligne][colonne]->coordinates_[2].y(), cellules_[ligne][colonne]->coordinates_[2].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[3].x(), cellules_[ligne][colonne]->coordinates_[3].y()+10, cellules_[ligne][colonne]->coordinates_[3].z()-10);
//// face a gauche

//glVertex3f(cellules_[ligne][colonne]->coordinates_[1].x(), cellules_[ligne][colonne]->coordinates_[1].y()+10, cellules_[ligne][colonne]->coordinates_[1].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[0].x(), cellules_[ligne][colonne]->coordinates_[0].y()+10, cellules_[ligne][colonne]->coordinates_[0].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[0].x(), cellules_[ligne][colonne]->coordinates_[0].y(), cellules_[ligne][colonne]->coordinates_[0].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[1].x(), cellules_[ligne][colonne]->coordinates_[1].y(), cellules_[ligne][colonne]->coordinates_[1].z());
//// face a droite

//glVertex3f(cellules_[ligne][colonne]->coordinates_[1].x()+10, cellules_[ligne][colonne]->coordinates_[1].y()+10, cellules_[ligne][colonne]->coordinates_[1].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[0].x()+10, cellules_[ligne][colonne]->coordinates_[0].y()+10, cellules_[ligne][colonne]->coordinates_[0].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[0].x()+10, cellules_[ligne][colonne]->coordinates_[0].y(), cellules_[ligne][colonne]->coordinates_[0].z());
//glVertex3f(cellules_[ligne][colonne]->coordinates_[1].x()+10, cellules_[ligne][colonne]->coordinates_[1].y(), cellules_[ligne][colonne]->coordinates_[1].z());
////glColor3ub(255, 255, 0);

//glEnd();


//}

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

class PaintWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget* parent = nullptr);

protected:
   // void paintEvent(QPaintEvent* event);
    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent * event);
    void drawEnvironment(GLfloat cubeWidth);
  //  void Draw();
    void drawCube();




public slots:
    void moveCircle(int);
private:
    QTransform transform_;
    int centre_x = 150;
    int centre_y = 150;
   int width = 5; // default width of 5
    int    length = 5; // default length of 5
     int   height = 12; // default height of 12
    cellule *cellules_[15][9];

    // bool casesStatue[15][9];
    // cellule *cel=new cellule(0,0,0);
};

#endif // PAINTWIDGET_H

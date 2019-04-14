#include "paintwidget.h"
#include <QPainter>
#include <QDebug>
#include <QGLWidget>
#include<QColor>
#include <tuple>
#include <math.h>

// Declarations des constantes
const unsigned int WIN_WIDTH  = 1600;
const unsigned int WIN_HEIGHT = 900;
const float MAX_DIMENSION     = 50.0f;

PaintWidget::PaintWidget(QWidget* parent) : QOpenGLWidget(parent)
{


}

void PaintWidget::moveCircle(int direction){
    switch (direction) {
    case 1:
        centre_x+=2;
        break;
    case -1:
        centre_x-=2;
        break;
    default:
        break;

    }
    update();
    qDebug() << direction;
}

// Fonction d'initialisation
void PaintWidget::initializeGL()
{



//    // Reglage de la couleur de fond
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

//    // Activation du zbuffer
//    // ...
    glEnable(GL_DEPTH_TEST);


}
void PaintWidget::paintGL()
{
    // Reinitialisation des tampons

    glClear(GL_DEPTH_BUFFER_BIT  | GL_COLOR_BUFFER_BIT);

    drawEnvironment();
    drawTetraminos();
    //qDebug() << "Max line: " << maxLine_;
}
void PaintWidget::resizeGL(int width, int height)
{

    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
        gluPerspective(70, 1 , 1, 1000);
    gluLookAt(0.0, 60.0, -30.0, 0.0, -25.0, -90.0, 0, 1, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
void PaintWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        // Activation/Arret de l'animation
        case Qt::Key_Space:
        {


            break;
        }

        // Sortie de l'applicationa
        case Qt::Key_Escape:
        {
            exit(0);
        }

        // Cas par defaut
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
  //  updateGL();
}




void PaintWidget::drawEnvironment(){
   // glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT  | GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0, 0.0, -35.0f);

    std::vector<QVector3D> aux;
    for(int i = 0; i < grilleHeith_; i++){ // For each layer
            for(int j = 0; j < grilleWidth_; j++){ // top wall, 5 squares across
                if( (i+j) % 2)
                    glColor3f(0.0f, 0.0f, 0.0f);
                else
                    glColor3f(0.0f, 0.2f, 0.2f);
                aux = cellules_[i][j]->getCoordinates();
                glBegin(GL_QUADS);
                    glVertex3f(aux[0].x(), aux[0].y(), aux[0].z());
                    glVertex3f(aux[1].x(), aux[1].y(), aux[1].z());
                    glVertex3f(aux[2].x(), aux[2].y(), aux[2].z());
                    glVertex3f(aux[3].x(), aux[3].y(), aux[3].z());
                glEnd();
            }
    }
}


void PaintWidget::drawTetraminos(){


    glPushMatrix();
    glTranslated(tetraminos_.back().getTranslateX(),tetraminos_.back().getTranslateY(),tetraminos_.back().getTranslateZ());
    tetraminos_.back().draw();
    glPopMatrix();

    for(int i = 0; i <= maxLine_; i++){
        for(int j = 0; j < cellules_[i].size(); ++j){
            if(cellules_[i][j]->getStatue()){
                cellules_[i][j]->draw();
            }
        }
    }
    update();
}
void PaintWidget::creatTetramino(){


}


void PaintWidget::SetTetraminosVector(std::vector<Tetramino> &v){
    tetraminos_ = v;
}

void PaintWidget::setGrille(std::vector<std::vector<cellule*> > & grille){
    cellules_ = grille;
}

void PaintWidget::setParametersGrille(int gW, int gH, int ml){
    grilleHeith_ = gH;
    grilleWidth_ = gW;
    maxLine_ = ml;
}

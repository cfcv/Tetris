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

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(incrementZ()));
    timer->start(1000); //milisecondes
  //  setFixedSize(WIN_WIDTH, WIN_HEIGHT);
//    for (int i=0;i<15;i++)
//        for(int j=0;j<9;j++)
//            //cellules[i][j]=new cellule(0,0,0);
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
    for(int i = 0; i < 15; i++) // For each layer
    {
    for(int j = 0; j < 9; j++) // top wall, 5 squares across
    {

        QVector3D p1(-(cubeWidth * 4.5) + cubeWidth*j,-(cubeWidth * 2.5),0.0 - cubeWidth*i);
        QVector3D p2(-(cubeWidth * 4.5) + cubeWidth*j,-(cubeWidth * 2.5),-cubeWidth - cubeWidth*i);
        QVector3D p3(-(cubeWidth * 3.5) + cubeWidth*j,-(cubeWidth * 2.5),-cubeWidth - cubeWidth*i);
        QVector3D p4(-(cubeWidth * 3.5) + cubeWidth*j,-(cubeWidth * 2.5),0.0 - cubeWidth*i);



    cellules_[i][j]=new cellule(p1,p2,p3,p4);

    }

    }
    creatTetramino();
    // QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();


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

    drawEnvironment(10);
    glLoadIdentity();
    glTranslated(translate_x,translate_y,translate_z);
    for(int i=0;i<t->tetramino_.size();i++)
    t->tetramino_[i].draw();
}
void PaintWidget::resizeGL(int width, int height)
{

    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
        gluPerspective(70, width/height , 1, 1000);

       // glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width), MAX_DIMENSION * height / static_cast<float>(width), -MAX_DIMENSION * 2.0f, MAX_DIMENSION * 2.0f);

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

        // Sortie de l'application
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




void PaintWidget::drawEnvironment(GLfloat cubeWidth)
{
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//glClear(GL_COLOR_BUFFER_BIT);
glClear(GL_DEPTH_BUFFER_BIT  | GL_COLOR_BUFFER_BIT);

glLoadIdentity();
int count = 0;
glTranslatef(0.0, 0.0, -35.0f);
for(int i = 0; i < 15; i++) // For each layer
{
for(int j = 0; j < 9; j++) // top wall, 5 squares across
{
    if( count % 2)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.0f, 0.2f, 0.2f);
    count++;
    glBegin(GL_QUADS);
        glVertex3f(-(cubeWidth * 4.5) + cubeWidth*j, -(cubeWidth * 2.5), 0.0 - cubeWidth*i);
        glVertex3f(-(cubeWidth * 4.5) + cubeWidth*j, -(cubeWidth * 2.5), -cubeWidth - cubeWidth*i);
        glVertex3f(-(cubeWidth * 3.5) + cubeWidth*j, -(cubeWidth * 2.5), -cubeWidth - cubeWidth*i);
        glVertex3f(-(cubeWidth * 3.5) + cubeWidth*j, -(cubeWidth * 2.5), 0.0 - cubeWidth*i);
    glEnd();


}

}

}


void PaintWidget::creatTetramino(){
    int ligneInit=12;
    int colloneInit=5;
    std::vector<cellule> cellules;
       cellule c1( cellules_[12][5]->getCoordinates()[0],cellules_[12][5]->getCoordinates()[1],cellules_[12][5]->getCoordinates()[2],cellules_[12][5]->getCoordinates()[3]) ;
       c1.setStatue(true);
    cellules.push_back(c1);
      QColor c(255,255,255);
      std::vector<std::tuple<int, int>> possibilites;
      possibilites.push_back(std::tuple<int, int>(12, 4));
      possibilites.push_back(std::tuple<int, int>(12, 6));
      possibilites.push_back(std::tuple<int, int>(11, 5));
      possibilites.push_back(std::tuple<int, int>(13, 5));

      std::vector<std::tuple<int, int>> already_taken;
      already_taken.push_back(std::tuple<int, int>(12,5));

      for(int i = 0; i < 3; i++){
          int r = rand()%possibilites.size();
          std::tuple<int, int> choice = possibilites[r];
          int ligne = std::get<0>(choice);
          int colone = std::get<1>(choice);
          possibilites.erase(possibilites.begin()+r);
          cellules.push_back(cellule(cellules_[ligne][colone]->getCoordinates()[0],cellules_[ligne][colone]->getCoordinates()[1],cellules_[ligne][colone]->getCoordinates()[2],cellules_[ligne][colone]->getCoordinates()[3]));
          already_taken.push_back(choice);
          //add new neigbohoods
           for(int j = 0; j < 4; j++){
              int activation = (j > 1) ? 1 : 0;
              std::tuple<int, int> t(ligne+(pow(-1, j)*activation),colone+(pow(-1, j)*((activation+1)%2)));
              if(std::find(already_taken.begin(), already_taken.end(), t) != already_taken.end()){
                  possibilites.push_back(t);
              }
           }
      }
    //  qDebug()<<"je suis a la fin";
      t=new Tetramino(cellules,c);

      // tetraminos_.push_back(c1, QColor c(255,255,255));

}
void PaintWidget::incrementZ()
{
    translate_z+=10;
    update();
}

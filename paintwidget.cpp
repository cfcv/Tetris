#include "paintwidget.h"
#include <QPainter>
#include <QDebug>
#include <QGLWidget>

// Declarations des constantes
const unsigned int WIN_WIDTH  = 1600;
const unsigned int WIN_HEIGHT = 900;
const float MAX_DIMENSION     = 50.0f;

PaintWidget::PaintWidget(QWidget* parent) : QOpenGLWidget(parent)
{
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
  //  glTranslatef(0.0, 0.0, -35.0f);

    drawCube();
   // Draw();


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
    double tab1[3];
    double tab2[3];
    double tab3[3];
    double tab4[3];
    tab1[0]=-(cubeWidth * 4.5) + cubeWidth*j;
    tab1[1]= -(cubeWidth * 2.5);
    tab1[2]=0.0 - cubeWidth*i;

    tab2[0]=-(cubeWidth * 4.5) + cubeWidth*j;
    tab2[1]= -(cubeWidth * 2.5);
    tab2[2]=-cubeWidth - cubeWidth*i;

    tab3[0]=-(cubeWidth * 3.5) + cubeWidth*j;
    tab3[1]= -(cubeWidth * 2.5);
    tab3[2]=-cubeWidth - cubeWidth*i;

    tab4[0]=-(cubeWidth * 3.5) + cubeWidth*j;
    tab4[1]= -(cubeWidth * 2.5);
    tab4[2]=0.0 - cubeWidth*i;

cellules_[i][j]=new cellule(tab1,tab2,tab3,tab4);

}

}

}
void PaintWidget::drawCube()
{
    glClear(GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0, 0.0, -35.0f);

glBegin(GL_QUADS);
glColor3ub(0, 0, 255); // face d'en bas
glVertex3f(cellules_[2][2]->coordinates_[0][0], cellules_[2][2]->coordinates_[0][1], cellules_[2][2]->coordinates_[0][2]);
glVertex3f(cellules_[2][2]->coordinates_[1][0], cellules_[2][2]->coordinates_[1][1], cellules_[2][2]->coordinates_[1][2]);
glVertex3f(cellules_[2][2]->coordinates_[2][0], cellules_[2][2]->coordinates_[2][1], cellules_[2][2]->coordinates_[2][2]);
glVertex3f(cellules_[2][2]->coordinates_[3][0], cellules_[2][2]->coordinates_[3][1], cellules_[2][2]->coordinates_[3][2]);
glColor3ub(0, 0, 255); //face d'en haux
glVertex3f(cellules_[2][2]->coordinates_[0][0], cellules_[2][2]->coordinates_[0][1]+10, cellules_[2][2]->coordinates_[0][2]);
glVertex3f(cellules_[2][2]->coordinates_[1][0], cellules_[2][2]->coordinates_[1][1]+10, cellules_[2][2]->coordinates_[1][2]);
glVertex3f(cellules_[2][2]->coordinates_[2][0], cellules_[2][2]->coordinates_[2][1]+10, cellules_[2][2]->coordinates_[2][2]);
glVertex3f(cellules_[2][2]->coordinates_[3][0], cellules_[2][2]->coordinates_[3][1]+10, cellules_[2][2]->coordinates_[3][2]);
//glColor3ub(0, 0, 255);// face en face
//glVertex3f(cellules_[2][2]->coordinates_[0][0], cellules_[2][2]->coordinates_[0][1]+10, cellules_[2][2]->coordinates_[0][2]);
//glVertex3f(cellules_[2][2]->coordinates_[1][0], cellules_[2][2]->coordinates_[1][1], cellules_[2][2]->coordinates_[1][2]+10);
//glVertex3f(cellules_[2][2]->coordinates_[2][0], cellules_[2][2]->coordinates_[2][1], cellules_[2][2]->coordinates_[2][2]+10);
//glVertex3f(cellules_[2][2]->coordinates_[3][0], cellules_[2][2]->coordinates_[3][1]+10, cellules_[2][2]->coordinates_[3][2]);
glColor3ub(255, 0, 255);// face derriere
glVertex3f(cellules_[2][2]->coordinates_[0][0], cellules_[2][2]->coordinates_[0][1]+10, cellules_[2][2]->coordinates_[0][2]-10);
glVertex3f(cellules_[2][2]->coordinates_[1][0], cellules_[2][2]->coordinates_[1][1], cellules_[2][2]->coordinates_[1][2]);
glVertex3f(cellules_[2][2]->coordinates_[2][0], cellules_[2][2]->coordinates_[2][1], cellules_[2][2]->coordinates_[2][2]);
glVertex3f(cellules_[2][2]->coordinates_[3][0], cellules_[2][2]->coordinates_[3][1]+10, cellules_[2][2]->coordinates_[3][2]-10);
glColor3ub(255, 0, 0);// face a droite

glVertex3f(cellules_[2][2]->coordinates_[1][0], cellules_[2][2]->coordinates_[1][1]+10, cellules_[2][2]->coordinates_[1][2]);
glVertex3f(cellules_[2][2]->coordinates_[0][0], cellules_[2][2]->coordinates_[0][1]+10, cellules_[2][2]->coordinates_[0][2]);

glVertex3f(cellules_[2][2]->coordinates_[0][0], cellules_[2][2]->coordinates_[0][1], cellules_[2][2]->coordinates_[0][2]);
glVertex3f(cellules_[2][2]->coordinates_[1][0], cellules_[2][2]->coordinates_[1][1], cellules_[2][2]->coordinates_[1][2]);
//glColor3ub(255, 255, 0);
//glVertex3f(3.0f, 3.0f, -7.0f);
//glVertex3f(3.0f, 3.0f, -5.0f);
//glVertex3f(3.0f, 1.0f, -5.0f);
//glVertex3f(3.0f, 1.0f, -7.0f);
glEnd();


}


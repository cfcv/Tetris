#include "cellule.h"

cellule::cellule(QVector3D p1,QVector3D p2,QVector3D p3,QVector3D p4)
{                           
            coordinates_.push_back(p1);
            coordinates_.push_back(p2);
            coordinates_.push_back(p3);
            coordinates_.push_back(p4);           
            statue_=true;
}
void cellule::draw()
{
    glClear(GL_DEPTH_BUFFER_BIT);

    //glLoadIdentity();
    //glTranslatef(0.0, 0.0, -35.0f);
    glBegin(GL_QUADS);
   // glColor3ub(0, 0, 255);

     // face d'en bas
    glVertex3f(  coordinates_[0].x(),   coordinates_[0].y(),   coordinates_[0].z());
    glVertex3f(  coordinates_[1].x(),   coordinates_[1].y(),   coordinates_[1].z());
    glVertex3f(  coordinates_[2].x(),   coordinates_[2].y(),   coordinates_[2].z());
    glVertex3f(  coordinates_[3].x(),   coordinates_[3].y(),   coordinates_[3].z());
     //face d'en haux
    glVertex3f(  coordinates_[0].x(),   coordinates_[0].y()+10,   coordinates_[0].z());
    glVertex3f(  coordinates_[1].x(),   coordinates_[1].y()+10,   coordinates_[1].z());
    glVertex3f(  coordinates_[2].x(),   coordinates_[2].y()+10,   coordinates_[2].z());
    glVertex3f(  coordinates_[3].x(),   coordinates_[3].y()+10,   coordinates_[3].z());
    // face en face
    glVertex3f(  coordinates_[0].x(),   coordinates_[0].y()+10,   coordinates_[0].z());
    glVertex3f(  coordinates_[1].x(),   coordinates_[1].y(),   coordinates_[1].z()+10);
    glVertex3f(  coordinates_[2].x(),   coordinates_[2].y(),   coordinates_[2].z()+10);
    glVertex3f(  coordinates_[3].x(),   coordinates_[3].y()+10,   coordinates_[3].z());
    // face derriere
    glVertex3f(  coordinates_[0].x(),   coordinates_[0].y()+10,   coordinates_[0].z()-10);
    glVertex3f(  coordinates_[1].x(),   coordinates_[1].y(),   coordinates_[1].z());
    glVertex3f(  coordinates_[2].x(),   coordinates_[2].y(),   coordinates_[2].z());
    glVertex3f(  coordinates_[3].x(),   coordinates_[3].y()+10,   coordinates_[3].z()-10);
    // face a gauche

    glVertex3f(  coordinates_[1].x(),   coordinates_[1].y()+10,   coordinates_[1].z());
    glVertex3f(  coordinates_[0].x(),   coordinates_[0].y()+10,   coordinates_[0].z());
    glVertex3f(  coordinates_[0].x(),   coordinates_[0].y(),   coordinates_[0].z());
    glVertex3f(  coordinates_[1].x(),   coordinates_[1].y(),   coordinates_[1].z());
    // face a droite

    glVertex3f(  coordinates_[1].x()+10,   coordinates_[1].y()+10,   coordinates_[1].z());
    glVertex3f(  coordinates_[0].x()+10,   coordinates_[0].y()+10,   coordinates_[0].z());
    glVertex3f(  coordinates_[0].x()+10,   coordinates_[0].y(),   coordinates_[0].z());
    glVertex3f(  coordinates_[1].x()+10,   coordinates_[1].y(),   coordinates_[1].z());
    //glColor3ub(255, 255, 0);

    glEnd();
}

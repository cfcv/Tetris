#include "cellule.h"

cellule::cellule(QVector3D p1,QVector3D p2,QVector3D p3,QVector3D p4,int ligne,int colonnes)
{                           
            coordinates_.push_back(p1);
            coordinates_.push_back(p2);
            coordinates_.push_back(p3);
            coordinates_.push_back(p4);           
            statue_=false;
            ligne_=ligne;
            colonne_=colonnes;

}
void cellule::draw(QImage texture_)
{

    glClear(GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
   // QImage texture_;
    GLuint m_TextureID ;
    //texture_=QGLWidget::convertToGLFormat(QImage(texture));
    glGenTextures( 1, &m_TextureID );
    glBindTexture( GL_TEXTURE_2D, m_TextureID );
    // Transmet à OpenGL toutes les caractéristiques de la texture courante : largeur, hauteur, format, etc... et bien sûr l'image
    glTexImage2D( GL_TEXTURE_2D, 0, 4, texture_.width(),texture_.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture_.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glLoadIdentity();
    //glTranslatef(0.0, 0.0, -35.0f);
    glBindTexture( GL_TEXTURE_2D, m_TextureID );

    glBegin(GL_QUADS);
   // glColor3ub(0, 0, 255);

     // face d'en bas
   glTexCoord2d(0,1); glVertex3f(  coordinates_[0].x(),   coordinates_[0].y(),   coordinates_[0].z());
   glTexCoord2d(0,0);glVertex3f(  coordinates_[1].x(),   coordinates_[1].y(),   coordinates_[1].z());
   glTexCoord2d(1,0); glVertex3f(  coordinates_[2].x(),   coordinates_[2].y(),   coordinates_[2].z());
   glTexCoord2d(1,1); glVertex3f(  coordinates_[3].x(),   coordinates_[3].y(),   coordinates_[3].z());
     //face d'en haux
    glTexCoord2d(0,1);glVertex3f(  coordinates_[0].x(),   coordinates_[0].y()+10,   coordinates_[0].z());
    glTexCoord2d(0,0);glVertex3f(  coordinates_[1].x(),   coordinates_[1].y()+10,   coordinates_[1].z());
    glTexCoord2d(1,0);glVertex3f(  coordinates_[2].x(),   coordinates_[2].y()+10,   coordinates_[2].z());
    glTexCoord2d(1,1);glVertex3f(  coordinates_[3].x(),   coordinates_[3].y()+10,   coordinates_[3].z());
    // face en face
    glTexCoord2d(0,1);glVertex3f(  coordinates_[0].x(),   coordinates_[0].y()+10,   coordinates_[0].z());
    glTexCoord2d(0,0);glVertex3f(  coordinates_[1].x(),   coordinates_[1].y(),   coordinates_[1].z()+10);
    glTexCoord2d(1,0);glVertex3f(  coordinates_[2].x(),   coordinates_[2].y(),   coordinates_[2].z()+10);
    glTexCoord2d(1,1); glVertex3f(  coordinates_[3].x(),   coordinates_[3].y()+10,   coordinates_[3].z());
    // face derriere
    glTexCoord2d(0,1);glVertex3f(  coordinates_[0].x(),   coordinates_[0].y()+10,   coordinates_[0].z()-10);
    glTexCoord2d(0,0);glVertex3f(  coordinates_[1].x(),   coordinates_[1].y(),   coordinates_[1].z());
    glTexCoord2d(1,0);glVertex3f(  coordinates_[2].x(),   coordinates_[2].y(),   coordinates_[2].z());
    glTexCoord2d(1,1);glVertex3f(  coordinates_[3].x(),   coordinates_[3].y()+10,   coordinates_[3].z()-10);
    // face a gauche

    glTexCoord2d(0,1);glVertex3f(  coordinates_[1].x(),   coordinates_[1].y()+10,   coordinates_[1].z());
    glTexCoord2d(0,0);glVertex3f(  coordinates_[0].x(),   coordinates_[0].y()+10,   coordinates_[0].z());
    glTexCoord2d(1,0);glVertex3f(  coordinates_[0].x(),   coordinates_[0].y(),   coordinates_[0].z());
    glTexCoord2d(1,1);glVertex3f(  coordinates_[1].x(),   coordinates_[1].y(),   coordinates_[1].z());
    // face a droite

    glTexCoord2d(0,1);glVertex3f(  coordinates_[1].x()+10,   coordinates_[1].y()+10,   coordinates_[1].z());
    glTexCoord2d(0,0);glVertex3f(  coordinates_[0].x()+10,   coordinates_[0].y()+10,   coordinates_[0].z());
    glTexCoord2d(1,0);glVertex3f(  coordinates_[0].x()+10,   coordinates_[0].y(),   coordinates_[0].z());
    glTexCoord2d(1,1);glVertex3f(  coordinates_[1].x()+10,   coordinates_[1].y(),   coordinates_[1].z());
    //glColor3ub(255, 255, 0);

    glEnd();
//       glDeleteTextures(1,&m_TextureID);
glDisable(GL_TEXTURE_2D);
}

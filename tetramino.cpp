#include "tetramino.h"
#include <QTimer>

Tetramino::Tetramino(std::vector<cellule> positions, QColor c,QString  I):color_(c),tetramino_(positions)
{
 //   qDebug()<< "le nom de la texture: "<<I;
texture_=QGLWidget::convertToGLFormat(QImage(I));

//glGenTextures( 1, &m_TextureID );



translate_z = 0;
translate_x = 0;
translate_y = 0;
}
void Tetramino::draw(){
//system("pause");
  //  glBindTexture( GL_TEXTURE_2D, *m_TextureID );
     glColor3ub(255, 255, 255);

    for(int i=0;i<tetramino_.size();i++)
    {
        tetramino_[i].draw(texture_);
    }
//    glDeleteTextures(1,m_TextureID);
}

float Tetramino::getTranslateZ(){
    return translate_z;
}

void Tetramino::translateZ(){
    translate_z += 10;
}
std::vector<cellule> Tetramino::getCellules()
{
    return tetramino_;
}

float Tetramino::getTranslateX(){return translate_x;}
float Tetramino::getTranslateY(){return translate_y;}
void Tetramino::translateX(QString sens)
{
   translate_x+=(sens=="gauche")?-10:10;
}
void Tetramino::translateY()
{
    translate_y+=10;
}

void Tetramino::rollTetramino(){
    for(std::vector<cellule>::iterator itc = tetramino_.begin(); itc != tetramino_.end(); ++itc){
        itc->rollLigne();
    }
}

void Tetramino::moveLeft(){
    translate_x -= 10;
    for(std::vector<cellule>::iterator itc = tetramino_.begin(); itc != tetramino_.end(); ++itc){
        itc->moveLeft();
    }
}

void Tetramino::moveRight(){
    translate_x += 10;
    for(std::vector<cellule>::iterator itc = tetramino_.begin(); itc != tetramino_.end(); ++itc){
        itc->moveRight();
    }
}

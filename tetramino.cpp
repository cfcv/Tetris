#include "tetramino.h"
#include <QTimer>

Tetramino::Tetramino(std::vector<cellule> positions, QColor c,QString  I):color_(c),tetramino_(positions)
{
texture_=QGLWidget::convertToGLFormat(QImage(I));

translate_z = 0;
translate_x = 0;
translate_y = 0;
}
void Tetramino::draw(){

     glColor3ub(255, 255, 255);
//     glClear(GL_COLOR_BUFFER_BIT);

    for(std::vector<cellule>::iterator it=tetramino_.begin();it!=tetramino_.end();++it)
    {
        it->draw(texture_);
    }
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

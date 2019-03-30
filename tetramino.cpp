#include "tetramino.h"
#include <QTimer>

Tetramino::Tetramino(std::vector<cellule> positions, QColor c):color_(c),tetramino_(positions)
{

translate_z = 0;
translate_x = 0;
translate_y = 0;
}
void Tetramino::draw(){
//system("pause");

    for(int i=0;i<tetramino_.size();i++)
    {
        glColor3ub(color_.red(), color_.green(), color_.blue());
        tetramino_[i].draw();
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

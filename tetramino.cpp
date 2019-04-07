#include "tetramino.h"
#include <QTimer>

Tetramino::Tetramino(std::vector<cellule> positions,  std::vector< std::vector<std::tuple<int,int> > > rot, QColor c)
    :color_(c),tetramino_(positions), rotations_(rot)
{
    current_rotation_ = 0;
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

std::vector<std::tuple<int,int> > Tetramino::afterRotation(){
    std::vector<std::tuple<int,int> > AR;
    //AR.push_back(std::tuple<int,int>(tetramino_[0].getLigne(), tetramino_[0].getColonne()));
    for(int i = 1; i < tetramino_.size(); i++){
        int ligne = tetramino_[0].getLigne() + std::get<0>(rotations_[0][((current_rotation_+1)*3)+i-1]);
        int colum = tetramino_[0].getColonne() + std::get<1>(rotations_[0][((current_rotation_+1)*3)+i-1]);
        AR.push_back(std::tuple<int,int>(ligne, colum));
    }

    return AR;
}

void Tetramino::Rotate(){
    current_rotation_ += 1;
    current_rotation_ %= 4;
    //qDebug() << "current position: " << tetramino_[0].getLigne() << tetramino_[0].getColonne();
    //qDebug() << "new position: " << tetramino_[0].getLigne() << tetramino_[0].getColonne();
    //qDebug() << tetramino_.size();
    //qDebug() << std::get<0>(rotations_[0][(current_rotation_*3)]);
    for(int i = 1; i < tetramino_.size(); i++){
        tetramino_[i].rotate(tetramino_[0].getLigne() + std::get<0>(rotations_[0][(current_rotation_*3)+i-1]), tetramino_[0].getColonne() + std::get<1>(rotations_[0][(current_rotation_*3)+i-1]));
    }
    return;
    //qDebug() << "PIVOT: ";
    std::vector<QVector3D> aux = tetramino_[0].getCoordinates();
    //qDebug() << aux[0].x() << " " << aux[0].y() << " " << aux[0].z();
    //qDebug() << aux[1].x() << " " << aux[1].y() << " " << aux[1].z();
    //qDebug() << aux[2].x() << " " << aux[2].y() << " " << aux[2].z();
    //qDebug() << aux[3].x() << " " << aux[3].y() << " " << aux[3].z();
    //float sum = aux[0].x() + aux[1].x() + aux[2].x() + aux[3].x();
    //qDebug() << "result" << sum/4.0;
    QVector3D pivot = tetramino_[0].getCenter();
    //qDebug() << "Point pivot: " << pivot.x() << " " << pivot.y() << " " << pivot.z();
    for(int i = 0; i < tetramino_.size(); ++i){
        //qDebug() << "Cellule " << i;
        tetramino_[i].rotate(pivot.x(), pivot.z());
    }
}

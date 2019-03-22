#include "tetramino.h"

Tetramino::Tetramino(std::vector<cellule> positions, QColor c):color_(c),tetramino_(positions)
{
//    color_=c;
//    for (int i=0;i<positions.size();i++)
//        tetramino_.push_back(positions[i]);
   // tetramino_=positions;
}
void Tetramino::draw(){
    qDebug()<<tetramino_.size();
//system("pause");
    for(int i=0;i<tetramino_.size();i++)
        tetramino_[0].draw();
}

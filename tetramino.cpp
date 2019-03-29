#include "tetramino.h"
#include <QTimer>

Tetramino::Tetramino(std::vector<cellule> positions, QColor c):color_(c),tetramino_(positions)
{

translate_z = 0;
//    color_=c;
//    for (int i=0;i<positions.size();i++)
//        tetramino_.push_back(positions[i]);
   // tetramino_=positions;
}
void Tetramino::draw(){
//system("pause");

    for(int i=0;i<tetramino_.size();i++)
    {
        glColor3ub(color_.red(), color_.green(), color_.blue());

        tetramino_[i].draw();
    }
}


double Tetramino::getTranslateZ(){
    return translate_z;
}

void Tetramino::translateZ(){
    translate_z += 10;
}

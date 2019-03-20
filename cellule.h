#ifndef CELLULE_H
#define CELLULE_H

#include<QColor>
#include<qdebug.h>

class cellule
{
public:
    cellule(double c1[],double c2[],double c3[],double c4[]);

private:

    bool statue_;
    QColor color_;
public:
    bool getStatue(){return  statue_;}
    void setStatue(bool b){statue_=b;}
    void setColor(QColor c){color_=c;}
    double coordinates_[4][3];
  //  std::vector<std::vector<double>> getCoordinates(){return coordinates_;}

   // double** getCoordinates(){return (coordinates_);}
};


#endif // CELLULE_H

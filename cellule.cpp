#include "cellule.h"

cellule::cellule(double c1[],double c2[],double c3[],double c4[])
{
        for(int j=0;j<3;j++)
            coordinates_[0][j]=c1[j];
        for(int j=0;j<3;j++)
            coordinates_[1][j]=c2[j];
        for(int j=0;j<3;j++)
            coordinates_[2][j]=c3[j];
        for(int j=0;j<3;j++)
            coordinates_[3][j]=c4[j];

    statue_=false;
}

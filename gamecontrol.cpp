#include "gamecontrol.h"
#include<math.h>
#include <QTimer>

GameControl::GameControl(PaintWidget* p, QObject *parent) : QObject(parent),affichage(p)
{

    QTimer* timer2 = new QTimer(this);
       connect(timer2, SIGNAL(timeout()), this, SLOT(incrementZ()));
       timer2->start(1000); //milisecondes
       createGrille();
           affichage->setGrille(cellules_);

           createTetramino();
           srand(time(NULL));
           affichage->SetTetraminosVector(tetraminos_);
}

void GameControl::incrementZ(){
    if(!tetraminos_.empty())
            tetraminos_.back().translateZ();
      //  qDebug()<<tetraminos_.back().getTranslateZ();
}

void GameControl::createGrille(){
    int cubeWidth = 10;
    cellules_.resize(15);
    for(int i = 0; i < 15; i++){ // For each layer
        cellules_[i].resize(9);
        for(int j = 0; j < 9; j++){ // top wall, 5 squares across
            QVector3D p1(-(cubeWidth * 4.5) + cubeWidth*j,-(cubeWidth * 2.5),0.0 - cubeWidth*i);
            QVector3D p2(-(cubeWidth * 4.5) + cubeWidth*j,-(cubeWidth * 2.5),-cubeWidth - cubeWidth*i);
            QVector3D p3(-(cubeWidth * 3.5) + cubeWidth*j,-(cubeWidth * 2.5),-cubeWidth - cubeWidth*i);
            QVector3D p4(-(cubeWidth * 3.5) + cubeWidth*j,-(cubeWidth * 2.5),0.0 - cubeWidth*i);

            cellules_[i][j] = new cellule(p1,p2,p3,p4);
        }
    }
}
void GameControl::createTetramino(){
    srand(time(NULL));
    // gestion couleurs
        // nous allons definir des couleurs bien connue
        std::vector<int> listeColor;
        listeColor.push_back(255);
        listeColor.push_back(192);
        listeColor.push_back(128);
        int value=listeColor[rand()%3];
        int rgb[3];

        rgb[rand()%3]=value;
        for(int i=0;i<3;i++)
        {
            if(rgb[i]!=value)
                rgb[i]=(rand()%2==1)? value : 0;
        }
        QColor c(rgb[0],rgb[1],rgb[2]);


    int ligneInit=12;
    int colloneInit=5;
    std::vector<cellule> cellules;
    cellule c1( cellules_[ligneInit][colloneInit]->getCoordinates()[0],cellules_[ligneInit][colloneInit]->getCoordinates()[1],cellules_[ligneInit][colloneInit]->getCoordinates()[2],cellules_[ligneInit][colloneInit]->getCoordinates()[3]) ;
    //c1.setStatue(true);
    cellules.push_back(c1);
   // QColor c(255,255,255);
    std::vector<std::tuple<int, int>> possibilites;
    possibilites.push_back(std::tuple<int, int>(12, 4));
    possibilites.push_back(std::tuple<int, int>(12, 6));
    possibilites.push_back(std::tuple<int, int>(11, 5));
    possibilites.push_back(std::tuple<int, int>(13, 5));

    std::vector<std::tuple<int, int>> already_taken;
    already_taken.push_back(std::tuple<int, int>(12,5));


    for(int i = 0; i < 3; i++){
      int r = rand()%possibilites.size();
      std::tuple<int, int> choice = possibilites[r];
      int ligne = std::get<0>(choice);
      int colone = std::get<1>(choice);
      possibilites.erase(possibilites.begin()+r);
      cellules.push_back(cellule(cellules_[ligne][colone]->getCoordinates()[0],cellules_[ligne][colone]->getCoordinates()[1],cellules_[ligne][colone]->getCoordinates()[2],cellules_[ligne][colone]->getCoordinates()[3]));
      already_taken.push_back(choice);
      //add new neigbohoods
       for(int j = 0; j < 4; j++){
          int activation = (j > 1) ? 1 : 0;
          std::tuple<int, int> t(ligne+(pow(-1, j)*activation),colone+(pow(-1, j)*((activation+1)%2)));
          if(std::find(already_taken.begin(), already_taken.end(), t) != already_taken.end()){
              possibilites.push_back(t);
          }
       }
    }
    tetraminos_.push_back(Tetramino(cellules,c));

}

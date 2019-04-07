#include "gamecontrol.h"
#include<math.h>
#include <QTimer>

GameControl::GameControl(PaintWidget* p, QObject *parent) : QObject(parent),affichage(p)
{
    cubeWidth=10;
    grilleWidth=10;
    grilleHeith=20;
    pauseTime_ = 1000;
    QTimer* timer2 = new QTimer(this);
       connect(timer2, SIGNAL(timeout()), this, SLOT(incrementZ()));
       timer2->start(pauseTime_); //milisecondes
       createAllTetraminos();
       createGrille();
       affichage->setParametersGrille(grilleWidth, grilleHeith);
       affichage->setGrille(cellules_);

           createTetramino();
           srand(time(NULL));
           affichage->SetTetraminosVector(tetraminos_);
    c = true;
}
float GameControl::getZmax()
{
    std::vector<cellule> cellules=tetraminos_.back().getCellules();
    float Max=cellules.begin()->getCoordinates().begin()->z();
    for(std::vector<cellule>::iterator itr=cellules.begin();itr!=cellules.end();++itr)
    {
        std::vector<QVector3D> coordinates=itr->getCoordinates();
        float max=coordinates.begin()->z();
        for (std::vector<QVector3D>::iterator it = coordinates.begin() ; it != coordinates.end(); ++it)
        {
          max=(max<it->z())? it->z():max;
        }
        Max=(Max<max)? max:Max;

    }
    return Max;
}

/* Fonction que crée et stock toutes les
 * tetraminos possibles et ses rotations
 */
void GameControl::createAllTetraminos(){
    // - - - -
    std::vector<std::tuple<int,int> > aux_line_1;
    aux_line_1.push_back(std::tuple<int, int>(0,-1));
    aux_line_1.push_back(std::tuple<int, int>(0,1));
    aux_line_1.push_back(std::tuple<int, int>(0,2));

    std::vector<std::tuple<int,int> > aux_line_2;
    aux_line_1.push_back(std::tuple<int, int>(1,0));
    aux_line_1.push_back(std::tuple<int, int>(-1,0));
    aux_line_1.push_back(std::tuple<int, int>(-2,0));

    std::vector<std::tuple<int,int> > aux_line_3;
    aux_line_1.push_back(std::tuple<int, int>(0,1));
    aux_line_1.push_back(std::tuple<int, int>(0,-1));
    aux_line_1.push_back(std::tuple<int, int>(0,-2));

    std::vector<std::tuple<int,int> > aux_line_4;
    aux_line_1.push_back(std::tuple<int, int>(1,0));
    aux_line_1.push_back(std::tuple<int, int>(-1,0));
    aux_line_1.push_back(std::tuple<int, int>(-2,0));

    std::vector< std::vector< std::tuple<int,int> > > aux_line_matrix;
    aux_line_matrix.push_back(aux_line_1);
    aux_line_matrix.push_back(aux_line_2);
    aux_line_matrix.push_back(aux_line_3);
    aux_line_matrix.push_back(aux_line_4);


    // |__

    // __|

    //-_

    //__-_

    //_-


    AllTetraminos_.push_back(aux_line_matrix);
}

void GameControl::createGrille(){
    //int cubeWidth = 10;
    cellules_.resize(grilleHeith);
    for(int i = 0; i < grilleHeith; i++){ // For each layer
        cellules_[i].resize(grilleWidth);
        for(int j = 0; j < grilleWidth; j++){ // top wall, 5 squares across
            QVector3D p1(-(cubeWidth * 4.5) + cubeWidth*j,-(cubeWidth * 2.5),0.0 - cubeWidth*i);
            QVector3D p2(-(cubeWidth * 4.5) + cubeWidth*j,-(cubeWidth * 2.5),-cubeWidth - cubeWidth*i);
            QVector3D p3(-(cubeWidth * 3.5) + cubeWidth*j,-(cubeWidth * 2.5),-cubeWidth - cubeWidth*i);
            QVector3D p4(-(cubeWidth * 3.5) + cubeWidth*j,-(cubeWidth * 2.5),0.0 - cubeWidth*i);
            cellules_[i][j] = new cellule(p1,p2,p3,p4,i,j);
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
    int colloneInit=4;

    std::vector<cellule> cellules;
    std::vector< std::vector< std::tuple<int,int> > > tetramino_matrix = AllTetraminos_[0];
    cellules.push_back(cellule(cellules_[ligneInit][colloneInit]->getCoordinates()[0], cellules_[ligneInit][colloneInit]->getCoordinates()[1], cellules_[ligneInit][colloneInit]->getCoordinates()[2], cellules_[ligneInit][colloneInit]->getCoordinates()[3], ligneInit, colloneInit));

    int ligneIndex = ligneInit + std::get<0>(tetramino_matrix[0][0]);
    int colloneIndex = colloneInit + std::get<1>(tetramino_matrix[0][0]);
    cellules.push_back(cellule(cellules_[ligneIndex][colloneIndex]->getCoordinates()[0], cellules_[ligneIndex][colloneIndex]->getCoordinates()[1], cellules_[ligneIndex][colloneIndex]->getCoordinates()[2], cellules_[ligneIndex][colloneIndex]->getCoordinates()[3], ligneIndex, colloneIndex));

    ligneIndex = ligneInit + std::get<0>(tetramino_matrix[0][1]);
    colloneIndex = colloneInit + std::get<1>(tetramino_matrix[0][1]);
    cellules.push_back(cellule(cellules_[ligneIndex][colloneIndex]->getCoordinates()[0], cellules_[ligneIndex][colloneIndex]->getCoordinates()[1], cellules_[ligneIndex][colloneIndex]->getCoordinates()[2], cellules_[ligneIndex][colloneIndex]->getCoordinates()[3], ligneIndex, colloneIndex));

    ligneIndex = ligneInit + std::get<0>(tetramino_matrix[0][2]);
    colloneIndex = colloneInit + std::get<1>(tetramino_matrix[0][2]);
    cellules.push_back(cellule(cellules_[ligneIndex][colloneIndex]->getCoordinates()[0], cellules_[ligneIndex][colloneIndex]->getCoordinates()[1], cellules_[ligneIndex][colloneIndex]->getCoordinates()[2], cellules_[ligneIndex][colloneIndex]->getCoordinates()[3], ligneIndex, colloneIndex));

    tetraminos_.push_back(Tetramino(cellules, tetramino_matrix, c));
    //qDebug() << tetramino_matrix[1].size();
    return;
    //cellules.push_back(cellule( cellules_[ligneInit][colloneInit]->getCoordinates()[0],cellules_[ligneInit][colloneInit]->getCoordinates()[1],cellules_[ligneInit][colloneInit]->getCoordinates()[2],cellules_[ligneInit][colloneInit]->getCoordinates()[3],ligneInit,colloneInit));
    //cellules.push_back(cellule( cellules_[ligneInit+1][colloneInit]->getCoordinates()[0],cellules_[ligneInit+1][colloneInit]->getCoordinates()[1],cellules_[ligneInit+1][colloneInit]->getCoordinates()[2],cellules_[ligneInit+1][colloneInit]->getCoordinates()[3],ligneInit,colloneInit));
    //cellules.push_back(cellule( cellules_[ligneInit+1][colloneInit-1]->getCoordinates()[0],cellules_[ligneInit+1][colloneInit-1]->getCoordinates()[1],cellules_[ligneInit+1][colloneInit-1]->getCoordinates()[2],cellules_[ligneInit+1][colloneInit-1]->getCoordinates()[3],ligneInit,colloneInit));
    //cellules.push_back(cellule( cellules_[ligneInit-1][colloneInit]->getCoordinates()[0],cellules_[ligneInit-1][colloneInit]->getCoordinates()[1],cellules_[ligneInit-1][colloneInit]->getCoordinates()[2],cellules_[ligneInit-1][colloneInit]->getCoordinates()[3],ligneInit,colloneInit));
    //tetraminos_.push_back(Tetramino(cellules,c));
    //return;

    //std::vector<cellule> cellules;
    cellules.push_back(cellule( cellules_[ligneInit][colloneInit]->getCoordinates()[0],cellules_[ligneInit][colloneInit]->getCoordinates()[1],cellules_[ligneInit][colloneInit]->getCoordinates()[2],cellules_[ligneInit][colloneInit]->getCoordinates()[3],ligneInit,colloneInit));
    std::vector<std::tuple<int, int>> possibilites;
    possibilites.push_back(std::tuple<int, int>(ligneInit, colloneInit-1));
    possibilites.push_back(std::tuple<int, int>(ligneInit, colloneInit+1));
    possibilites.push_back(std::tuple<int, int>(ligneInit-1, colloneInit));
    possibilites.push_back(std::tuple<int, int>(ligneInit+1, colloneInit));
    std::vector<std::tuple<int, int>> already_taken;
    already_taken.push_back(std::tuple<int, int>(12,5));
    for(int i = 0; i < 3; i++){
      int r = rand()%possibilites.size();
      std::tuple<int, int> choice = possibilites[r];
      int ligne = std::get<0>(choice);
      int colone = std::get<1>(choice);
      possibilites.erase(possibilites.begin()+r);
      cellules.push_back(cellule(cellules_[ligne][colone]->getCoordinates()[0],cellules_[ligne][colone]->getCoordinates()[1],cellules_[ligne][colone]->getCoordinates()[2],cellules_[ligne][colone]->getCoordinates()[3],ligne,colone));
      already_taken.push_back(choice);
      //add new neigbohoods
       for(int j = 0; j < 4; j++){
          int activation = (j > 1) ? 1 : 0;
          std::tuple<int, int> t(ligne+(pow(-1, j)*activation),colone+(pow(-1, j)*((activation+1)%2)));
          if(std::find(already_taken.begin(), already_taken.end(), t) == already_taken.end()){
              possibilites.push_back(t);
          }
       }
    }
    //qDebug() << cellules.size();
    //for(std::vector<cellule>::iterator itc = cellules.begin(); itc != cellules.end(); ++itc){
    //    qDebug() << itc->getLigne() << itc->getColonne();
    //}
    //tetraminos_.push_back(Tetramino(cellules,c));

}

bool GameControl::canWeMoveDown(){
    std::vector<cellule> current_cellules = tetraminos_.back().getCellules();
    for(std::vector<cellule>::iterator itc=current_cellules.begin(); itc != current_cellules.end();++itc){
        int line = itc->getLigne();
        int colum = itc->getColonne();

        if( line == 0 || cellules_[line-1][colum]->getStatue()){
            return false;
        }
    }
    return true;
}

bool GameControl::canWeMoveLeft(){
    std::vector<cellule> current_cellules = tetraminos_.back().getCellules();
    for(std::vector<cellule>::iterator itc=current_cellules.begin(); itc != current_cellules.end();++itc){
        int line = itc->getLigne();
        int colum = itc->getColonne();
        //qDebug() << "colum: " << colum;
        if( colum == 0 || cellules_[line][colum-1]->getStatue()){
            return false;
        }
    }
    return true;
}

bool GameControl::canWeMoveRight(){
    std::vector<cellule> current_cellules = tetraminos_.back().getCellules();
    for(std::vector<cellule>::iterator itc=current_cellules.begin(); itc != current_cellules.end();++itc){
        int line = itc->getLigne();
        int colum = itc->getColonne();
        //qDebug() << "colum: " << colum;
        if( colum == (grilleWidth-1) || cellules_[line][colum+1]->getStatue()){
            return false;
        }
    }
    return true;
}

//--------------- SLOTS DEFINITION -----------------
void GameControl::Pause(){
    c = !c;
}
void GameControl::incrementZ(){
    if(c){
        if(canWeMoveDown()){
            tetraminos_.back().translateZ();
            tetraminos_.back().rollTetramino();
        }else {//if(!canWeMoveDown()){
            std::vector<cellule> current_cellules = tetraminos_.back().getCellules();
            for(std::vector<cellule>::iterator itc=current_cellules.begin(); itc != current_cellules.end();++itc){
                int line = itc->getLigne();
                int colum = itc->getColonne();
                cellules_[line][colum]->setStatue(true);// toute est faux au debut
            }
            createTetramino();
        }

        // gestion des collision maintenand
        affichage->SetTetraminosVector(tetraminos_);
           // qDebug()<<getZmin()+tetraminos_.back().getTranslateZ();
   }
}

void GameControl::LeftRequest(){
    //qDebug() << "Left request";
    if(canWeMoveLeft()){
        //qDebug() << "YES";
        tetraminos_.back().moveLeft();
    }
}

void GameControl::RightRequest(){
    //qDebug() << "Right request";
    if(canWeMoveRight()){
        //qDebug() << "YES";
        tetraminos_.back().moveRight();
    }
}

void GameControl::RotateRequest(){
    //c = false;
    //qDebug() << "Rotate Request";
    tetraminos_.back().Rotate();

}

#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <QObject>
#include "paintwidget.h"
#include <QWidget>

class GameControl : public QObject
{
    Q_OBJECT
public:
    explicit GameControl(PaintWidget* p = nullptr, QObject *parent = nullptr);

signals:

public slots:
    void incrementZ();
    void LeftRequest();
    void RightRequest();
    void RotateRequest();
    void Pause();
private:
    bool c;
   int cubeWidth;
   int grilleWidth;
   int grilleHeith;
   int pauseTime_;
   PaintWidget* affichage;
   std::vector<Tetramino> tetraminos_;
   std::vector<std::vector<cellule*> > cellules_;

   std::vector< std::vector<std::vector<std::tuple<int, int> > > > AllTetraminos_;
   void createTetramino();
   void createAllTetraminos();
   void createGrille();
   float getZmax();
   bool canWeMoveDown();
   bool canWeMoveLeft();
   bool canWeMoveRight();
   bool canWeRotate();
   std::vector<QString> listeImage;
};

#endif // GAMECONTROL_H

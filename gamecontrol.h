#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <QObject>
#include "paintwidget.h"
#include <QWidget>
#include <QLabel>

class GameControl : public QObject
{
    Q_OBJECT
public:
    explicit GameControl(PaintWidget* p = nullptr, QLabel* score = nullptr, QLabel* level = nullptr, QLabel* lines = nullptr, QLabel* move = nullptr, QObject *parent = nullptr);

signals:

public slots:
    void incrementZ();
    void LeftRequest();
    void RightRequest();
    void RotateRequest();
    void Pause();
    void MoveSlowOrSpeed();
private:
    bool c;
   int cubeWidth;
   int grilleWidth;
   int grilleHeith;
   int pauseTime_;
   std::vector<int> remplissage_;
   QTimer* timer;
   PaintWidget* affichage;
   QLabel* score_, *level_, *lines_, *move_;
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
   bool endGame();
   void RestartGame();
   void RemoveLine(int i);
   std::vector<QString> listeImage;
};

#endif // GAMECONTROL_H

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
private:
    PaintWidget* affichage;
       std::vector<Tetramino> tetraminos_;
       std::vector<std::vector<cellule*> > cellules_;
       void createTetramino();
       void createGrille();
       float getZmin();
       bool canWeMouve();
};

#endif // GAMECONTROL_H

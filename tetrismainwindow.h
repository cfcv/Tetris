#ifndef TETRISMAINWINDOW_H
#define TETRISMAINWINDOW_H

#include <QMainWindow>
#include<QWidget>
#include "videocrontrol.h"
#include "gamecontrol.h"


namespace Ui {
class TetrisMainWindow;
}

class TetrisMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TetrisMainWindow(QWidget *parent = nullptr);
    ~TetrisMainWindow();

private:
    Ui::TetrisMainWindow *ui;
    VideoCrontrol* vc_;             //variable pour instancier la classe VideoControl
    GameControl* gc_;               //variable pour instancier la classe GameControl

protected:
    void keyPressEvent(QKeyEvent* event);

signals:
    void LeftSignal();              //Signal pour notifier le GameControl pour faire la translation vers la gauche du tetramino courant
    void RightSignal();             //Signal pour notifier le GameControl pour faire la translation vers la droite du tetramino courant
    void RotateSignal();            //Signal pour notifier le GameControl pour rotationer le tetramino courant
    void PauseSignal();
    void MoveSlowOrSpeed();         //Signal pour notifier le GameControl pour modifier la vitesse
    void changeNiveau(int);

};

#endif // TETRISMAINWINDOW_H

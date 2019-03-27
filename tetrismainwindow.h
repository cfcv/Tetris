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
    VideoCrontrol* vc_;
    GameControl* gc_;
};

#endif // TETRISMAINWINDOW_H

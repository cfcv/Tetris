#include "tetrismainwindow.h"
#include "ui_tetrismainwindow.h"
#include "paintwidget.h"

#include <QTimer>
#include <iostream>

TetrisMainWindow::TetrisMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TetrisMainWindow)
{
    ui->setupUi(this);
    vc_ = new VideoCrontrol(ui->image_label);
    gc_ = new GameControl(ui->paintArea);
}

TetrisMainWindow::~TetrisMainWindow()
{
    delete ui;
}

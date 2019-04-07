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
    connect(this, SIGNAL(LeftSignal()), gc_, SLOT(LeftRequest()));
    connect(this, SIGNAL(RightSignal()), gc_, SLOT(RightRequest()));
    connect(this, SIGNAL(RotateSignal()), gc_, SLOT(RotateRequest()));
    connect(this, SIGNAL(PauseSignal()), gc_, SLOT(Pause()));
}

TetrisMainWindow::~TetrisMainWindow()
{
    delete ui;
}

void TetrisMainWindow::keyPressEvent(QKeyEvent * event){
    switch(event->key()){
        // Activation/Arret de l'animation
        case Qt::Key_A:{
            qDebug() << "left";
            emit LeftSignal();
            break;
        }

        // Sortie de l'application
        case Qt::Key_D:{
            qDebug() << "right";
            emit RightSignal();
            break;
        }

        case Qt::Key_R:{
            qDebug() << "rotate";
            emit RotateSignal();
            break;
        }
    case Qt::Key_P:{
            emit PauseSignal();
            break;
        }
        case Qt::Key_Q:{
            exit(0);
            break;
        }
        // Cas par defaut
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
  //  updateGL();
}

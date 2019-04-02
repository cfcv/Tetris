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

void TetrisMainWindow::keyPressEvent(QKeyEvent * event){
    switch(event->key()){
        // Activation/Arret de l'animation
        case Qt::Key_A:{
            qDebug() << "left";
            break;
        }

        // Sortie de l'application
        case Qt::Key_D:{
            qDebug() << "right";
            break;
        }

        case Qt::Key_R:{
            qDebug() << "rotate";
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

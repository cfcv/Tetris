#include "tetrismainwindow.h"
#include "ui_tetrismainwindow.h"

#include <QTimer>
#include <iostream>

using namespace cv;

TetrisMainWindow::TetrisMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TetrisMainWindow)
{
    ui->setupUi(this);
    cap = VideoCapture(0);
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(cameraThread()));
    timer->start(10); //milisecondes
}

TetrisMainWindow::~TetrisMainWindow()
{
    delete ui;
}

void TetrisMainWindow::cameraThread(){
    //VideoCapture cap(0);
    //#int width=cap.get(CV_CAP_PROP_FRAME_WIDTH);
    //int height=cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    //QString cascadePath = "";
    if (cap.isOpened()) {
            Mat frame;
            if (cap.read(frame)) {   // Capture a frame
                // Flip to get a mirror effect
                flip(frame,frame,1);
                // Invert Blue and Red color channels
                cvtColor(frame,frame,CV_BGR2RGB);
                // Convert to Qt image
                QImage img= QImage((const unsigned char*)(frame.data),frame.cols,frame.rows,QImage::Format_RGB888);
                // Display on label
                ui->image_label->setPixmap(QPixmap::fromImage(img));
                // Resize the label to fit the image
                ui->image_label->resize(ui->image_label->pixmap()->size());

            }
            else {
               std::cout << "Error while opening camera." << std::endl;
            }
       }
}

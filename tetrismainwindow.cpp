#include "tetrismainwindow.h"
#include "ui_tetrismainwindow.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect/objdetect.hpp>

TetrisMainWindow::TetrisMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TetrisMainWindow)
{
    ui->setupUi(this);
}

TetrisMainWindow::~TetrisMainWindow()
{
    delete ui;
}

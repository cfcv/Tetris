#ifndef TETRISMAINWINDOW_H
#define TETRISMAINWINDOW_H

#include <QMainWindow>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect/objdetect.hpp>

namespace Ui {
class TetrisMainWindow;
}

class TetrisMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TetrisMainWindow(QWidget *parent = nullptr);
    ~TetrisMainWindow();

private slots:
    void cameraThread();
private:
    Ui::TetrisMainWindow *ui;
    cv::VideoCapture cap;
};

#endif // TETRISMAINWINDOW_H

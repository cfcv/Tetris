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

public slots:
    void cameraThread();

signals:
    void handDetection(int);

private:
    Ui::TetrisMainWindow *ui;
    cv::VideoCapture cap_;
    cv::CascadeClassifier hand_cascade_;
    int direction_ = 0; // -1 -> gauche, 0 -> rien, 1 -> droite
};

#endif // TETRISMAINWINDOW_H

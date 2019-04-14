#ifndef VIDEOCRONTROL_H
#define VIDEOCRONTROL_H
#include<QWidget>
#include <QLabel>
#include <QMainWindow>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2/opencv.hpp"
#include <QTimer>
#include <QDebug>

class VideoCrontrol : public QObject
{
    Q_OBJECT
public:
    explicit VideoCrontrol(QLabel* i, QObject *parent = nullptr);

private:
    int count_;
    int timing_response_;                           //le temps qu'on envoie un signal
    QLabel* image_label;                            //Label de l'interface pour afficher l'image
    cv::VideoCapture cap_;                          //Variable pour faire des capture des images à travers de la caméra
    cv::CascadeClassifier hand_cascade_;            //Variable pour stocker le classifieur
signals:
    void VideoLeftSignal();                         //Fonction qui notifie la classe GameControl qu'elle a detecté un geste pour translater le tetramino vers la gauche
    void VideoRightSignal();                        //Fonction qui notifie la classe GameControl qu'elle a detecté un geste pour translater le tetramino vers la driote
    void VideoRotateSignal();                       //Fonction qui notifie la classe GameControl qu'elle a detecté un geste pour rotationer le tetramino

public slots:
    void cameraThread();                            //Fonction appelé dans chaque 100ms pour s'occuper de capturer des images et detecter des gestes
};

#endif // VIDEOCRONTROL_H

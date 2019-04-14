#include "videocrontrol.h"


VideoCrontrol::VideoCrontrol(QLabel* i, QObject *parent) : QObject(parent), image_label(i)
{

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(cameraThread()));
    timer->start(10); //mi
    cap_ = cv::VideoCapture(0);
    if(! hand_cascade_.load("/home/cfcv/Desktop/Tetris/closed_palm.xml")){
        qDebug() << "Error during loading the cascade classifier";
        exit(0);
    }

    count_ = 0;
    timing_response_ = 10;
}

void VideoCrontrol::cameraThread(){
           int width=cap_.get(CV_CAP_PROP_FRAME_WIDTH);
           int height=cap_.get(CV_CAP_PROP_FRAME_HEIGHT);
           //QString cascadePath = "";
           if (cap_.isOpened()) {

                   std::vector<cv::Rect> hands;
                   cv::Mat frame, crop, frame_gray;
                   if (cap_.read(frame)) {   // Capture a frame

                       // Flip to get a mirror effect
                       flip(frame,frame,1);
                       // Invert Blue and Red color channels
                       cvtColor(frame,frame,CV_BGR2RGB);
                       crop = cv::Mat(frame, cv::Rect(0,height/2,width,height/2)).clone();

                       cv::cvtColor(crop,frame_gray,cv::COLOR_RGB2GRAY);
                       hand_cascade_.detectMultiScale( frame_gray, hands, 1.1, 3, 0|CV_HAAR_SCALE_IMAGE, cv::Size(80, 80), cv::Size(200, 200));
                       if (hands.size()>0)
                       {
                           // Draw green rectangle
                           //int xMoyen = 0;
                           //int yMoyen = 0;
                           for (int i=0;i<(int)hands.size();i++){
                               rectangle(crop,hands[i],cv::Scalar(0,255,0),2);

                               circle(crop, cv::Point(hands[i].x + hands[i].width/2, hands[i].y + hands[i].width/2), 10, cv::Scalar(255,0,0), -1);

                           }

                           if(hands.size() == 2){
                               int centre_y_1 = hands[0].y + hands[0].width/2;
                               int centre_y_2 = hands[1].y + hands[1].width/2;
                               int centre_x_1 = hands[0].x + hands[0].width/2;
                               int centre_x_2 = hands[1].x + hands[1].width/2;
                               int decalage = centre_y_1 - centre_y_2;
                               if(count_%timing_response_ == 0){
                                   if(abs(decalage) > 30){
                                       if(centre_x_1 < centre_x_2){
                                           if(decalage < 0){
                                               qDebug() << "right";
                                               emit VideoRightSignal();
                                           } else{
                                               qDebug() << "left";
                                               emit VideoLeftSignal();
                                           }
                                       }
                                       else{
                                           if(decalage < 0){
                                               qDebug() << "left";
                                               emit VideoLeftSignal();
                                           } else{
                                               qDebug() << "right";
                                               emit VideoRightSignal();
                                           }
                                       }
                                   } else {
                                       qDebug() << abs(centre_x_1-centre_x_2);
                                       if(abs(centre_x_1-centre_x_2)<200){
                                       qDebug() << "rot";
                                       emit VideoRotateSignal();
                                       }
                                   }
                               }
                               count_++;
     //
                               }


                       }
                       // Convert to Qt image
                       QImage img= QImage((const unsigned char*)(crop.data),crop.cols,crop.rows,QImage::Format_RGB888);
                       // Display on label
                      image_label->setPixmap(QPixmap::fromImage(img));
                       // Resize the label to fit the image
                       image_label->resize(image_label->pixmap()->size());


                   }
              }
}



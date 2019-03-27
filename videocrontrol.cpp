#include "videocrontrol.h"
//#include <QMainWindow>
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include <opencv2/objdetect/objdetect.hpp>
//#include <opencv2/core/core.hpp>
//#include "opencv2/opencv.hpp"
//#include<QWidget>
//cv::VideoCapture cap_;
//cv::CascadeClassifier hand_cascade_;
//int direction_ = 0; // -1 -> gauche, 0 -> rien, 1 -> droite
VideoCrontrol::VideoCrontrol(QLabel* i, QObject *parent) : QObject(parent)
{
    //read the haar cascade file
    //appel a function to read the image and detect hands
    //emettre un singal une fois detecté les mains.
}

//cap_ = VideoCapture(0);
//if( !hand_cascade_.load("C:/Users/yayak/Desktop/cours_fise2/Tetris/ressource/hand.xml"))//"/home/cfcv/Desktop/CascadeTraining/data/cascade.xml"))//CarData/data/cascade.xml"))//CascadeTraining/data/cascade.xml"))//Tutoriais/Projet_s8/tests/Opencv/haarcascade/closed_frontal_palm.xml" ) )
//{
//    std::cout <<"Error loading haarcascade"<< std::endl;
//    close();
//}
//    QTimer* timer = new QTimer(this);
//connect(timer, SIGNAL(timeout()), this, SLOT(cameraThread()));
        //connect(this, SIGNAL(handDetection(int)), ui->paintArea, SLOT(moveCircle(int)));

 //   void TetrisMainWindow::cameraThread(){
 //       int width=cap_.get(CV_CAP_PROP_FRAME_WIDTH);
 //       int height=cap_.get(CV_CAP_PROP_FRAME_HEIGHT);
        //QString cascadePath = "";
 //       if (cap_.isOpened()) {
 //               std::vector<Rect> hands;
 //               Mat frame, crop, frame_gray;
 //               if (cap_.read(frame)) {   // Capture a frame

                    // Flip to get a mirror effect
 //                   flip(frame,frame,1);
                    // Invert Blue and Red color channels
 //                   cvtColor(frame,frame,CV_BGR2RGB);
 //                   crop = cv::Mat(frame, cv::Rect(0,height/2,width,height/2)).clone();

 //                   cv::cvtColor(crop,frame_gray,COLOR_RGB2GRAY);
 //                   hand_cascade_.detectMultiScale( frame_gray, hands, 1.1, 3, 0|CV_HAAR_SCALE_IMAGE, Size(80, 80), Size(200, 200));
 //                   if (hands.size()>0)
 //                   {
                        // Draw green rectangle
 //                       for (int i=0;i<(int)hands.size();i++){
 //                           rectangle(crop,hands[i],Scalar(0,255,0),2);
                            //std::cout << hands[i].width << " " << hands[i].height << std::endl;
 //                       }

 //                       if(hands.size() == 2){
 //                           int centre_y_1 = hands[0].y + hands[0].width/2;
 //                           int centre_y_2 = hands[1].y + hands[1].width/2;
 //                           int decalage = centre_y_1 - centre_y_2;

  //                          if(abs(decalage) < 30){
  //                              direction_ = 0;
  //                          } else {
  //                              if(decalage < 0){
  //                                  direction_ = 1;
  //                              } else {
   //                                 direction_ = -1;
   //                             }
   //                         }

                            //std::cout << centre_y_1 << " " << centre_y_2 << std::endl;
                            //std::cout << "emis" << std::endl;
    //                        emit handDetection(direction_);
    //                    }
    //                }
                    // Convert to Qt image
     //               QImage img= QImage((const unsigned char*)(crop.data),crop.cols,crop.rows,QImage::Format_RGB888);
                    // Display on label
       //             ui->image_label->setPixmap(QPixmap::fromImage(img));
                    // Resize the label to fit the image
        //            ui->image_label->resize(ui->image_label->pixmap()->size());

          //      }
            //    else {
            //       std::cout << "Error while opening camera." << std::endl;
             //   }
           //}
    //}

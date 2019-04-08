#include "cellule.h"

cellule::cellule(QVector3D p1,QVector3D p2,QVector3D p3,QVector3D p4,int ligne,int colonnes)
{
    path="C:\\Users\\yayak\\Desktop\\cours_fise2\\Tetris\\image\\inc.jpg";
    texture_=QGLWidget::convertToGLFormat(QImage(path));
            coordinates_.push_back(p1);
            coordinates_.push_back(p2);
            coordinates_.push_back(p3);
            coordinates_.push_back(p4);
            planY = coordinates_[0].y();
            center_.setX((p1.x() + p2.x() + p3.x() + p4.x())/4);
            center_.setY((p1.y() + p2.y() + p3.y() + p4.y())/4);
            center_.setZ((p1.z() + p2.z() + p3.z() + p4.z())/4);
            statue_=false;
            ligne_=ligne;
            colonne_=colonnes;
            minX = coordinates_[0].x();
            //float maxX = coordinates_[0].x();
            minZ = coordinates_[0].z();
            //float maxZ = coordinates_[0].z();
            for(int i =1; i < coordinates_.size(); ++i){
                if(coordinates_[i].x() < minX || (coordinates_[i].x() == minX && coordinates_[i].z() < minZ)){
                    minX = coordinates_[i].x();
                    minZ = coordinates_[i].z();
                }
            }
}

float cellule::cubeWidth = 10;

void cellule::draw()
{
    //get the minimum and maximum x and minimal and maximum z
    //glClear(GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glGenTextures( 1, &m_TextureID );
    glBindTexture( GL_TEXTURE_2D, m_TextureID );
    glTexImage2D( GL_TEXTURE_2D, 0, 4, texture_.width(),texture_.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture_.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glLoadIdentity();
    //glTranslatef(0.0, 0.0, -35.0f);
    glBegin(GL_QUADS);
   // glColor3ub(0, 0, 255);

     // face d'en bas
    glTexCoord2d(0,1);glVertex3f(  minX,   planY,   minZ);
    glTexCoord2d(0,0);glVertex3f(  minX+cubeWidth,   planY,   minZ);
    glTexCoord2d(1,0);glVertex3f(  minX+cubeWidth,   planY,   minZ+cubeWidth);
    glTexCoord2d(1,1);glVertex3f(  minX,   planY,   minZ+cubeWidth);
    //glVertex3f(  coordinates_[0].x(),   coordinates_[0].y(),   coordinates_[0].z());
    //glVertex3f(  coordinates_[1].x(),   coordinates_[1].y(),   coordinates_[1].z());
    //glVertex3f(  coordinates_[2].x(),   coordinates_[2].y(),   coordinates_[2].z());
    //glVertex3f(  coordinates_[3].x(),   coordinates_[3].y(),   coordinates_[3].z());
     //face d'en haux
    glTexCoord2d(0,1);glVertex3f(  minX,   planY+cubeWidth,   minZ);
    glTexCoord2d(0,0);glVertex3f(  minX+cubeWidth,   planY+cubeWidth,   minZ);
    glTexCoord2d(1,0);glVertex3f(  minX+cubeWidth,   planY+cubeWidth,   minZ+cubeWidth);
    glTexCoord2d(1,1);glVertex3f(  minX,   planY+cubeWidth,   minZ+cubeWidth);
    //glVertex3f(  coordinates_[0].x(),   coordinates_[0].y()+10,   coordinates_[0].z());
    //glVertex3f(  coordinates_[1].x(),   coordinates_[1].y()+10,   coordinates_[1].z());
    //glVertex3f(  coordinates_[2].x(),   coordinates_[2].y()+10,   coordinates_[2].z());
    //glVertex3f(  coordinates_[3].x(),   coordinates_[3].y()+10,   coordinates_[3].z());
    // face en face
    glTexCoord2d(0,1);glVertex3f(  minX,   planY+cubeWidth,   minZ+cubeWidth);
    glTexCoord2d(0,0);glVertex3f(  minX+cubeWidth,   planY+cubeWidth,   minZ+cubeWidth);
    glTexCoord2d(1,0);glVertex3f(  minX+cubeWidth,   planY,   minZ+cubeWidth);
    glTexCoord2d(1,1);glVertex3f(  minX,   planY,   minZ+cubeWidth);
    //glVertex3f(  coordinates_[0].x(),   coordinates_[0].y()+10,   coordinates_[0].z());
    //glVertex3f(  coordinates_[1].x(),   coordinates_[1].y(),   coordinates_[1].z()+10);
    //glVertex3f(  coordinates_[2].x(),   coordinates_[2].y(),   coordinates_[2].z()+10);
    //glVertex3f(  coordinates_[3].x(),   coordinates_[3].y()+10,   coordinates_[3].z());
    // face derriere
    glTexCoord2d(0,1);glVertex3f(  minX,   planY+cubeWidth,   minZ);
    glTexCoord2d(0,0);glVertex3f(  minX+cubeWidth,   planY+cubeWidth,   minZ);
    glTexCoord2d(1,0);glTexCoord2d(1,0);glVertex3f(  minX+cubeWidth,   planY,   minZ);
    glTexCoord2d(1,1);glVertex3f(  minX,   planY,   minZ);
    //glVertex3f(  coordinates_[0].x(),   coordinates_[0].y()+10,   coordinates_[0].z()-10);
    //glVertex3f(  coordinates_[1].x(),   coordinates_[1].y(),   coordinates_[1].z());
    //glVertex3f(  coordinates_[2].x(),   coordinates_[2].y(),   coordinates_[2].z());
    //glVertex3f(  coordinates_[3].x(),   coordinates_[3].y()+10,   coordinates_[3].z()-10);
    // face a gauche
    glTexCoord2d(0,1);glVertex3f(  minX,   planY+cubeWidth,   minZ);
    glTexCoord2d(0,0);glVertex3f(  minX,  planY+cubeWidth,   minZ+cubeWidth);
    glTexCoord2d(1,0);glVertex3f(  minX,   planY,   minZ+cubeWidth);
    glTexCoord2d(1,1);glVertex3f(  minX,   planY,   minZ);
    //glVertex3f(  coordinates_[1].x(),   coordinates_[1].y()+10,   coordinates_[1].z());
    //glVertex3f(  coordinates_[0].x(),   coordinates_[0].y()+10,   coordinates_[0].z());
    //glVertex3f(  coordinates_[0].x(),   coordinates_[0].y(),   coordinates_[0].z());
    //glVertex3f(  coordinates_[1].x(),   coordinates_[1].y(),   coordinates_[1].z());
    // face a droite
    glTexCoord2d(0,1);glVertex3f(  minX+cubeWidth,   planY+cubeWidth,   minZ+cubeWidth);
    glTexCoord2d(0,0);glVertex3f(  minX+cubeWidth,   planY+cubeWidth,   minZ);
    glTexCoord2d(1,0);glVertex3f(  minX+cubeWidth,   planY,   minZ);
    glTexCoord2d(1,1);glVertex3f(  minX+cubeWidth,   planY,   minZ+cubeWidth);
    //glVertex3f(  coordinates_[1].x()+10,   coordinates_[1].y()+10,   coordinates_[1].z());
    //glVertex3f(  coordinates_[0].x()+10,   coordinates_[0].y()+10,   coordinates_[0].z());
    //glVertex3f(  coordinates_[0].x()+10,   coordinates_[0].y(),   coordinates_[0].z());
    //glVertex3f(  coordinates_[1].x()+10,   coordinates_[1].y(),   coordinates_[1].z());
    //glColor3ub(255, 255, 0);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void cellule::rotate(float Xpivot, float Ypivot){
    int ancien_ligne = ligne_;
    int ancien_colonne = colonne_;

    ligne_ = Xpivot;
    colonne_ = Ypivot;
    //qDebug() << "current position: " << ancien_ligne << ancien_colonne;
    //qDebug() << "new position: " << ligne_ << colonne_;

    int deltaY = ligne_ - ancien_ligne; //if it is posivite: the cellule goes UP, otherwise DOWN
    int deltaX= colonne_ - ancien_colonne; //if it is positive: the cellule goes RIGHT otherwie it goes LEFT
    //qDebug() << "current center: " << minX << minZ;

    minX += cubeWidth*deltaX;
    minZ += -(deltaY*cubeWidth);
    //qDebug() << "new center: " << minX << minZ;
    return;

    //qDebug() << "pivot dedans la fonction: " << Xpivot << Ypivot;
    //qDebug() << "Ancien min: " << minX << minZ;
    float newX = Xpivot + Ypivot - coordinates_[0].z();
    float newZ = Ypivot - Xpivot + coordinates_[0].x();
    //qDebug() << "new x et Z: " << newX << newZ;
    coordinates_[0].setX(newX);
    coordinates_[0].setZ(newZ);
    minX = newX;
    minZ = newZ;
    for(int i = 1; i < coordinates_.size(); i++){
        //qDebug() << "Ancien point: " << itc->x() << " " << itc->y() << " " << itc->z();
        newZ = Ypivot - Xpivot + coordinates_[i].x();
        newX = Xpivot + Ypivot - coordinates_[i].z();
        coordinates_[i].setX(newX);
        //qDebug() << "somme intermediaire Z: " << Ypivot - Xpivot + itc->x();
        coordinates_[i].setZ(newZ);
        //qDebug() << "Nouvelle point: " << itc->x() << itc->y() << itc->z();
        //qDebug() << "Nouvelle point: " << coordinates_[i].x() << coordinates_[i].y() << coordinates_[i].z();
        if(coordinates_[i].x() < minX || (coordinates_[i].x() == minX && coordinates_[i].z() < minZ)){
            minX = coordinates_[i].x();
            minZ = coordinates_[i].z();
        }
    }
    qDebug() << "Nouvelle min: " << minX << minZ;
    //qDebug() << "Ancien centre: " << center_.x() << " " << center_.y() << " " << center_.z();
    center_.setX(Xpivot + Ypivot - center_.z());
    center_.setZ(Ypivot - Xpivot - center_.x());
    //qDebug() << "Ancien centre: " << center_.x() << " " << center_.y() << " " << center_.z();
}

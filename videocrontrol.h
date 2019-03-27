#ifndef VIDEOCRONTROL_H
#define VIDEOCRONTROL_H
#include<QWidget>

class VideoCrontrol : public QObject
{
    Q_OBJECT
public:
    explicit VideoCrontrol(QObject *parent = nullptr);

signals:

public slots:
};

#endif // VIDEOCRONTROL_H

#ifndef BULLET_H
#define BULLET_H

#include<QGraphicsRectItem>
#include<QObject>

//inherit from QObject so that we can use signal and slot
class Bullet:public QObject,public QGraphicsRectItem
{
    Q_OBJECT

public:
    Bullet();

public slots:
    //slot to move bullet
    void move();
};

#endif // BULLET_H

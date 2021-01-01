#ifndef ENEMY_H
#define ENEMY_H

#include<QGraphicsRectItem>
#include<QObject>

class Enemy:public QObject,public QGraphicsRectItem
{
     Q_OBJECT
public:
    Enemy();

public slots:
    //slot to move enemy
    void move();
};

#endif // ENEMY_H

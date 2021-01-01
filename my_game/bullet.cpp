#include "bullet.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QDebug>
#include<enemy.h>
#include<QList>
#include<game.h>

extern Game *game; //their is a global variable named game having type Game

Bullet::Bullet():QObject(), QGraphicsRectItem()
{
    //set bullet size
    setRect(0,0,10,50);

    //adding a timer so that the slot is called when timer gets to 0
    QTimer *timer = new QTimer();

    //connect to slot
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //setting timer time to 50 milliseconds
    //the move method will be called after every 50 milliseconds
    timer->start(50);
}

//moving bullet
void Bullet::move()
{
    //if bullet collide with enemy destroy both of them
    QList<QGraphicsItem *> collide_item = collidingItems();

    for(int i=0;i<collide_item.size();i++){
        if(typeid(*(collide_item[i])) == typeid(Enemy)){
            //increase the score
            game->score->increase();

            //remove both the item
            scene()->removeItem(collide_item[i]);
            scene()->removeItem(this);
            delete collide_item[i];
            delete this;
            return ;
        }
    }
    //move bullet up
    setPos(x(),y()-10);

    //if bullet is out of scene delete it
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;
//        qDebug()<<"Bullet deleted";
    }
}

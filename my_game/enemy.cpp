#include "enemy.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QDebug>
#include<stdlib.h> //gives random function
#include<game.h>

extern Game *game;

Enemy::Enemy():QObject(), QGraphicsRectItem()
{
    //setting position
    int random_number = rand()%700;
    setPos(random_number,0);
    //set enemy size
    setRect(0,0,100,100);

    //adding a timer so that the slot is called when timer gets to 0
    QTimer *timer = new QTimer();

    //connect to slot
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //setting timer time to 50 milliseconds
    //the move method will be called after every 50 milliseconds
    timer->start(50);
}

//moving enemy
void Enemy::move()
{
    //if enemy collide with player decrease the health and delete the item
    QList<QGraphicsItem *> collide_item = collidingItems();

    for(int i=0;i<collide_item.size();i++){
        if(typeid(*(collide_item[i])) == typeid(MyRect)){
            //decrease the health
            game->health->decrease();

            //remove the enemy
            scene()->removeItem(this);
            delete this;
            return ;
        }
    }

    //move enemy down
    setPos(x(),y()+5);

    //if enemy is out of scene delete it
    if(pos().y() + 100 >= 600){
        //decrease the health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;

//        qDebug()<<"Bullet deleted";
    }
}

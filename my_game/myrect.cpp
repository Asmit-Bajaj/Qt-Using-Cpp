#include "myrect.h"
#include<QKeyEvent>
#include<QGraphicsScene>
#include<bullet.h>
#include<enemy.h>


MyRect::MyRect(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    //setting bullet sound
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/C:/Users/Hp/Downloads/bullet.wav"));

}
//this method is called when key is pressed
void MyRect::keyPressEvent(QKeyEvent *event)
{
    //now moving the rectangle accor to key
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0)
            setPos(x()-10,y());
    }else if(event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 800)
            setPos(x()+10,y());
    }else if(event->key() == Qt::Key_Space){
        //create a new Bullet
        Bullet *bullet = new Bullet();
        //now setting bullet postiton to current rect x and y
        bullet->setPos(x(),y());

        //adding to current scene
        scene()->addItem(bullet);

        //if sound is already played then stop it
        if(bulletSound->state() == QMediaPlayer::PlayingState){
            bulletSound->setPosition(0);
        }else if(bulletSound->state() == QMediaPlayer::StoppedState){
            //else play the sound
            bulletSound->play();
        }
    }
}

void MyRect::spawn()
{
    //creating enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}

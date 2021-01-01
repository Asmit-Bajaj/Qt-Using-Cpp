#include "game.h"
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsView>
#include<myrect.h>
#include<QTimer>
#include<QMediaPlayer>

/*QGraphicsScene for adding the scene
 * QGraphicsItem for adding items on scene
 * QGraphicsView to show the scene
 */


Game::Game(QWidget *parent)
{
    //first creating a scene
    scene = new QGraphicsScene();

    //now create an item to add to scene
    player = new MyRect();

    //by default the rectangle has length and width as 0
    //setting x and y coordinates and then the length and width
    player->setRect(0,0,100,100);

    //in order to respond to event we need to set item to focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    setScene(scene);
    //now adding item
    scene->addItem(player);

    //creating the score
    score = new Score();
    scene->addItem(score);

    //now setting the size of scene and view
    setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    //the scene and view will overlap each other

    //creating the health
    health = new Health();
    health->setPos(650,health->y());
    scene->addItem(health);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //setting background music
    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/C:/Users/Hp/Downloads/sound.mp3"));
    music->play();

    //now getting the player to bottom of scene
    player->setPos(width()/2,height() - player->rect().height());

    //now spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);
}

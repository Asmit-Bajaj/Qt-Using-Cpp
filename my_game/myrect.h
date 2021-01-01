#ifndef MYRECT_H
#define MYRECT_H
#include<QGraphicsRectItem>
#include<QObject>
#include<QMediaPlayer>

class MyRect:public QObject,public QGraphicsRectItem
{
    Q_OBJECT

public:
    MyRect(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);

public slots:
    void spawn();
private:
    QMediaPlayer *bulletSound;
};

#endif // MYRECT_H

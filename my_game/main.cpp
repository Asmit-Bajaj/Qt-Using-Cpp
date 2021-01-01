#include <QApplication>
#include<game.h>

Game *game; //making global so that anyone can access it

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->show();

    return a.exec();
}

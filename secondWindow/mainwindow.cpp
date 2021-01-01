#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "window2.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    window2 win;
//    //shows in modal format
//    win.setModal(true);
//    win.exec();
    hide();
    win = new window2();
    win->show();
}

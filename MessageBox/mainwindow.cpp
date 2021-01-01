#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<qdebug.h>

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

//display message when button is clicked
void MainWindow::on_pushButton_clicked()
{
    //we can call functions in static manner as well as using object

    //show simple message
   // QMessageBox::about(this,"My Message Box","Hello World");

    //show about QT
//    QMessageBox::aboutQt(this,"About QT");

        //showing a critical message
//    QMessageBox::critical(this,"Critical Message","This is a critical message");

    //showing info msg
//       QMessageBox::information(this,"Information Message","This is a information message");

      //showing a question msg
       QMessageBox::StandardButton reply =
               QMessageBox::question(this,"Question","Are You Sure About It",QMessageBox::Yes|QMessageBox::No);


       //if reply is yes then quit the app
       if(reply == QMessageBox::Yes){
           QApplication::quit();
       }else{
           //else show msg on console
           qDebug()<<"No Is Clicked";
       }
}

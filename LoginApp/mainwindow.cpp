#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setting picc in label
    QPixmap pix(":/images/img/login.png");
    ui->label_pic->setPixmap(pix.scaled(ui->label_pic->width(),ui->label_pic->height(),Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{
    QString user = ui->user->text();
    QString pwd = ui->pwd->text();

    //on successful login show msg
    if(user == "ab004" && pwd == "1234"){
//        QMessageBox::information(this,"Successful","You Have Successfully Logged In");
        ui->statusbar->showMessage("You Have Successfully Logged In");
    }else{
//        QMessageBox::warning(this,"Error","Wrong Username Or Password");
        ui->statusbar->showMessage("Wrong Username Or Password");
    }
}

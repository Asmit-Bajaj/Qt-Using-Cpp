#include "mainwindow.h"
#include "ui_mainwindow.h"

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

//this method will be called when pushButton is clicked
void MainWindow::on_pushButton_clicked()
{
    ui->my_label->setText("You Had Clicked The Button");
}

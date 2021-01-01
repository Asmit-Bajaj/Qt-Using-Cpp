#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QFileDialog>
#include<QMessageBox>
#include<QFont>
#include<QFontDialog>
#include<QColor>
#include<QColorDialog>
#include<QPrintDialog>
#include<QPrinter>
#include<QDateTime>
#include<QCloseEvent>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setting title and icon
    QWidget::setWindowTitle("Untitled - MyNotepad");
    QWidget::setWindowIcon(QIcon(":/img/images/icon.png"));
    //setting text edit to full screen
    this->setCentralWidget(ui->mainTextWindow);

    textChg = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

//handling the close event when x is clicked
void MainWindow::closeEvent(QCloseEvent *bar){

    if(textChg == 1 && (ui->mainTextWindow->toPlainText() != "" || file_path != "")){
        QMessageBox::StandardButton reply;
        if(file_path == ""){
            reply = QMessageBox::question(this,"MyNotepad",
            "Do You Want To Save The Changes to Untitled ?",QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
        }else{
            reply = QMessageBox::question(this,"MyNotepad",
            "Do You Want To Save The Changes to "+file_path+" ?",QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
        }


        if(reply == QMessageBox::Save){
            QString file_name = "";
          if(file_path == ""){
          //getting file name
              file_name = QFileDialog::getSaveFileName(this,"Open A File","C://Users","Text File(*.txt)");
          }else{
              file_name = file_path;
          }

          QFile file(file_name);

          if(!file.open(QFile::WriteOnly|QFile::Text)){
              if(file_name != "")
                QMessageBox::warning(this,"Cannot Open File","Cannot Open This File !!Some Error Occured");
              bar->ignore();
           }else{
          //file opened
              QTextStream out(&file);
              out<<ui->mainTextWindow->toPlainText();
          //after saving the text write to window title
              int size = file_name.split("/").size();
              QWidget::setWindowTitle(file_name.split("/")[size-1]);
              file.flush();
              file.close();
              file_path = file_name;
          }
        }else if(reply == QMessageBox::Cancel){
            bar->ignore();
        }
    }

    //bar->accept();
}

//whenever new is clicked we check if we have some chg made in text editor is save or not using textChg variable
//if no chgs made are not saved then prompt the user for saving or discard or cancel
//after successful completion show the new window
//in case if text editor is empty then no need to show prompt
void MainWindow::on_actionNew_triggered()
{
    if(textChg == 1 && (ui->mainTextWindow->toPlainText() != "" || file_path != "")){
        QMessageBox::StandardButton reply;
        if(file_path == ""){
            reply = QMessageBox::question(this,"MyNotepad",
            "Do You Want To Save The Changes to Untitled ?",QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
        }else{
            reply = QMessageBox::question(this,"MyNotepad",
            "Do You Want To Save The Changes to "+file_path+" ?",QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
        }


        if(reply == QMessageBox::Save){
            QString file_name = "";
          if(file_path == ""){
          //getting file name
              file_name = QFileDialog::getSaveFileName(this,"Open A File","C://Users","Text File(*.txt)");
          }else{
              file_name = file_path;
          }

          QFile file(file_name);

          if(!file.open(QFile::WriteOnly|QFile::Text)){
              if(file_name != "")
                QMessageBox::warning(this,"Cannot Open File","Cannot Open This File !!Some Error Occured");
              return;
           }else{
          //file opened
              QTextStream out(&file);
              out<<ui->mainTextWindow->toPlainText();
          //after saving the text write to window title
              int size = file_name.split("/").size();
              QWidget::setWindowTitle(file_name.split("/")[size-1]);
              file.flush();
              file.close();
              file_path = file_name;
          }
        }else if(reply == QMessageBox::Cancel){
            return;
        }
    }
     //setting name back to null
     file_path = "";
     ui->mainTextWindow->setText("");
     QWidget::setWindowTitle("Untitled - MyNotepad");
      textChg = 0;

}

//whenever opne is clicked we check if we have some chg made in existing file is saved or not using textChg variable
//if no chgs made are not saved then prompt the user for saving or discard or cancel
//after successful completion show the new window
void MainWindow::on_actionOpen_triggered()
{
    if(textChg == 1 && (ui->mainTextWindow->toPlainText() != "" || file_path != "")){
        QMessageBox::StandardButton reply;
        if(file_path == ""){
            reply = QMessageBox::question(this,"MyNotepad",
            "Do You Want To Save The Changes to Untitled ?",QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
        }else{
            reply = QMessageBox::question(this,"MyNotepad",
            "Do You Want To Save The Changes to "+file_path+" ?",QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
        }


        if(reply == QMessageBox::Save){
            QString file_name = "";
          if(file_path == ""){
          //getting file name
              file_name = QFileDialog::getSaveFileName(this,"Open A File","C://Users","Text File(*.txt)");
          }else{
              file_name = file_path;
          }

          QFile file(file_name);

          if(!file.open(QFile::WriteOnly|QFile::Text)){
              if(file_name != "")
                QMessageBox::warning(this,"Cannot Open File","Cannot Open This File !!Some Error Occured");
              return;

           }else{
          //file opened
              QTextStream out(&file);
              out<<ui->mainTextWindow->toPlainText();
          //after saving the text write to window title
              int size = file_name.split("/").size();
              QWidget::setWindowTitle(file_name.split("/")[size-1]);
              file.flush();
              file.close();
              file_path = file_name;
          }
        }else if(reply == QMessageBox::Cancel){
            return;
        }
    }

    //getting file name
    QString file_name = QFileDialog::getOpenFileName(this,"Open A File","C://Users","Text File(*.txt)");

    QFile file(file_name);

    if(!file.open(QFile::ReadOnly|QFile::Text)){
        //some error occured
//        QMessageBox::warning(this,"Cannot Open File","Cannot Open File !!Some Error Occured");
        return;
    }else{
        //file opened
        QTextStream in(&file);
        QString text = in.readAll();

        ui->mainTextWindow->setText(text);
        int size = file_name.split("/").size();
        QWidget::setWindowTitle(file_name.split("/")[size-1]);
        file.close();
        file_path = file_name;
    }
     textChg = 0;
}

void MainWindow::on_actionSave_triggered()
{

      QString file_name = "";
    if(file_path == ""){
    //getting file name
        file_name = QFileDialog::getSaveFileName(this,"Open A File","C://Users","Text File(*.txt)");
    }else{
        file_name = file_path;
    }

    QFile file(file_name);
    if(!file.open(QFile::WriteOnly|QFile::Text)){
    //some error occured
        QMessageBox::warning(this,"Cannot Open File","Cannot Open This File !!Some Error Occured");
     }else{
    //file opened
        QTextStream out(&file);
        out<<ui->mainTextWindow->toPlainText();
    //after saving the text write to window title
        int size = file_name.split("/").size();
        QWidget::setWindowTitle(file_name.split("/")[size-1]);
        file.flush();
        file.close();
        file_path = file_name;
        textChg = 0;
    }
}

void MainWindow::on_actionSave_As_triggered()
{
    QString file_name = "";

     //getting file name
     file_name = QFileDialog::getSaveFileName(this,"Open A File","C://Users","Text File(*.txt)");
  QFile file(file_name);
  if(!file.open(QFile::WriteOnly|QFile::Text)){
  //some error occured
      QMessageBox::warning(this,"Cannot Open File","Cannot Open This File !!Some Error Occured");

   }else{
  //file opened
      QTextStream out(&file);
      out<<ui->mainTextWindow->toPlainText();
  //after saving the text write to window title
      int size = file_name.split("/").size();
      QWidget::setWindowTitle(file_name.split("/")[size-1]);
      file.flush();
      file.close();
      file_path = file_name;
      textChg =0;
  }
}

void MainWindow::on_actionExit_triggered()
{
    if(textChg == 1 && (ui->mainTextWindow->toPlainText() != "" || file_path != "")){
        QMessageBox::StandardButton reply;
        if(file_path == ""){
            reply = QMessageBox::question(this,"MyNotepad",
            "Do You Want To Save The Changes to Untitled ?",QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
        }else{
            reply = QMessageBox::question(this,"MyNotepad",
            "Do You Want To Save The Changes to "+file_path+" ?",QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
        }


        if(reply == QMessageBox::Save){
            QString file_name = "";
          if(file_path == ""){
          //getting file name
              file_name = QFileDialog::getSaveFileName(this,"Open A File","C://Users","Text File(*.txt)");
          }else{
              file_name = file_path;
          }

          QFile file(file_name);

          if(!file.open(QFile::WriteOnly|QFile::Text)){
          //some error occured
              if(file_name != "")
                QMessageBox::warning(this,"Cannot Open File","Cannot Open This File !!Some Error Occured");
              return;
           }else{
          //file opened
              QTextStream out(&file);
              out<<ui->mainTextWindow->toPlainText();
          //after saving the text write to window title
              int size = file_name.split("/").size();
              QWidget::setWindowTitle(file_name.split("/")[size-1]);
              file.flush();
              file.close();
              file_path = file_name;
          }
        }else if(reply == QMessageBox::Cancel){
            return;
        }
    }
    QApplication::quit();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->mainTextWindow->undo();
}

void MainWindow::on_actionCut_triggered()
{
    ui->mainTextWindow->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->mainTextWindow->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->mainTextWindow->copy();
}

//whenever text is changed in window set textChg to 1
void MainWindow::on_mainTextWindow_textChanged()
{
    textChg = 1;
}

//show font dialog
void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);

    //if font is changed then set that font
    if(ok){
        ui->mainTextWindow->setFont(font);
    }
}

//setting text color using Color and ColorDialog
void MainWindow::on_actionText_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Text Color ...");

    if(color.isValid()){
        QPalette palette = ui->mainTextWindow->palette();

        palette.setColor(QPalette::Text,color);

        ui->mainTextWindow->setPalette(palette);

//        ui->mainTextWindow->setTextColor(color);
    }


}

//setting text background color
void MainWindow::on_actionSet_Text_Background_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Text Background Color ...");

    if(color.isValid()){
        ui->mainTextWindow->setTextBackgroundColor(color);

    }
}

//to print the page
void MainWindow::on_actionPrint_triggered()
{
    QPrinter print;
    print.setPrinterName("My Printer");

    QPrintDialog dialog(&print);

    if(dialog.exec() == QDialog::Rejected)
        return;

    ui->mainTextWindow->print(&print);

}

//to select all the text
void MainWindow::on_actionSelect_All_triggered()
{
    ui->mainTextWindow->selectAll();
}

//to get date time
void MainWindow::on_actionDate_Time_triggered()
{
    QString dt = QDateTime::currentDateTime().toString();
    ui->mainTextWindow->setText(ui->mainTextWindow->toPlainText()+dt);
}

//zoom in when zoom in is pressed
void MainWindow::on_actionZoom_In_triggered()
{
    ui->mainTextWindow->zoomIn();
}

//zooms out
void MainWindow::on_actionZoom_Out_triggered()
{
    ui->mainTextWindow->zoomOut();
}

void MainWindow::on_actionAbout_Us_triggered()
{
    QMessageBox::information(this,"About MyNotepad","MyNotepad version v1.0.0 Developed By Asmit Bajaj");
}

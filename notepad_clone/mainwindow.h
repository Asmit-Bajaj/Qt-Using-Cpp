#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionUndo_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();


    void on_mainTextWindow_textChanged();

    void on_actionFont_triggered();

    void on_actionText_Color_triggered();

    void on_actionSet_Text_Background_Color_triggered();

    void on_actionPrint_triggered();

    void on_actionSelect_All_triggered();

    void on_actionDate_Time_triggered();

    void closeEvent(QCloseEvent *bar);

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionAbout_Us_triggered();

private:
    Ui::MainWindow *ui;
    QString file_path;
    int textChg;

};
#endif // MAINWINDOW_H

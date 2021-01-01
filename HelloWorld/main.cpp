#include<QApplication>
#include<QLabel>

int main(int argc,char* argv[]){
    //here we are defining an object of application
    QApplication app(argc,argv);
    //creating a label
    QLabel *label = new QLabel("Hello World");

    //setting the title of window
    label->setWindowTitle("My First App");

    //defing the width and height
    label->resize(400,400);

    //showing the label
    label->show();

    //returns successful completion of application
    return app.exec();
}

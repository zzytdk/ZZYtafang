#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playbutton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(1200,700);
    ui->setupUi(this);
    Playbutton * play=new Playbutton(":/pic/playbutton.png");
    play->setParent(this);
    play->move(533,380);
    Mainmap *map =new Mainmap;
    connect(play,&Playbutton::clicked,this,[=](){
                this->close();
                map->show();
                });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix(":/pic/timg.jpg");
    QPixmap pix2(":/pic/Word2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    painter.drawPixmap(360,260,480,96,pix2);
}



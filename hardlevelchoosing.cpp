#include "hardlevelchoosing.h"


Hardlevelchoosing::Hardlevelchoosing(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1200,700);


    Playbutton *Hard_button=new Playbutton(QString(":/pic/hard.png"));
    Playbutton *Easy_button=new Playbutton(QString(":/pic/easy.png"));
    Hard_button->setParent(this);
    Easy_button->setParent(this);
    Hard_button->move(300,345);
    Easy_button->move(700,345);
    connect(Hard_button,&Playbutton::clicked,this,[=](){
                this->close();
                Mainmap *map =new Mainmap(2);
                map->show();
                });
    connect(Easy_button,&Playbutton::clicked,this,[=](){
                this->close();
                Mainmap *map =new Mainmap;
                map->show();
                });

}

void Hardlevelchoosing::paintEvent(QPaintEvent *){
  QPainter painter(this);
  QPixmap HardChoose(QString(":/pic/hardchoose.png"));
  painter.drawPixmap(400,150,HardChoose.width(),HardChoose.height(),HardChoose);
}

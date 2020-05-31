#include "mainmap.h"

Mainmap::Mainmap(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1200,700);
}
void Mainmap::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap background(":/pic/background.png");
    painter.drawPixmap(0,0,this->width(),this->height(),background);
}

#include "optionbox.h"

Optionbox::Optionbox(int index):BaseIndex(index)
{
    SetImage1(QString(":/pic/normtower.png"));
    SetImage2(QString(":/pic/firetower.png"));
    SetImage3(QString(":/pic/blacktower.png"));
    SetImage4(QString(":/pic/upgrade.png"));
    SetImage5(QString(":/pic/delete.png"));
    SetBoxImage(QString(":/pic/selectbox.png"));//设置图片路径
    switch(index)
    {
    case 1:
        x1=500-105;
        y1=150;
        x2=500;
        y2=150-105;
        x3=500+105;
        y3=150;
        x4=500;
        y4=150+105;
        x5=500+105;
        y5=150-105;
        break;
    case 2:
        x1=700-105;
        y1=150;
        x2=700;
        y2=150-105;
        x3=700+105;
        y3=150;
        x4=700;
        y4=150+105;
        x5=700+105;
        y5=150-105;
        break;

    case 3:
        x1=500-105;
        y1=450;
        x2=500;
        y2=450-105;
        x3=500+105;
        y3=450;
        x4=500;
        y4=450+105;
        x5=500+105;
        y5=450-105;
        break;
    case 4:
        x1=700-105;
        y1=450;
        x2=700;
        y2=450-105;
        x3=700+105;
        y3=450;
        x4=700;
        y4=450+105;
        x5=700+105;
        y5=450-105;
        break;//相应坑位的坐标
    }
}
void Optionbox::SetImage1(QString path1){
    QPixmap temp(path1);
    this->OptionImage_1=temp;
}
void Optionbox::SetImage2(QString path2){
    QPixmap temp(path2);
    this->OptionImage_2=temp;
}
void Optionbox::SetImage3(QString path3){
    QPixmap temp(path3);
    this->OptionImage_3=temp;
}
void Optionbox::SetImage4(QString path4){
    QPixmap temp(path4);
    this->OptionImage_4=temp;
}
void Optionbox::SetImage5(QString path5){
    QPixmap temp(path5);
    this->OptionImage_5=temp;
}
void Optionbox::SetBoxImage(QString path){
    QPixmap temp(path);
    this->Box=temp;
}

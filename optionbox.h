#ifndef OPTIONBOX_H
#define OPTIONBOX_H
#include <QPixmap>

class Optionbox
{
public:
    Optionbox(int index);
    void SetIfShow(bool ifshow){IfShow=ifshow;}
    void SetImage1(QString path1);
    void SetImage2(QString path2);
    void SetImage3(QString path3);
    void SetImage4(QString path4);
    void SetImage5(QString path5);
    void SetBoxImage(QString path);

    int GetX1(){return x1;}
    int GetX2(){return x2;}
    int GetX3(){return x3;}
    int GetX4(){return x4;}
    int GetY1(){return y1;}
    int GetY2(){return y2;}
    int GetY3(){return y3;}
    int GetY4(){return y4;}
    int GetY5(){return y5;}
    int GetX5(){return x5;}

    int GetIndex(){return this->BaseIndex;}
    QPixmap GetImage1(){return OptionImage_1;}
    QPixmap GetImage2(){return OptionImage_2;}
    QPixmap GetImage3(){return OptionImage_3;}
    QPixmap GetImage4(){return OptionImage_4;}
    QPixmap GetImage5(){return OptionImage_5;}
    QPixmap GetBoxImage(){return Box;}
    bool IfShow=false;

private:
    int BaseIndex;
    int x1,y1;
    int x2,y2;
    int x3,y3;
    int x4,y4;
    int x5,y5;
    QPixmap OptionImage_1;
    QPixmap OptionImage_2;
    QPixmap OptionImage_3;
    QPixmap OptionImage_4;
    QPixmap OptionImage_5;
    QPixmap Box;

};

#endif // OPTIONBOX_H

#ifndef TOWERBASE_H
#define TOWERBASE_H
#include <QPixmap>
#include <QString>


class Towerbase
{
public:
    Towerbase(int index);
    int GetX(){return this->Base_x;}
    int GetY(){return this->Base_y;}

    void SetX(int x){this->Base_x=x;}
    void SetY(int y){this->Base_y=y;}

    int GetHeight(){return this->Base_height;}
    int GetWidth(){return this->Base_width;}

    void SetHeight(int height){this->Base_height=height;}
    void SetWidth(int width){this->Base_width=width;}

    void SetImage(QString path);
    QPixmap GetImage(){return this->Base_image;}

private:
    int Base_x;
    int Base_y;
    QPixmap Base_image;
    int Base_index;
    int Base_width;
    int Base_height;
};

#endif // TOWERBASE_H

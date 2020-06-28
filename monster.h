#ifndef MONSTER_H
#define MONSTER_H


#include <QString>
#include "struct.h"
#include <QVector>
#include <QPixmap>

class Monster
{
public:
    Monster(int kind,point** path,int pathmun);
    QVector<point*> Monster_movepath;


    int GetX(){return Monster_x;}
    int GetY(){return Monster_y;}

    void SetX(int x){Monster_x=x;}
    void SetY(int y){Monster_y=y;}

    int GetLife(){return this->Monster_life;}

    int GetWidth(){return Monster_width;}
    int GetHeight(){return Monster_height;}

    void SetWidth(int width){Monster_width=width;}
    void SetHeight(int height){Monster_height=height;}

    void SetLife(int lifenow){Monster_life=lifenow;}
    void SetImage(QString path);

    QPixmap GetImage(){return this->Monster_image;}
    int GetMaxLife() const {return this->MaxLife;}


    void Monster_move();
    bool CanMove=true;
    bool IfShow=true;



private:
    int Monster_life;
    int MaxLife;
    int Monster_speed;
    int Monster_width;
    int Monster_height;
    int Monster_x;
    int Monster_y;
    int Monster_kind;
    int Pathnum;
    int PreAimIndex;//当前目标点（初始值为路径的第一个点）
    QString Monster_imagepath;
    QPixmap Monster_image;


};

#endif // MONSTER_H

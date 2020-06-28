#ifndef BULLET_H
#define BULLET_H
#include "tdobj.h"


class Bullet
{
public:
    Bullet(int kind,int x,int y,Monster* Aim);
    void Bullet_move();

    int GetX(){return this->Bullet_x;}
    int GetY(){return this->Bullet_y;}
    int GetSpeed(){return this->Bullet_speed;}
    int GetDamage(){return this->Bullet_damage;}
    int GetWidth(){return this->Bullet_width;}
    int GetHeight(){return this->Bullet_height;}
    int GetKind(){return this->Bullet_kind;}

    void SetX(int x){Bullet_x=x;}
    void SetY(int y){Bullet_y=y;}
    void SetImage(QString path);
    void SetSpeed(int speed){Bullet_speed=speed;}
    void SetDamage(int damage){Bullet_damage=damage;}
    void SetHeight(int height){Bullet_height=height;}
    void SetWidth(int width){Bullet_width=width;}

    QPixmap GetImage(){return this->Bullet_image;}



private:
    int Bullet_kind;
    int Bullet_x;
    int Bullet_y;
    int Bullet_width;
    int Bullet_height;
    QPixmap Bullet_image;
    Monster* AimMonster=NULL;
    int k=0,b=0;
    int Bullet_speed;
    int Bullet_damage;

};

#endif // BULLET_H

#include "bullet.h"

Bullet::Bullet(int kind,int x,int y,Monster* Aim):Bullet_kind(kind), Bullet_x(x),Bullet_y(y)
{
    SetSpeed(50);
    switch(kind)
    {
    case 1:
        SetDamage(10);
        SetWidth(5);
        SetHeight(5);
        SetImage(QString(":/pic/bullet1.png"));

        break;
    case 2:
        SetDamage(50);
        SetWidth(10);
        SetHeight(10);
        SetImage(QString(":/pic/bullet2.png"));
        break;
    case 3:
        SetDamage(20);
        SetWidth(10);
        SetHeight(10);
        SetImage(QString(":/pic/bullet3.png"));
        break;
    }
    AimMonster=Aim;
    k=(Bullet_y-AimMonster->GetY()+AimMonster->GetHeight()/2)/(Bullet_x-AimMonster->GetX()+AimMonster->GetWidth());
    b=AimMonster->GetY()+AimMonster->GetHeight()/2-k*(AimMonster->GetX()+AimMonster->GetWidth());
}
void Bullet::SetImage(QString path){
    QPixmap temp(path);
    Bullet_image=temp;
}
void Bullet::Bullet_move(){


    Bullet_x<AimMonster->GetX()+AimMonster->GetWidth() ? Bullet_x+=k*Bullet_speed : Bullet_x-=k*Bullet_speed;
    Bullet_y=k*Bullet_x+b;







}

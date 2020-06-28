#ifndef TDOBJ_H
#define TDOBJ_H
#include <QImage>
#include <QPainter>
#include <string>
#include <map>
#include <QPixmap>
#include <QString>
#include "monster.h"
#include "bullet.h"

class Bullet;

class Tdobj
{
public:
    int GetX(){return Obj_x;}
    int GetY(){return Obj_y;}

    void SetX(int x){Obj_x=x;}
    void SetY(int y){Obj_y=y;}

    int GetHeight(){return this->Obj_height;}
    int GetWidth(){return this->Obj_width;}

    void SetHeight(int height){this->Obj_height=height;}
    void SetWidth(int width){this->Obj_width=width;}

    int GetDamage(){return this->Obj_damage;}
    void SetDamage(int damage){this->Obj_damage=damage;}

    int GetPrice(){return this->Obj_price;}
    void SetPrice(int price){this->Obj_price=price;}

    void SetAimMonster(Monster* aimmonster){PreAimMonster=aimmonster;}
    Monster* GetAimMonster(){return PreAimMonster;}


    int GetRange(){return Obj_range;}
    void SetRange(int range){Obj_range=range;}

    void SetImage(QString path);

    void Upgrade();
    QPixmap GetImage(){return Obj_image;}

    void BulletMove();

    void AddBullet();

    bool IfShow=true;


    QVector<Bullet*>& GetBulletList(){return BulletList;}
    int GetKind(){return this->kind;}








protected:
    int kind;
    int Obj_x;
    int Obj_y;
    int Obj_height;
    int Obj_width;
    int Obj_price;
    QPixmap Obj_image;
    Monster* PreAimMonster=NULL;
    int Obj_damage;
    int Obj_range;
    QVector<Bullet*> BulletList;


  
};

#endif // TDOBJ_H

#include "tdobj.h"
#include <iostream>

void Tdobj::SetImage(QString path){
    QPixmap temp(path);
    Obj_image=temp;
}
void Tdobj::Upgrade(){
    this->SetDamage(Obj_damage+5);
}

void Tdobj::BulletMove(){
    for(auto bullet =BulletList.begin();bullet!=BulletList.end();bullet++){

        (*bullet)->Bullet_move();

        if ((*bullet)->GetX()<=20 || (*bullet)->GetX()>=1100 ||(*bullet)->GetY()<=150 ||(*bullet)->GetY()>=450){
            delete *bullet;
            BulletList.erase(bullet);
        }
        }

}

void Tdobj::AddBullet(){

    Bullet *zidan=new Bullet(kind,Obj_x+40,Obj_y,PreAimMonster);
    BulletList.push_back(zidan);
}



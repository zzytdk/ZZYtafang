#include "monster.h"



Monster::Monster(int kind,point** path,int pathnum):Monster_kind(kind)
{
    this->Monster_width=60;
    this->Monster_height=90;
    PreAimIndex=1;

    for (int i=0;i<pathnum;i++){

        Monster_movepath.push_back(path[i]);
    }
    SetX(path[0]->Point_x);
    SetY(path[0]->Point_y);

    switch(kind)
    {
        case 1:
            Monster_life=600;
            MaxLife=600;
            Monster_speed=12;
            Monster_imagepath=":/pic/monster1.png";
            break;
        case 2:
            Monster_life=800;
            MaxLife=800;
            Monster_speed=20;
            Monster_imagepath=":/pic/monster2.png";
            break;
        case 3:
            Monster_life=4000;
            MaxLife=4000;
            Monster_speed=8;
            Monster_imagepath=":/pic/monster3.png";
            break;

         default:
            break;


    }
    SetImage(Monster_imagepath);

}
void Monster::Monster_move(){

    if(CanMove==false){IfShow=false;return;}
    if (Monster_x==Monster_movepath.at(1)->Point_x && Monster_y==Monster_movepath.at(1)->Point_y){
        CanMove=false;
        return;}



    if (Monster_movepath.at(1)->Point_x>Monster_x)
        Monster_x+=Monster_speed;

    if (Monster_movepath.at(1)->Point_x<Monster_x)
        Monster_x-=Monster_speed;

    if (Monster_movepath.at(1)->Point_y>Monster_y)
        Monster_y+=Monster_speed;

    if (Monster_movepath.at(1)->Point_y<Monster_y)
        Monster_y-=Monster_speed;

}



void Monster::SetImage(QString path){
    QPixmap temp(path);
    this->Monster_image=temp;


}

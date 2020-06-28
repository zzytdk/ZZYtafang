#include "normtower.h"


Normtower::Normtower(int x,int y)
{
    this->SetX(x);
    this->SetY(y);
    SetWidth(100);
    SetHeight(120);
    this->Obj_damage=20;
    this->Obj_price=20;
    this->Obj_range=250;
    this->SetImage(QString(":/pic/normtower.png"));
    kind=1;

}

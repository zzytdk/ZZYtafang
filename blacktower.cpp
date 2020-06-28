#include "blacktower.h"

Blacktower::Blacktower(int x,int y)
{
    SetX(x);
    SetY(y);
    SetWidth(80);
    SetHeight(120);
    SetDamage(50);
    SetPrice(100);
    SetRange(200);
    SetImage(QString(":/pic/blacktower.png"));
    kind=3;
}

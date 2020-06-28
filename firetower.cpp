#include "firetower.h"

Firetower::Firetower(int x,int y)
{
   SetX(x);
   SetY(y);
   SetWidth(80);
   SetHeight(120);
   SetPrice(60);
   SetDamage(5);
   SetRange(275);
   SetImage(QString(":/pic/firetower.png"));
   kind=2;
}

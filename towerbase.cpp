#include "towerbase.h"

Towerbase::Towerbase(int index):Base_index(index)
{
    this->SetImage(QString(":/pic/towerbase.png"));
    switch(index){
    case 1:
        SetHeight(100);
        SetWidth(100);
        SetX(500);
        SetY(150);
        break;
    case 2:
        SetHeight(100);
        SetWidth(100);
        SetX(700);
        SetY(150);
        break;
    case 3:
        SetHeight(100);
        SetWidth(100);
        SetX(500);
        SetY(450);
        break;
    case 4:
        SetHeight(100);
        SetWidth(100);
        SetX(700);
        SetY(450);
        break;
    }

}
void Towerbase::SetImage(QString path){
    QPixmap temp(path);
    this->Base_image=temp;
}

#include "tdobj.h"
#include <iostream>

void Tdobj::initObj(string type)
{


}
void Tdobj::show(QPainter * pa){
    int gSize = Icon::GRID_SIZE;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}


void Tdobj::onErase(){

}


#ifndef TDOBJ_H
#define TDOBJ_H
#include <QImage>
#include <QPainter>
#include <string>
#include <icon.h>
#include <map>
using namespace std;


class Tdobj
{
public:
    Tdobj(){};
    void initObj(string type);
    void show(QPainter * painter);

    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}

    int getPosX() const{return this->_pos_x;}
    int getPosY() const{return this->_pos_y;}
    int getHeight() const{return this->_icon.getHeight();}
    int getWidth() const{return this->_icon.getWidth();}

    bool canSee() const{return this->_seeable;}
    bool canAttack() const{return this->_attackable;}


    virtual void onErase();

    string getObjType() const{return this->_icon.getTypeName();}

protected:


    QImage _pic;
    int _pos_x, _pos_y;
    Icon _icon;
    bool _seeable;
    bool _attackable;

  
};

#endif // TDOBJ_H

#include "icon.h"
#include<iostream>
int Icon::GRID_SIZE = 32;


pair<string,Icon> pairArray[] =
{
    make_pair("player",Icon("player",1,13, 1, 2)),
    make_pair("stone",Icon("stone",4,9, 1, 1)),
    make_pair("fruit",Icon("fruit",3,6, 1, 1))//待修改
};

map<string,Icon> Icon::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));


Icon::Icon(string name, int x, int y, int w, int h){
    this->typeName = name;
    this->srcX = x;
    this->srcY = y;
    this->width = w;
    this->height = h;
}

Icon Icon::findIcon(string type){
    map<string,Icon>::iterator kv;
    kv = Icon::GAME_ICON_SET.find(type);
    if (kv==Icon::GAME_ICON_SET.end()){

       cout<<"Error: cannot find ICON"<<endl;
       return Icon();
    }
    else{
        return kv->second;
    }
}

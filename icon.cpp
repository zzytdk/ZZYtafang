#include "icon.h"
#include<iostream>
int Icon::GRID_SIZE = 32;


pair<string,Icon> pairArray[] =
{
    make_pair("road1",Icon("road1",0,1,1,1)),
    make_pair("road2",Icon("road2",1,1,1,1)),
    make_pair("road3",Icon("road3",2,1,1,1)),
    make_pair("road4",Icon("road4",4,1,1,1)),
    make_pair("tree1",Icon("tree1",5,9,1,2)),
    make_pair("tree2",Icon("tree2",0,12,2,2)),
    make_pair("trees",Icon("trees",2,12,2,2)),


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

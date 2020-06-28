#ifndef MAINMAP_H
#define MAINMAP_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QPushButton>
#include <QTimer>
#include "towerbase.h"
#include "normtower.h"
#include "firetower.h"
#include "blacktower.h"
#include "optionbox.h"
#include <cmath>
#include <QDebug>
#include <QLabel>
#include <string>
#include <QtMultimedia/QMediaPlayer>

using namespace std;


class Mainmap : public QWidget
{

public:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);


    int Life=5;
    int Money=20;
    int Monster_number=0;

    void SetMonsterWave(int hardlevel=1);
    QVector<Monster*> MonsterList;
    QVector<Tdobj*> TowerList;
    point* Monster_path[2] = {new point(20,300),new point(1100,300)};
    QVector<Optionbox*> OptionboxList;

    bool CanSpend(int money);
    QLabel *MoneyLabel=new QLabel(this);
    QLabel *WinLabel =new QLabel(this);
    QMediaPlayer * player = new QMediaPlayer;




    void DrawTowerbase(QPainter& painter);
    void DrawTower(QPainter& painter);
    void DrawMonster(QPainter& painter);
    void DrawSelectBox(QPainter& painter,int index);


    Mainmap(int hardlevel=1);
    ~Mainmap();


};

#endif // MAINMAP_H

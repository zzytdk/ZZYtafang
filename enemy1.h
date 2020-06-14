#ifndef ENEMY1_H
#define ENEMY1_H

#include <QObject>
#include <tdobj.h>

class Enemy1 : public QObject,public Tdobj
{
    Q_OBJECT
public:
    explicit Enemy1(QObject *parent = nullptr);
    void findobj();
    void attack();
    int getSide(){return this->side;}
    void move();


signals:

public slots:
private:

    int life;
    int damage;
    int side;
};

#endif // ENEMY1_H

#ifndef ENEMY2_H
#define ENEMY2_H

#include <QObject>
#include <tdobj.h>

class Enemy2 : public QObject,public Tdobj
{
    Q_OBJECT
public:
    explicit Enemy2(QObject *parent = nullptr);
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

#endif // ENEMY2_H

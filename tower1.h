#ifndef TOWER1_H
#define TOWER1_H

#include <QObject>
#include <tdobj.h>

class Tower1 : public QObject,public Tdobj
{
    Q_OBJECT
public:
    explicit Tower1(QObject *parent = nullptr);
    void findEnemy();
    void attack();

signals:

public slots:
private:
    int life;
    int damage;
    int sort;
};

#endif // TOWER1_H

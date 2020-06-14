#ifndef TOWER2_H
#define TOWER2_H

#include <QObject>
#include <tdobj.h>

class Tower2 : public QObject,public Tdobj
{
    Q_OBJECT
public:
    explicit Tower2(QObject *parent = nullptr);
    void findEnemy();
    void attack();

signals:

public slots:

private:
    int life;
    int damage;
    int sort;
};

#endif // TOWER2_H

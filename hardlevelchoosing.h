#ifndef HARDLEVELCHOOSING_H
#define HARDLEVELCHOOSING_H

#include <QWidget>
#include "playbutton.h"
#include "mainmap.h"

class Hardlevelchoosing : public QWidget
{
    Q_OBJECT
public:
    explicit Hardlevelchoosing(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);


signals:

public slots:
};

#endif // HARDLEVELCHOOSING_H

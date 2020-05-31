#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include <QWidget>
#include <QPushButton>

class Playbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit Playbutton(QString path);

signals:

public slots:
};

#endif // PLAYBUTTON_H

#include "playbutton.h"
#include <QPixmap>
Playbutton::Playbutton(QString path) : QPushButton(0)
{
    QPixmap play(path);
    this->setFixedSize(play.width(),play.height());
    this->setStyleSheet("QPushButton{border:Opx}");
    this->setIcon(play);
    this->setIconSize(QSize(play.width(),play.height()));
}


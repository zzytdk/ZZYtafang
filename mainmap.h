#ifndef MAINMAP_H
#define MAINMAP_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
namespace ui{
class Mainmap;
}

class Mainmap : public QMainWindow
{
    Q_OBJECT
public:
    void paintEvent(QPaintEvent *);
    explicit Mainmap(QWidget *parent = nullptr);

signals:

public slots:
private:
    QTimer *timer;
};

#endif // MAINMAP_H

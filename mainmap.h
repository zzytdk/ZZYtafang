#ifndef MAINMAP_H
#define MAINMAP_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>

class Mainmap : public QMainWindow
{
    Q_OBJECT
public:
    void paintEvent(QPaintEvent *);
    explicit Mainmap(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // MAINMAP_H

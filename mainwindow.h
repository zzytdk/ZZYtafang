#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "mainmap.h"
#include <QtMultimedia/QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent *);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

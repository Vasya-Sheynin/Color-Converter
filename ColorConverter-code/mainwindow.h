
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "colorpanel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void hexInputTextChanged();

private:
    Ui::MainWindow *ui;

    QGridLayout *grid1;
    QGridLayout *grid2;
    QGridLayout *grid3;

    ColorPanel *panel1;
    ColorPanel *panel2;
    ColorPanel *panel3;

    int red;
    int green;
    int blue;

    void mouseMoveEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent*);

    void setColor(int x, int y);
    QString RGBToHex(int r, int g, int b);

    void colorSignalProcess(QColor color);
};

#endif // MAINWINDOW_H

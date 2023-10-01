
#ifndef COLORPANEL_H
#define COLORPANEL_H

#include <QtWidgets>

class ColorPanel : public QWidget
{

    Q_OBJECT

public:
    enum ColorType {RGB, CMYK, HSV, HLS, XYZ, LAB};

    explicit ColorPanel(QWidget *parent = nullptr);
    void createPanel(QGridLayout* grid, ColorType type, double val1, double val2, double val3);
    void setColorComponents(double val1, double val2, double val3);

signals:
    void colorSignal(QColor color);

private:
    const double eps = 1.0;

    double component1;
    double component2;
    double component3;
    double component4;

    ColorType type;

    QSlider *slider1 = new QSlider(Qt::Horizontal);
    QSlider *slider2 = new QSlider(Qt::Horizontal);
    QSlider *slider3 = new QSlider(Qt::Horizontal);
    QSlider *slider4 = new QSlider(Qt::Horizontal);

    QLabel *colorLabel = new QLabel();
    QLabel *lbl1 = new QLabel();
    QLabel *lbl2 = new QLabel();
    QLabel *lbl3 = new QLabel();
    QLabel *lbl4 = new QLabel();

    QLineEdit *line1 = new QLineEdit();
    QLineEdit *line2 = new QLineEdit();
    QLineEdit *line3 = new QLineEdit();
    QLineEdit *line4 = new QLineEdit();

    void sendColor();

    void RGBtoCMYK(int r, int g, int b, double &comp1, double &comp2, double &comp3, double &comp4);
    void RGBtoHSV(int r, int g, int b, double &comp1, double &comp2, double &comp3);
    void RGBtoHSL(int r, int g, int b, double &comp1, double &comp2, double &comp3);
    void RGBtoLAB(int r, int g, int b, double &comp1, double &comp2, double &comp3);
    void RGBtoXYZ(int r, int g, int b, double &comp1, double &comp2, double &comp3);

    void CMYKtoRGB(int &r, int &g, int &b, double comp1, double comp2, double comp3, double comp4);
    void HSVtoRGB(int &r, int &g, int &b, double comp1, double comp2, double comp3);
    void HSLtoRGB(int &r, int &g, int &b, double comp1, double comp2, double comp3);
    void LABtoRGB(int &r, int &g, int &b, double comp1, double comp2, double comp3);
    void XYZtoRGB(int &r, int &g, int &b, double comp1, double comp2, double comp3);
};

#endif // COLORPANEL_H


#include "colorpanel.h"

ColorPanel::ColorPanel(QWidget *parent)
    : QWidget{parent}
{
    connect(slider1, &QSlider::sliderMoved, this, [=](int value) {
        component1 = slider1->value();
        line1->setText(QString::number(value));
        sendColor();
    });

    connect(slider2, &QSlider::sliderMoved, this, [=](int value) {
        component2 = slider2->value();
        line2->setText(QString::number(value));      
        sendColor();
    });

    connect(slider3, &QSlider::sliderMoved, this, [=](int value) {
        component3 = slider3->value();
        line3->setText(QString::number(value));
        sendColor();
    });

    connect(slider4, &QSlider::sliderMoved, this, [=](int value) {
        component4 = slider4->value();
        line4->setText(QString::number(value));
        sendColor();
    });

    connect(line1, &QLineEdit::textEdited, this, [=]() {
        component1 = line1->text().toDouble();
        slider1->setSliderPosition(line1->text().toInt());
        sendColor();
    });

    connect(line2, &QLineEdit::textEdited, this, [=]() {
        component2 = line2->text().toDouble();
        slider2->setSliderPosition(line2->text().toInt());
        sendColor();
    });

    connect(line3, &QLineEdit::textEdited, this, [=]() {
        component3 = line3->text().toDouble();
        slider3->setSliderPosition(line3->text().toInt());
        sendColor();
    });

    connect(line4, &QLineEdit::textEdited, this, [=]() {
        component4 = line4->text().toDouble();
        slider4->setSliderPosition(line4->text().toInt());
        sendColor();
    });
}

void ColorPanel::createPanel(QGridLayout *grid, ColorType type, double val1, double val2, double val3)
{
    this->type = type;

    QString font = "font: 12pt Segoe UI;";

    colorLabel->setStyleSheet(font);

    lbl1->setStyleSheet(font);
    lbl2->setStyleSheet(font);
    lbl3->setStyleSheet(font);
    lbl4->setStyleSheet(font);

    line1->setStyleSheet(font);
    line2->setStyleSheet(font);
    line3->setStyleSheet(font);
    line4->setStyleSheet(font);

    grid->addWidget(colorLabel, 0, 0, 1, 3, Qt::AlignCenter);
    grid->addWidget(lbl1, 1, 0, Qt::AlignCenter);
    grid->addWidget(lbl2, 2, 0, Qt::AlignCenter);
    grid->addWidget(lbl3, 3, 0, Qt::AlignCenter);
    grid->addWidget(line1, 1, 1, Qt::AlignCenter);
    grid->addWidget(line2, 2, 1, Qt::AlignCenter);
    grid->addWidget(line3, 3, 1, Qt::AlignCenter);
    grid->addWidget(slider1, 1, 2);
    grid->addWidget(slider2, 2, 2);
    grid->addWidget(slider3, 3, 2);

    line1->setMaximumSize(92, 25);
    line2->setMaximumSize(92, 25);
    line3->setMaximumSize(92, 25);
    line4->setMaximumSize(92, 25);

    grid->setColumnStretch(2, 1);
    grid->setHorizontalSpacing(25);

    setColorComponents(val1, val2, val3);

    switch (type)
    {
    case ColorType::CMYK:
    {
        slider4->show();
        lbl4->show();
        line4->show();

        grid->addWidget(lbl4, 4, 0, Qt::AlignCenter);
        grid->addWidget(line4, 4, 1, Qt::AlignCenter);
        grid->addWidget(slider4, 4, 2);

        colorLabel->setText("<center> Color model: CMYK </center>");

        lbl1->setText("<center> C </center>");
        lbl2->setText("<center> M </center>");
        lbl3->setText("<center> Y </center>");
        lbl4->setText("<center> K </center>");

        QRegExpValidator *validator = new QRegExpValidator(
            QRegExp("^(0|[1-9]\\d?|100)$"));

        line1->setText(QString::number(qRound(component1)));
        line2->setText(QString::number(qRound(component2)));
        line3->setText(QString::number(qRound(component3)));
        line4->setText(QString::number(qRound(component4)));

        line1->setValidator(validator);
        line2->setValidator(validator);
        line3->setValidator(validator);
        line4->setValidator(validator);

        slider1->setRange(0, 100);
        slider2->setRange(0, 100);
        slider3->setRange(0, 100);
        slider4->setRange(0, 100);

        slider1->setValue(component1);
        slider2->setValue(component2);
        slider3->setValue(component3);
        slider4->setValue(component4);

        break;
    }
    case ColorType::HLS:
    {
        slider4->hide();
        lbl4->hide();
        line4->hide();

        colorLabel->setText("<center> Color model: HSL </center>");

        lbl1->setText("<center> H </center>");
        lbl2->setText("<center> S </center>");
        lbl3->setText("<center> L </center>");

        QRegExpValidator *validator1 = new QRegExpValidator(
            QRegExp("^(0|[1-9]\\d?|100)$"));

        QRegExpValidator *validator2 = new QRegExpValidator(
            QRegExp("^(0|[1-9]\\d?|1\\d\\d|2\\d\\d|3[0-5]\\d|360)$"));

        line1->setText(QString::number(qRound(component1)));
        line2->setText(QString::number(qRound(component2)));
        line3->setText(QString::number(qRound(component3)));

        line1->setValidator(validator2);
        line2->setValidator(validator1);
        line3->setValidator(validator1);

        slider1->setRange(0, 360);
        slider2->setRange(0, 100);
        slider3->setRange(0, 100);

        slider1->setValue(component1);
        slider2->setValue(component2);
        slider3->setValue(component3);

        break;
    }
    case ColorType::HSV:
    {
        slider4->hide();
        lbl4->hide();
        line4->hide();

        colorLabel->setText("<center> Color model: HSV </center>");

        lbl1->setText("<center> H </center>");
        lbl2->setText("<center> S </center>");
        lbl3->setText("<center> V </center>");

        QRegExpValidator *validator1 = new QRegExpValidator(
            QRegExp("^(0|[1-9]\\d?|100)$"));

        QRegExpValidator *validator2 = new QRegExpValidator(
            QRegExp("^(0|[1-9]\\d?|1\\d\\d|2\\d\\d|3[0-5]\\d|360)$"));

        line1->setText(QString::number(qRound(component1)));
        line2->setText(QString::number(qRound(component2)));
        line3->setText(QString::number(qRound(component3)));

        line1->setValidator(validator2);
        line2->setValidator(validator1);
        line3->setValidator(validator1);

        slider1->setRange(0, 360);
        slider2->setRange(0, 100);
        slider3->setRange(0, 100);

        slider1->setValue(component1);
        slider2->setValue(component2);
        slider3->setValue(component3);

        break;
    }
    case ColorType::LAB:
    {
        slider4->hide();
        lbl4->hide();
        line4->hide();

        colorLabel->setText("<center> Color model: LAB </center>");

        lbl1->setText("<center> L </center>");
        lbl2->setText("<center> A </center>");
        lbl3->setText("<center> B </center>");

        QRegExpValidator *validator1 = new QRegExpValidator(
            QRegExp("^(0|[1-9]\\d?|100)$"));

        QRegExpValidator *validator2 = new QRegExpValidator(
            QRegExp("^-?(0|[1-9]\\d?|100)$"));

        line1->setText(QString::number(qRound(component1)));
        line2->setText(QString::number(qRound(component2)));
        line3->setText(QString::number(qRound(component3)));

        line1->setValidator(validator1);
        line2->setValidator(validator2);
        line3->setValidator(validator2);

        slider1->setRange(0, 100);
        slider2->setRange(-128, 128);
        slider3->setRange(-128, 128);

        slider1->setValue(component1);
        slider2->setValue(component2);
        slider3->setValue(component3);

        break;
    }
    case ColorType::RGB:
    {
        slider4->hide();
        lbl4->hide();
        line4->hide();

        colorLabel->setText("<center> Color model: RGB </center>");

        lbl1->setText("<center> R </center>");
        lbl2->setText("<center> G </center>");
        lbl3->setText("<center> B </center>");

        QRegExpValidator *validator = new QRegExpValidator(
            QRegExp("^(0|[1-9]\\d?|1\\d\\d|2[0-4]\\d|25[0-5])$"));

        line1->setText(QString::number(qRound(component1)));
        line2->setText(QString::number(qRound(component2)));
        line3->setText(QString::number(qRound(component3)));

        line1->setValidator(validator);
        line2->setValidator(validator);
        line3->setValidator(validator);

        slider1->setRange(0, 255);
        slider2->setRange(0, 255);
        slider3->setRange(0, 255);

        slider1->setValue(component1);
        slider2->setValue(component2);
        slider3->setValue(component3);

        break;
    }
    case ColorType::XYZ:
    {
        slider4->hide();
        lbl4->hide();
        line4->hide();

        colorLabel->setText("<center> Color model: XYZ </center>");

        lbl1->setText("<center> X </center>");
        lbl2->setText("<center> Y </center>");
        lbl3->setText("<center> Z </center>");

        QRegExpValidator *validator1 = new QRegExpValidator(
            QRegExp("^(0|[1-8]\\d?|9[0-5])$"));

        QRegExpValidator *validator2 = new QRegExpValidator(
            QRegExp("^(0|[1-9]\\d?|100)$"));

        QRegExpValidator *validator3 = new QRegExpValidator(
            QRegExp("^(0|[1-9]\\d?|10\\d)$"));

        line1->setText(QString::number(qRound(component1)));
        line2->setText(QString::number(qRound(component2)));
        line3->setText(QString::number(qRound(component3)));

        line1->setValidator(validator1);
        line2->setValidator(validator2);
        line3->setValidator(validator3);

        slider1->setRange(0, 95);
        slider2->setRange(0, 100);
        slider3->setRange(0, 109);

        slider1->setValue(component1);
        slider2->setValue(component2);
        slider3->setValue(component3);

        break;
    }
    }
}

void ColorPanel::setColorComponents(double val1, double val2, double val3)
{
    switch (type)
    {
    case ColorType::CMYK:
    {
        RGBtoCMYK(val1, val2, val3, component1, component2, component3, component4);

        line1->setText(QString::number(qRound(component1)));
        line2->setText(QString::number(qRound(component2)));
        line3->setText(QString::number(qRound(component3)));
        line4->setText(QString::number(qRound(component4)));

        slider1->setSliderPosition(qRound(component1));
        slider2->setSliderPosition(qRound(component2));
        slider3->setSliderPosition(qRound(component3));
        slider4->setSliderPosition(qRound(component4));

        break;
    }
    case ColorType::HLS:
    {
        RGBtoHSL(val1, val2, val3, component1, component2, component3);

        line1->setText(QString::number(qRound(component1)));
        line2->setText(QString::number(qRound(component2)));
        line3->setText(QString::number(qRound(component3)));

        slider1->setSliderPosition(qRound(component1));
        slider2->setSliderPosition(qRound(component2));
        slider3->setSliderPosition(qRound(component3));

        break;
    }
    case ColorType::HSV:
    {
        RGBtoHSV(val1, val2, val3, component1, component2, component3);
        line1->setText(QString::number(qRound(component1)));
        line2->setText(QString::number(qRound(component2)));
        line3->setText(QString::number(qRound(component3)));

        slider1->setSliderPosition(qRound(component1));
        slider2->setSliderPosition(qRound(component2));
        slider3->setSliderPosition(qRound(component3));

        break;
    }
    case ColorType::LAB:
    {
        RGBtoLAB(val1, val2, val3, component1, component2, component3);

        line1->setText(QString::number(qRound(component1)));
        line2->setText(QString::number(qRound(component2)));
        line3->setText(QString::number(qRound(component3)));

        slider1->setSliderPosition(qRound(component1));
        slider2->setSliderPosition(qRound(component2));
        slider3->setSliderPosition(qRound(component3));

        break;
    }
    case ColorType::RGB:
    {
        component1 = val1;
        component2 = val2;
        component3 = val3;

        line1->setText(QString::number(val1));
        line2->setText(QString::number(val2));
        line3->setText(QString::number(val3));

        slider1->setSliderPosition(val1);
        slider2->setSliderPosition(val2);
        slider3->setSliderPosition(val3);

        break;
    }
    case ColorType::XYZ:
    {
        RGBtoXYZ(val1, val2, val3, component1, component2, component3);

        line1->setText(QString::number(qRound(component1)));
        line2->setText(QString::number(qRound(component2)));
        line3->setText(QString::number(qRound(component3)));

        slider1->setSliderPosition(qRound(component1));
        slider2->setSliderPosition(qRound(component2));
        slider3->setSliderPosition(qRound(component3));

        break;
    }
    }
}

void ColorPanel::sendColor()
{
    int r, g, b;

    switch (type)
    {
    case ColorType::CMYK:
    {
        CMYKtoRGB(r, g, b, component1, component2, component3, component4);
        break;
    }
    case ColorType::HLS:
    {
        HSLtoRGB(r, g, b, component1, component2, component3);
        break;
    }
    case ColorType::HSV:
    {
        HSVtoRGB(r, g, b, component1, component2, component3);
        break;
    }
    case ColorType::LAB:
    {
        LABtoRGB(r, g, b, component1, component2, component3);
        break;
    }
    case ColorType::RGB:
    {
        r = component1;
        g = component2;
        b = component3;
        break;
    }
    case ColorType::XYZ:
    {
        XYZtoRGB(r, g, b, component1, component2, component3);
        break;
    }
    }

    emit colorSignal(QColor(r, g, b));
}

void ColorPanel::RGBtoCMYK(int r, int g, int b, double &comp1, double &comp2, double &comp3, double &comp4)
{
    comp4 = qMin(1.0 - (double)r / 255, qMin(1.0 - (double)g / 255, 1.0 - (double)b / 255)) * 100;
    comp1 = (1 - (double)r / 255 - comp4 / 100) / (1 - comp4 / 100) * 100;
    comp2 = (1 - (double)g / 255 - comp4 / 100) / (1 - comp4 / 100) * 100;
    comp3 = (1 - (double)b / 255 - comp4 / 100) / (1 - comp4 / 100) * 100;
}

void ColorPanel::RGBtoHSV(int r, int g, int b, double &comp1, double &comp2, double &comp3)
{
    double R = r / 255.0;
    double G = g / 255.0;
    double B = b / 255.0;
    double cMax = qMax(R, qMax(G, B));
    double cMin = qMin(R, qMin(G, B));
    double delta = cMax - cMin;

    comp2 = cMax == 0 ? 0 : (delta / cMax) * 100;
    comp3 = cMax * 100;

    if (delta == 0.0)
    {
        comp1 = 0;
    }

    if (cMax == R)
    {
        comp1 = 60 * ((G - B) / delta);

        if (G < B)
        {
            comp1 += 360;
        }
    }
    else if (cMax == G)
    {
        comp1 = 60 * ((B - R) / delta + 2);
    }
    else
    {
        comp1 = 60 * ((R - G) / delta + 4);
    }
}

void ColorPanel::RGBtoHSL(int r, int g, int b, double &comp1, double &comp2, double &comp3)
{
    double R = r / 255.0;
    double G = g / 255.0;
    double B = b / 255.0;
    double cMax = qMax(R, qMax(G, B));
    double cMin = qMin(R, qMin(G, B));
    double delta = cMax - cMin;

    comp3 = (cMax + cMin) / 2;

    if (delta == 0)
    {
        comp2 = 0;
    }
    else if (comp3 <= 0.5)
    {
        comp2 = delta / (2 * comp3);
    }
    else
    {
        comp2 = delta / (2 - 2 * comp3);
    }

    comp2 *= 100;
    comp3 *= 100;

    if (delta == 0.0)
    {
        comp1 = 0;
    }

    if (cMax == R)
    {
        if (G >= B)
        {
            comp1 = 60 * ((G - B) / delta);
        }
        else
        {
            comp1 = 60 * ((G - B) / delta) + 360;
        }
    }
    else if (cMax == G)
    {
        comp1 = 60 * ((B - R) / delta + 2);
    }
    else
    {
        comp1 = 60 * ((R - G) / delta + 4);
    }
}

void ColorPanel::RGBtoXYZ(int r, int g, int b, double &comp1, double &comp2, double &comp3)
{
    double R = r / 255.0;
    double G = g / 255.0;
    double B = b / 255.0;

    R = R >= 0.04045 ? (pow(((R + 0.055) / 1.055), 2.4) * 100) : (R / 12.92 * 100);
    G = G >= 0.04045 ? (pow(((G + 0.055) / 1.055), 2.4) * 100) : (G / 12.92 * 100);
    B = B >= 0.04045 ? (pow(((B + 0.055) / 1.055), 2.4) * 100) : (B / 12.92 * 100);

    comp1 = 0.412453 * R + 0.357580 * G + 0.180423 * B;
    comp2 = 0.212671 * R + 0.715160 * G + 0.072169 * B;
    comp3 = 0.019334 * R + 0.119193 * G + 0.950227 * B;
}

void ColorPanel::RGBtoLAB(int r, int g, int b, double &comp1, double &comp2, double &comp3)
{
    double X, Y, Z;

    RGBtoXYZ(r, g, b, X, Y, Z);

    X /= 95.047;
    Y /= 100;
    Z /= 108.883;

    comp1 = 116 * (Y >= 0.008856 ? cbrt(Y) : (7.787 * Y + 16.0 / 116)) - 16;
    comp2 = 500 * ((X >= 0.008856 ? cbrt(X) : (7.787 * X + 16.0 / 116)) - (Y >= 0.008856 ? cbrt(Y) : (7.787 * Y + 16.0 / 116)));
    comp3 = 200 * ((Y >= 0.008856 ? cbrt(Y) : (7.787 * Y + 16.0 / 116)) - (Z >= 0.008856 ? cbrt(Z) : (7.787 * Z + 16.0 / 116)));
}

void ColorPanel::CMYKtoRGB(int &r, int &g, int &b, double comp1, double comp2, double comp3, double comp4)
{
    r = 255 * (1 - comp1 / 100) * (1 - comp4 / 100);
    g = 255 * (1 - comp2 / 100) * (1 - comp4 / 100);
    b = 255 * (1 - comp3 / 100) * (1 - comp4 / 100);
}

void ColorPanel::HSVtoRGB(int &r, int &g, int &b, double comp1, double comp2, double comp3)
{
    comp2 /= 100;
    comp3 /= 100;

    if (comp1 > 359.999)
    {
        comp1 = 0;
    }

    double c = comp2 * comp3;
    double x = c * (1 - abs((comp1 / 60) - 2 * ((int)(comp1 / 60) / 2) - 1));
    double m = comp3 - c;

    r = 0;
    g = 0;
    b = 0;

    if (comp1 < 60)
    {
        r = (c + m) * 255;
        g = (x + m) * 255;
        b = (0 + m) * 255;
    }
    else if (comp1 < 120)
    {
        r = (x + m) * 255;
        g = (c + m) * 255;
        b = (0 + m) * 255;
    }
    else if (comp1 < 180)
    {
        r = (0 + m) * 255;
        g = (c + m) * 255;
        b = (x + m) * 255;
    }
    else if (comp1 < 240)
    {
        r = (0 + m) * 255;
        g = (x + m) * 255;
        b = (c + m) * 255;
    }
    else if (comp1 < 300)
    {
        r = (x + m) * 255;
        g = (0 + m) * 255;
        b = (c + m) * 255;
    }
    else
    {
        r = (c + m) * 255;
        g = (0 + m) * 255;
        b = (x + m) * 255;
    }
}

void ColorPanel::HSLtoRGB(int &r, int &g, int &b, double comp1, double comp2, double comp3)
{
    comp2 /= 100;
    comp3 /= 100;

    if (comp1 > 359.999)
    {
        comp1 = 0;
    }

    double c = comp2 * (1 - abs(2 * comp3 - 1));
    double x = c * (1 - abs((comp1 / 60) - 2 *((int)(comp1 / 60) / 2) - 1));
    double m = comp3 - c / 2;

    r = 0;
    g = 0;
    b = 0;

    if (comp1 < 60)
    {
        r = (c + m) * 255;
        g = (x + m) * 255;
        b = (0 + m) * 255;
    }
    else if (comp1 < 120)
    {
        r = (x + m) * 255;
        g = (c + m) * 255;
        b = (0 + m) * 255;
    }
    else if (comp1 < 180)
    {
        r = (0 + m) * 255;
        g = (c + m) * 255;
        b = (x + m) * 255;
    }
    else if (comp1 < 240)
    {
        r = (0 + m) * 255;
        g = (x + m) * 255;
        b = (c + m) * 255;
    }
    else if (comp1 < 300)
    {
        r = (x + m) * 255;
        g = (0 + m) * 255;
        b = (c + m) * 255;
    }
    else
    {
        r = (c + m) * 255;
        g = (0 + m) * 255;
        b = (x + m) * 255;
    }
}

void ColorPanel::LABtoRGB(int &r, int &g, int &b, double comp1, double comp2, double comp3)
{
    double x, y, z, tmp;

    y = (((comp1 + 16) / 116 > 6.0 / 29) ? pow((comp1 + 16) / 116, 3) : 3 * 36.0 / 841 * ((comp1 + 16) / 116 - 4.0 / 29)) * 100;

    tmp = comp2 / 500 + (comp1 + 16) / 116;
    x = ((tmp > 6.0 / 29) ? pow(tmp, 3) : 3 * 36.0 / 841 * (tmp - 4.0 / 29)) * 95.047;

    tmp = (comp1 + 16) / 116 - comp3 / 200;
    z = ((tmp > 6.0 / 29) ? pow(tmp, 3) : 3 * 36.0 / 841 * (tmp - 4.0 / 29)) * 108.883;

    XYZtoRGB(r, g, b, x, y, z);
}

void ColorPanel::XYZtoRGB(int &r, int &g, int &b, double comp1, double comp2, double comp3)
{
    double R, G, B;

    comp1 /= 100;
    comp2 /= 100;
    comp3 /= 100;

    R = 3.2406 * comp1 - 1.5372 * comp2 - 0.4986 * comp3;
    G = -0.9689 * comp1 + 1.8758 * comp2 + 0.0415 * comp3;
    B = 0.0557 * comp1 - 0.2040 * comp2 + 1.0570 * comp3;

    r = (R >= 0.0031308 ? (1.055 * pow(R, (1 / 2.4)) - 0.055) : (12.92 * R)) * 255;
    g = (G >= 0.0031308 ? (1.055 * pow(G, (1 / 2.4)) - 0.055) : (12.92 * G)) * 255;
    b = (B >= 0.0031308 ? (1.055 * pow(B, (1 / 2.4)) - 0.055) : (12.92 * B)) * 255;
}

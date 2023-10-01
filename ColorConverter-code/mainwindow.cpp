
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->setMaxVisibleItems(20);

    QRegExp rx("[0-9A-Fa-f]{6}");
    QValidator* validator = new QRegExpValidator(rx);
    ui->hexInput->setValidator(validator);
    ui->hexInput->setText("FFFFFF");

    grid1 = new QGridLayout();
    grid2 = new QGridLayout();
    grid3 = new QGridLayout();

    ui->verticalLayout->addLayout(grid1);
    ui->verticalLayout->addLayout(grid2);
    ui->verticalLayout->addLayout(grid3);

    red = green = blue = 255;

    panel1 = new ColorPanel();
    panel2 = new ColorPanel();
    panel3 = new ColorPanel();

    panel1->createPanel(grid1, ColorPanel::RGB, red, green, blue);
    panel2->createPanel(grid2, ColorPanel::LAB, red, green, blue);
    panel3->createPanel(grid3, ColorPanel::CMYK, red, green, blue);

    connect(ui->hexInput, &QLineEdit::textEdited, this, &MainWindow::hexInputTextChanged);

    connect(panel1, &ColorPanel::colorSignal, this, [=](QColor color){
        colorSignalProcess(color);
        panel2->setColorComponents(red, green, blue);
        panel3->setColorComponents(red, green, blue);
    });

    connect(panel2, &ColorPanel::colorSignal, this, [=](QColor color){
        colorSignalProcess(color);
        panel1->setColorComponents(red, green, blue);
        panel3->setColorComponents(red, green, blue);
    });

    connect(panel3, &ColorPanel::colorSignal, this, [=](QColor color){
        colorSignalProcess(color);
        panel1->setColorComponents(red, green, blue);
        panel2->setColorComponents(red, green, blue);
    });

    connect(ui->comboBox, &QComboBox::currentTextChanged, this, [=](QString text){
        switch(ui->comboBox->findText(text))
        {
        case 0:
            panel1->createPanel(grid1, ColorPanel::RGB, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::LAB, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::CMYK, red, green, blue);
            break;
        case 1:
            panel1->createPanel(grid1, ColorPanel::RGB, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::CMYK, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::HLS, red, green, blue);
            break;
        case 2:
            panel1->createPanel(grid1, ColorPanel::RGB, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::XYZ, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::LAB, red, green, blue);
            break;
        case 3:
            panel1->createPanel(grid1, ColorPanel::RGB, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::HSV, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::LAB, red, green, blue);
            break;
        case 4:
            panel1->createPanel(grid1, ColorPanel::CMYK, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::LAB, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::HSV, red, green, blue);
            break;
        case 5:
            panel1->createPanel(grid1, ColorPanel::CMYK, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::RGB, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::HLS, red, green, blue);
            break;
        case 6:
            panel1->createPanel(grid1, ColorPanel::CMYK, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::RGB, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::HSV, red, green, blue);
            break;
        case 7:
            panel1->createPanel(grid1, ColorPanel::RGB, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::XYZ, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::HSV, red, green, blue);
            break;
        case 8:
            panel1->createPanel(grid1, ColorPanel::HSV, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::XYZ, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::LAB, red, green, blue);
            break;
        case 9:
            panel1->createPanel(grid1, ColorPanel::CMYK, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::LAB, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::RGB, red, green, blue);
            break;
        case 10:
            panel1->createPanel(grid1, ColorPanel::XYZ, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::LAB, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::HLS, red, green, blue);
            break;
        case 11:
            panel1->createPanel(grid1, ColorPanel::RGB, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::XYZ, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::HLS, red, green, blue);
            break;
        case 12:
            panel1->createPanel(grid1, ColorPanel::RGB, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::XYZ, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::CMYK, red, green, blue);
            break;
        case 13:
            panel1->createPanel(grid1, ColorPanel::CMYK, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::LAB, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::XYZ, red, green, blue);
            break;
        case 14:
            panel1->createPanel(grid1, ColorPanel::RGB, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::CMYK, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::HSV, red, green, blue);
            break;
        case 15:
            panel1->createPanel(grid1, ColorPanel::CMYK, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::HLS, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::XYZ, red, green, blue);
            break;
        case 16:
            panel1->createPanel(grid1, ColorPanel::RGB, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::HLS, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::LAB, red, green, blue);
            break;
        case 17:
            panel1->createPanel(grid1, ColorPanel::CMYK, red, green, blue);
            panel2->createPanel(grid2, ColorPanel::XYZ, red, green, blue);
            panel3->createPanel(grid3, ColorPanel::RGB, red, green, blue);
            break;
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::colorSignalProcess(QColor color)
{
    red = color.red();
    green = color.green();
    blue = color.blue();
    ui->hexInput->setText(RGBToHex(red, green, blue));
    ui->colorShowWidget->setStyleSheet("border: 1px solid black; background-color: " + QColor(red, green, blue).name() + ";");
}

void MainWindow::hexInputTextChanged()
{
    if (ui->hexInput->text().length() == 6)
    {
        bool ok;
        red = ui->hexInput->text().midRef(0, 2).toInt(&ok, 16);
        green = ui->hexInput->text().midRef(2, 2).toInt(&ok, 16);
        blue = ui->hexInput->text().midRef(4, 2).toInt(&ok, 16);
        ui->colorShowWidget->setStyleSheet("border: 1px solid black; background-color: " + QColor(red, green, blue).name() + ";");
        panel1->setColorComponents(red, green, blue);
        panel2->setColorComponents(red, green, blue);
        panel3->setColorComponents(red, green, blue);
    }
    else
    {
        ui->colorShowWidget->setStyleSheet("border: 1px solid black; background-color: white;");
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    if (ev->buttons() & Qt::LeftButton)
    {
        setColor(ev->x(), ev->y());
    }
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if (ev->buttons() & Qt::LeftButton)
    {
        setColor(ev->x(), ev->y());
    }
}

void MainWindow::setColor(int x, int y)
{
    if (x > ui->colorSelectWidget->pos().x() && x < ui->colorSelectWidget->pos().x() + ui->colorSelectWidget->width() - 1 &&
        y > ui->colorSelectWidget->pos().y() && y < ui->colorSelectWidget->pos().y() + ui->colorSelectWidget->height() - 1)
    {
        QPixmap pixmap = this->grab();
        QColor pixelColor = pixmap.toImage().pixelColor(x, y);

        red = pixelColor.red();
        green = pixelColor.green();
        blue = pixelColor.blue();

        ui->colorShowWidget->setStyleSheet("border: 1px solid black; background-color: " + pixelColor.name() + ";");
        ui->hexInput->setText(RGBToHex(red, green, blue));

        panel1->setColorComponents(red, green, blue);
        panel2->setColorComponents(red, green, blue);
        panel3->setColorComponents(red, green, blue);
    }
}

QString MainWindow::RGBToHex(int r, int g, int b)
{
    QString redHex = QString::number(r, 16).length() == 1 ? "0" + QString::number(r, 16) : QString::number(r, 16);
    QString greenHex = QString::number(g, 16).length() == 1 ? "0" + QString::number(g, 16) : QString::number(g, 16);
    QString blueHex = QString::number(b, 16).length() == 1 ? "0" + QString::number(b, 16) : QString::number(b, 16);

    QString hex = redHex + greenHex + blueHex;
    return hex;
}

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *colorSelectWidget;
    QWidget *colorShowWidget;
    QLineEdit *hexInput;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(612, 831);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: white;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        colorSelectWidget = new QWidget(centralwidget);
        colorSelectWidget->setObjectName(QString::fromUtf8("colorSelectWidget"));
        colorSelectWidget->setGeometry(QRect(30, 30, 362, 234));
        colorSelectWidget->setCursor(QCursor(Qt::CrossCursor));
        colorSelectWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/img/Images/ColorPalette.jpg);\n"
"border: 1px solid rgb(0, 0, 0);"));
        colorShowWidget = new QWidget(centralwidget);
        colorShowWidget->setObjectName(QString::fromUtf8("colorShowWidget"));
        colorShowWidget->setGeometry(QRect(422, 30, 160, 80));
        colorShowWidget->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"background-color: white;"));
        hexInput = new QLineEdit(centralwidget);
        hexInput->setObjectName(QString::fromUtf8("hexInput"));
        hexInput->setGeometry(QRect(490, 140, 92, 25));
        QFont font;
        font.setPointSize(12);
        hexInput->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(422, 140, 65, 25));
        label->setFont(font);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 299, 591, 451));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(422, 195, 160, 34));
        QFont font1;
        font1.setPointSize(8);
        comboBox->setFont(font1);
        comboBox->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 612, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "HEX: #", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "RGB \342\206\224 LAB \342\206\224 CMYK", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "RGB \342\206\224 CMYK \342\206\224 HLS", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "RGB \342\206\224 XYZ \342\206\224 LAB", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "RGB \342\206\224 HSV \342\206\224 LAB", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "CMYK \342\206\224 LAB \342\206\224 HSV", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "CMYK \342\206\224 RGB \342\206\224 HLS", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "CMYK \342\206\224 RGB \342\206\224 HSV", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "RGB \342\206\224 XYZ \342\206\224 HSV", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "HSV \342\206\224 XYZ \342\206\224 LAB", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("MainWindow", "CMYK \342\206\224 LAB \342\206\224 RGB", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("MainWindow", "XYZ \342\206\224 LAB \342\206\224 HLS", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("MainWindow", "RGB \342\206\224 XYZ \342\206\224 HLS", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("MainWindow", "RGB \342\206\224 XYZ \342\206\224 CMYK", nullptr));
        comboBox->setItemText(13, QCoreApplication::translate("MainWindow", "CMYK \342\206\224 LAB \342\206\224 XYZ", nullptr));
        comboBox->setItemText(14, QCoreApplication::translate("MainWindow", "RGB \342\206\224 CMYK \342\206\224 HSV", nullptr));
        comboBox->setItemText(15, QCoreApplication::translate("MainWindow", "CMYK \342\206\224 HLS \342\206\224 XYZ", nullptr));
        comboBox->setItemText(16, QCoreApplication::translate("MainWindow", "RGB \342\206\224 HLS \342\206\224 LAB", nullptr));
        comboBox->setItemText(17, QCoreApplication::translate("MainWindow", "CMYK \342\206\224 XYZ \342\206\224 RGB", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

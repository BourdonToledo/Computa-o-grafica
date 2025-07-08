/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "newframe.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    newFrame *frame;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QDoubleSpinBox *x1;
    QDoubleSpinBox *y1;
    QDoubleSpinBox *x2;
    QDoubleSpinBox *y2;
    QDoubleSpinBox *multi_x;
    QDoubleSpinBox *angulo;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QSpinBox *Index;
    QDoubleSpinBox *z1;
    QDoubleSpinBox *z2;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QDoubleSpinBox *angulo_z;
    QDoubleSpinBox *angulo_y;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QPushButton *chariz;
    QLineEdit *EditorDeNome;
    QDoubleSpinBox *multi_y;
    QDoubleSpinBox *multi_z;
    QPushButton *dir;
    QPushButton *esq;
    QPushButton *baixo;
    QPushButton *cima;
    QPushButton *esq_2;
    QPushButton *esq_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new newFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(240, 60, 221, 211));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 90, 75, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(120, 90, 75, 24));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(30, 130, 75, 24));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(120, 130, 75, 24));
        x1 = new QDoubleSpinBox(centralwidget);
        x1->setObjectName("x1");
        x1->setGeometry(QRect(10, 230, 62, 22));
        x1->setMinimum(-99.989999999999995);
        y1 = new QDoubleSpinBox(centralwidget);
        y1->setObjectName("y1");
        y1->setGeometry(QRect(80, 230, 62, 22));
        y1->setMinimum(-99.989999999999995);
        x2 = new QDoubleSpinBox(centralwidget);
        x2->setObjectName("x2");
        x2->setGeometry(QRect(10, 310, 62, 22));
        x2->setMinimum(-99.989999999999995);
        y2 = new QDoubleSpinBox(centralwidget);
        y2->setObjectName("y2");
        y2->setGeometry(QRect(80, 310, 62, 22));
        y2->setMinimum(-99.989999999999995);
        multi_x = new QDoubleSpinBox(centralwidget);
        multi_x->setObjectName("multi_x");
        multi_x->setGeometry(QRect(480, 180, 62, 22));
        angulo = new QDoubleSpinBox(centralwidget);
        angulo->setObjectName("angulo");
        angulo->setGeometry(QRect(480, 280, 62, 22));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(10, 200, 51, 22));
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(80, 200, 51, 22));
        lineEdit_3->setReadOnly(true);
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(480, 150, 61, 22));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(480, 250, 61, 22));
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(10, 280, 51, 22));
        lineEdit_6->setReadOnly(true);
        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(80, 280, 51, 22));
        lineEdit_7->setReadOnly(true);
        Index = new QSpinBox(centralwidget);
        Index->setObjectName("Index");
        Index->setGeometry(QRect(330, 30, 42, 22));
        z1 = new QDoubleSpinBox(centralwidget);
        z1->setObjectName("z1");
        z1->setGeometry(QRect(150, 230, 62, 22));
        z1->setMinimum(-99.989999999999995);
        z2 = new QDoubleSpinBox(centralwidget);
        z2->setObjectName("z2");
        z2->setGeometry(QRect(150, 310, 62, 22));
        z2->setMinimum(-99.989999999999995);
        lineEdit_8 = new QLineEdit(centralwidget);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(150, 200, 51, 22));
        lineEdit_8->setReadOnly(true);
        lineEdit_9 = new QLineEdit(centralwidget);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(150, 280, 51, 22));
        lineEdit_9->setReadOnly(true);
        angulo_z = new QDoubleSpinBox(centralwidget);
        angulo_z->setObjectName("angulo_z");
        angulo_z->setGeometry(QRect(620, 280, 62, 22));
        angulo_y = new QDoubleSpinBox(centralwidget);
        angulo_y->setObjectName("angulo_y");
        angulo_y->setGeometry(QRect(550, 280, 62, 22));
        lineEdit_10 = new QLineEdit(centralwidget);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(550, 250, 61, 22));
        lineEdit_11 = new QLineEdit(centralwidget);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(620, 250, 61, 22));
        chariz = new QPushButton(centralwidget);
        chariz->setObjectName("chariz");
        chariz->setGeometry(QRect(30, 50, 75, 24));
        EditorDeNome = new QLineEdit(centralwidget);
        EditorDeNome->setObjectName("EditorDeNome");
        EditorDeNome->setGeometry(QRect(10, 350, 201, 22));
        multi_y = new QDoubleSpinBox(centralwidget);
        multi_y->setObjectName("multi_y");
        multi_y->setGeometry(QRect(550, 180, 62, 22));
        multi_z = new QDoubleSpinBox(centralwidget);
        multi_z->setObjectName("multi_z");
        multi_z->setGeometry(QRect(620, 180, 62, 22));
        dir = new QPushButton(centralwidget);
        dir->setObjectName("dir");
        dir->setGeometry(QRect(370, 320, 31, 24));
        esq = new QPushButton(centralwidget);
        esq->setObjectName("esq");
        esq->setGeometry(QRect(290, 320, 31, 24));
        baixo = new QPushButton(centralwidget);
        baixo->setObjectName("baixo");
        baixo->setGeometry(QRect(330, 320, 31, 24));
        cima = new QPushButton(centralwidget);
        cima->setObjectName("cima");
        cima->setGeometry(QRect(330, 290, 31, 24));
        esq_2 = new QPushButton(centralwidget);
        esq_2->setObjectName("esq_2");
        esq_2->setGeometry(QRect(240, 280, 71, 21));
        esq_3 = new QPushButton(centralwidget);
        esq_3->setObjectName("esq_3");
        esq_3->setGeometry(QRect(380, 280, 71, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_3, &QPushButton::clicked, frame, qOverload<>(&newFrame::Rotar));
        QObject::connect(pushButton_4, &QPushButton::clicked, frame, qOverload<>(&newFrame::Escalar));
        QObject::connect(pushButton, &QPushButton::clicked, frame, qOverload<>(&newFrame::NewLinha));
        QObject::connect(pushButton_2, &QPushButton::clicked, frame, qOverload<>(&newFrame::New));
        QObject::connect(pushButton_2, &QPushButton::clicked, Index, qOverload<>(&QSpinBox::stepUp));
        QObject::connect(chariz, &QPushButton::clicked, frame, qOverload<>(&newFrame::ReadObj));
        QObject::connect(chariz, &QPushButton::clicked, Index, qOverload<>(&QSpinBox::stepUp));
        QObject::connect(cima, &QPushButton::clicked, frame, qOverload<>(&newFrame::Acima));
        QObject::connect(dir, &QPushButton::clicked, frame, qOverload<>(&newFrame::Direita));
        QObject::connect(esq, &QPushButton::clicked, frame, qOverload<>(&newFrame::Esquerda));
        QObject::connect(baixo, &QPushButton::clicked, frame, qOverload<>(&newFrame::Abaixo));
        QObject::connect(esq_3, &QPushButton::clicked, frame, qOverload<>(&newFrame::OlharDir));
        QObject::connect(esq_2, &QPushButton::clicked, frame, qOverload<>(&newFrame::OlharEsq));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Nova Linha", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Novo Objeto", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Rotar", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Multiplicar", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "X1", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "Y1", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "Multiplier", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "Angulo yz", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("MainWindow", "X2", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "Y2", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("MainWindow", "Z1", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "Z2", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("MainWindow", "Angulo xz", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("MainWindow", "Angulo xy", nullptr));
        chariz->setText(QCoreApplication::translate("MainWindow", "Char", nullptr));
        EditorDeNome->setText(QCoreApplication::translate("MainWindow", "X1", nullptr));
        dir->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        esq->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        baixo->setText(QCoreApplication::translate("MainWindow", "v", nullptr));
        cima->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        esq_2->setText(QCoreApplication::translate("MainWindow", "virar esq", nullptr));
        esq_3->setText(QCoreApplication::translate("MainWindow", "virar dir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

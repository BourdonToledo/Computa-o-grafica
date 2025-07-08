#ifndef NEWFRAME_H
#define NEWFRAME_H

#include <QWidget>
#include <QFrame.h>
#include <QPainter.h>
#include <QPaintEvent>
#include <QRect>
#include <QList>
#include <QObject>
#include <QWidget>
#include <QtMath>
#include "moldes.h"
#include <QFile>
#include <iostream>
#include <string>
#include "movimento.h"
#include <QDebug>
#include <QGenericMatrix>
#include <QMatrix4x4>
#include <QVector4D>


class newFrame : public QFrame
{
    Q_OBJECT
public:
    explicit newFrame(QWidget *parent = nullptr);
    void paintEvent ( QPaintEvent * event );
    void New();
    void NewLinha();
    void Iniciar();
    void Rotar();
    void Escalar();
    void SoRodar();
    void ReadObj();
    void Transformada();
    void AssinarP1(QString line);
    void AssinarP2(QString line);
    void Acima();
    void Abaixo();
    void Esquerda();
    void Direita();
    void OlharDir();
    void OlharEsq();
    void FazerQuadrado();
    void FazerCasa();
    void Cubo();
    void Piramide();
    void Afastar();
    void Aproximar();

    float dbw = 0 ,dbh = 0; // largura e altura da window respectivamente;
    double x0, y0, z0, x2, y2, z2, anguloX = 0, anguloY = 0, anguloZ = 0, multiX = 1, multiY = 1, multiZ = 1;
    // anguloX =  em torno de x;
    // anguloY =  em trono de Y;
    // anguloZ =  em torno de Z;
    Movimento Win;
    int index = 0, maxShape = 0;
    bool girarDir = false;
    bool auxIR[4] = {false, false, false, false};

    QString FileNome;



signals:
};

#endif // NEWFRAME_H

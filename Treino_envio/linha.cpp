#include "linha.h"
#include <QList>
Linha::Linha(Molde *parent)
    : Molde{parent}
{}

void Linha::Make(QString name, int fx, int fy, int fz, int lx, int ly, int lz){

    id = name;
    ponto.append(QLineF(QPointF(fx, fy), QPointF(lx, ly)));


}

void Linha::Spin(int ang){


    double aux = qDegreesToRadians(ang);
    int nx0, ny0, nx2, ny2;

    int x0 = 0;
    int y0 = 0;
    int x2 = ponto[0].p2().rx() - ponto[0].p1().rx();
    int y2 = ponto[0].p2().ry() - ponto[0].p1().ry();

    nx0 = x0 * qCos(aux) - y0 * qSin(aux);
    ny0 = x0 * qSin(aux) + y0 * qCos(aux);
    nx2 = x2 * qCos(aux) - y2 * qSin(aux);
    ny2 = x2 * qSin(aux) + y2 * qCos(aux);

    nx0 += ponto[0].p1().rx();
    ny0 += ponto[0].p1().ry();
    nx2 += ponto[0].p1().rx();
    ny2 += ponto[0].p1().ry();

    ponto[0]= QLineF(QPointF(nx0, ny0), QPointF(nx2, ny2));


}

void Linha::Translasao(int multp){

    int x2 = ponto[0].p2().rx() - ponto[0].p1().rx();
    int y2 = ponto[0].p2().ry() - ponto[0].p1().ry();

    x2 *= multp;
    y2 *= multp;

    x2 += ponto[0].p1().rx();
    y2 += ponto[0].p1().ry();

    ponto[0].setP2(QPointF(x2, y2));


}



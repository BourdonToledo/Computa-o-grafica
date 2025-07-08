#include "rect.h"

Rect::Rect(Molde *parent)
    : Molde{parent}
{}


void Rect::Make(QString name, int fx, int fy, int fz, int lx, int ly, int lz){

    id = name;

    ponto.append(QLineF(QPointF(fx, fy), QPointF(fx, ly)));
    ponto.append(QLineF(QPointF(fx, ly), QPointF(lx, ly)));
    ponto.append(QLineF(QPointF(fx, fy), QPointF(lx, fy)));
    ponto.append(QLineF(QPointF(lx, fy), QPointF(lx, ly)));

    this->GravarPontos(fx, fy, fz);
    this->GravarPontos(lx, ly, lz);

}

void Rect::Spin(int ang){

    double ox0 =  ponto[0].p1().rx(), oy0 = ponto[0].p1().ry();
    for(int i = 0; i < 4; i++){
        double aux = qDegreesToRadians(ang);
        int nx0, ny0, nx2, ny2;

        int x0 = ponto[i].p1().rx() - ox0;
        int y0 = ponto[i].p1().ry() - oy0;
        int x2 = ponto[i].p2().rx() - ox0;
        int y2 = ponto[i].p2().ry() - oy0;

        nx0 = x0 * qCos(aux) - y0 * qSin(aux);
        ny0 = x0 * qSin(aux) + y0 * qCos(aux);
        nx2 = x2 * qCos(aux) - y2 * qSin(aux);
        ny2 = x2 * qSin(aux) + y2 * qCos(aux);

        nx0 += ox0;
        ny0 += oy0;
        nx2 += ox0;
        ny2 += oy0;

        ponto[i]= QLineF(QPointF(nx0, ny0), QPointF(nx2, ny2));
    }


}

void Rect::Translasao(int multp){

    double ox0 =  ponto[0].p1().rx(), oy0 = ponto[0].p1().ry();
    for(int i = 0; i < 4; i++){

        int x0 = ponto[i].p1().rx() - ox0;
        int y0 = ponto[i].p1().ry() - oy0;
        int x2 = ponto[i].p2().rx() - ox0;
        int y2 = ponto[i].p2().ry() - oy0;

        x0 *= multp;
        y0 *= multp;
        x2 *= multp;
        y2 *= multp;

        x0 += ox0;
        y0 += oy0;
        x2 += ox0;
        y2 += oy0;

        ponto[i].setP1(QPointF(x0, y0));
        ponto[i].setP2(QPointF(x2, y2));

    }



}

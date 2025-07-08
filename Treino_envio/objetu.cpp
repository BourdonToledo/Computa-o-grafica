#include "objetu.h"

Objetu::Objetu(Molde *parent)
    : Molde{parent}
{}

void Objetu::Make(QString name, int fx, int fy, int fz, int lx, int ly, int lzy){

    id = name;
    ponto.append(QLineF(QPointF(fx, fy), QPointF(lx, ly)));

}

void Objetu::AddNovaLinha(int fx, int fy, int lx, int ly){


    ponto.append(QLineF(QPointF(fx, fy), QPointF(lx, ly)));

}

#ifndef RECT_H
#define RECT_H

#include <QObject>
#include <QRect>
#include <QList>
#include <QObject>
#include <QWidget>
#include <QtMath>
#include "moldes.h"


class Rect : public Molde
{
    Q_OBJECT
public:
    explicit Rect(Molde *parent = nullptr);
    virtual void Make(QString name, int fx, int fy, int fz, int lx, int ly, int lz) override;
    virtual void Spin(int ang);
    virtual void Translasao(int multp);


signals:
};

#endif // RECT_H

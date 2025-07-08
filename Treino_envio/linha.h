#ifndef LINHA_H
#define LINHA_H

#include "moldes.h"
#include <QObject>

class Linha : public Molde
{
    Q_OBJECT
public:
    explicit Linha(Molde *parent = nullptr);
    virtual void Make(QString name, int fx, int fy, int fz, int lx, int ly, int lz) override;
    virtual void Spin(int ang);
    virtual void Translasao(int multp);

signals:
};

#endif // LINHA_H

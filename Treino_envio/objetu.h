#ifndef OBJETU_H
#define OBJETU_H

#include "moldes.h"
#include <QObject>

class Objetu : public Molde
{
    Q_OBJECT
public:
    explicit Objetu(Molde *parent = nullptr);
    virtual void Make(QString name, int fx, int fy, int fz, int lx, int ly, int lz) override;
    void AddNovaLinha(int fx, int fy, int lx, int ly);

signals:
};

#endif // OBJETU_H

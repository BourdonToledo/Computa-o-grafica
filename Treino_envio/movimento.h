#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#include <QObject>
#include "moldes.h"


class Movimento : public QObject
{
    Q_OBJECT
public:
    explicit Movimento(QObject *parent = nullptr);

    Molde janela;
    float Vup = 0, RotY = 0, RotX = 0, mudarX = 1, mudarY = 1, mudarZ = 1, Wx, Wy;

signals:
};

#endif // MOVIMENTO_H

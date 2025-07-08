#ifndef RETAN_H
#define RETAN_H

#include <QObject>

class Retan : public QObject
{
    Q_OBJECT
public:
    explicit Retan(QObject *parent = nullptr);

signals:
};

#endif // RETAN_H

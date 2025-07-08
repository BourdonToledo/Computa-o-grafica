#ifndef MOLDES_H
#define MOLDES_H

#include <QObject>
#include <QRect>
#include <QList>
#include <QObject>
#include <QWidget>
#include <QtMath>
#include <QtMinMax>
#include <QGenericMatrix>
#include <QMatrix4x4>
#include <QQuickOpenGLUtils>
#include <QVector4D>

class Molde : public QObject
{
    Q_OBJECT
public:
    explicit Molde(QObject *parent = nullptr);

    //======================================== auxiliadores na criação =======================================
    virtual void Make(QString name, float fx, float fy, float fz, float lx, float ly, float lz);
    virtual void GravarPontos(float fx, float fy, float fz);
    void AcharCentro(float x, float y, float z, float dwx, float dwy);
    void Base(QString name, float fx, float fy, float fz, float lx, float ly, float lz);
//====================== 2d=============================
    void Quadrado(QString name, float fx, float fy, float fz, float lx, float ly, float lz);
    void Casa(QString name, float fx, float fy, float fz, float lx, float ly, float lz);
//===================== 3d ==========================
    void Cubo(QString name, float fx, float fy, float fz, float lx, float ly, float lz);
    void Piramide(QString name, float fx, float fy, float fz, float lx, float ly, float lz);

    //===================== Transformações =====================================================
    virtual void Spin(float angz, float angy, float angx, float multpx, float multpy, float multpz);
    virtual void Translasao(float multpx, float multy, float multz);
    void Atualizar(float Vup, float RotX, float RotZ, float x, float y, float Wcx, float Wcy);
    virtual void Movimentar(int direcion);
    virtual QLineF Cliperson(double WSup, double WInf, double WEsq, double WDir, QLineF w, bool IR[4]);
    void SCN(float sx, float sy, float wh, float wv);
    void Arredondar();
    void ClippinZed();
    QVector3D NovoVetor(QVector3D p1, QVector3D p2, float z);
    virtual void distancia();

    int number;
    QString name;
    float smallestx, smallesty, smallestz, bigx, bigy, bigz, centrx, centry, centrz;
    QList <float> xs, ys, zs;
    QList <QVector3D> pointz;
    QList <QLineF> ponto;
    QString id;


signals:
};

#endif // MOLDES_H

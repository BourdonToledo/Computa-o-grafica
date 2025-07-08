 #include "moldes.h"


Molde::Molde(QObject *parent)
    : QObject{parent}
{}


//===================================== Criar formas ==========================================


void Molde::GravarPontos(float fx, float fy, float fz){

    xs.append(fx);
    ys.append(fy);
    zs.append(fz);
    pointz.append(QVector3D(fx, fy, fz));

}


void Molde::Make(QString name, float fx, float fy, float fz, float lx, float ly, float lz){

    if(name != this->name){

        this->name = name;
        this->bigx = lx;
        this->bigy = ly;
        this->bigz = lz;
        this->smallestx = fx;
        this->smallesty = fy;
        this->smallestz = fz;


    }



    if(this->bigx < lx)
        this->bigx = lx;

    if(this->bigx < fx)
        this->bigx = fx;

    if(this->bigy > ly)
        this->bigy = ly;

    if(this->bigy > fy)
        this->bigy = fy;

    if(this->bigz < lz)
        this->bigz = lz;

    if(this->bigz < fz)
        this->bigz = fz;


    if(this->smallestx > lx)
        this->smallestx = lx;

    if(this->smallestx > fx)
        this->smallestx = fx;

    if(this->smallesty < ly)
        this->smallesty = ly;

    if(this->smallesty < fy)
        this->smallesty = fy;

    if(this->smallestz > lz)
        this->smallestz = lz;

    if(this->smallestz > fz)
        this->smallestz = fz;


    this->centrx = this->smallestx + (this->bigx - this->smallestx)/2;
    this->centry = this->smallesty + (this->bigy - this->smallesty)/2;
    this->centrz = this->smallestz + (this->bigz - this->smallestz)/2;





    this->GravarPontos(fx, fy, fz);
    this->GravarPontos(lx, ly, lz);
    ponto.append(QLineF(QPointF(fx, fy), QPointF(lx, ly)));





}

void Molde::Quadrado(QString name, float fx, float fy, float fz, float lx, float ly, float lz){

    this->name = name;
    this->bigx = lx;
    this->bigy = ly;
    this->bigz = lz;
    this->smallestx = fx;
    this->smallesty = fy;
    this->smallestz = fz;






    if(this->bigx < fx){
        this->smallestx = lx;
        this->bigx = fx;
    }

    if(this->bigy > fy){
        this->smallesty = ly;
        this->bigy = fy;
    }

    if(this->bigz < fz){
        this->smallestz = lz;
        this->bigz = fz;
    }

    this->centrx = this->smallestx + (this->bigx - this->smallestx)/2;
    this->centry = this->smallesty + (this->bigy - this->smallesty)/2;
    this->centrz = this->smallestz + (this->bigz - this->smallestz)/2;




    //linha 1
    GravarPontos(fx, fy, fz);
    GravarPontos(lx, fy, fz);
    ponto.append(QLineF(QPointF(fx, fy), QPointF(lx, fy)));

    //linha 2
    GravarPontos(lx, fy, fz);
    GravarPontos(lx, ly, fz);
    ponto.append(QLineF(QPointF(lx, fy), QPointF(lx, ly)));


    //linha 3
    GravarPontos(lx, ly, fz);
    GravarPontos(fx, ly, fz);
    ponto.append(QLineF(QPointF(lx, ly), QPointF(fx, ly)));

    //linha 4

    GravarPontos(fx, ly, fz);
    GravarPontos(fx, fy, fz);
    ponto.append(QLineF(QPointF(fx, ly), QPointF(fx, fy)));

}

void Molde::Base(QString name, float fx, float fy, float fz, float lx, float ly, float lz){

    this->name = name;
    this->bigx = lx;
    this->bigz = lz;
    this->smallestx = fx;
    this->smallestz = fz;






    if(this->bigx < fx){
        this->smallestx = lx;
        this->bigx = fx;
    }


    if(this->bigz < fz){
        this->smallestz = lz;
        this->bigz = fz;
    }

    this->centrx = this->smallestx + (this->bigx - this->smallestx)/2;
    this->centrz = this->smallestz + (this->bigz - this->smallestz)/2;




    //linha 1
    GravarPontos(fx, fy, fz);
    GravarPontos(lx, fy, fz);
    ponto.append(QLineF(QPointF(fx, fy), QPointF(lx, fy)));

    //linha 2
    GravarPontos(lx, fy, fz);
    GravarPontos(lx, fy, lz);
    ponto.append(QLineF(QPointF(lx, fy), QPointF(lx, ly)));


    //linha 3
    GravarPontos(lx, fy, lz);
    GravarPontos(fx, fy, lz);
    ponto.append(QLineF(QPointF(lx, ly), QPointF(fx, ly)));

    //linha 4

    GravarPontos(fx, fy, lz);
    GravarPontos(fx, fy, fz);
    ponto.append(QLineF(QPointF(fx, ly), QPointF(fx, fy)));

}

void Molde::Casa(QString name, float fx, float fy, float fz, float lx, float ly, float lz){

    // quadrado
    this->Quadrado(name, fx, fy, fz, lx, ly, lz);

    //ponto 1
    float aux = smallestx - (centrx - smallestx);

    GravarPontos(aux, ly, fz);

    //ponto 2
    float aux2 = bigx + centrx - smallestx;

    GravarPontos(aux2, ly, fz);

    //linha 1
    ponto.append(QLineF(QPointF(aux, ly), QPointF(aux2, fy)));

    //ponto 3
    GravarPontos(aux, ly, fz);

    //ponto 4
    float aux3 = bigy + (centry - smallesty);
    float aux4 = centrx - 1;
    GravarPontos(aux4, aux3, fz);

    //linha 2
    ponto.append(QLineF(QPointF(aux, ly), QPointF(aux4, aux3)));

    //ponto 5
    GravarPontos(aux4, aux3, fz);

    //ponto 6
    GravarPontos(aux2, ly, fz);

    //linha 3
    ponto.append(QLineF(QPointF(aux4, aux3), QPointF(aux2, ly)));

}


void Molde::Cubo(QString name, float fx, float fy, float fz, float lx, float ly, float lz){

    Quadrado(name, fx, fy, fz, lx, ly, fz);
    Quadrado(name, fx, fy, lz, lx, ly, lz);

    if(this->bigx < fz){
        this->smallestz = lz;
        this->bigz = fz;
    }

    if(this->bigx > fz){
        this->smallestz = fz;
        this->bigz = lz;
    }

    this->centrz = this->smallestz + (this->bigz - this->smallestz)/2;

    GravarPontos(fx, fy, fz);
    GravarPontos(fx, fy, lz);
    ponto.append(QLineF(QPointF(fx, fy), QPointF(fx, fy)));

    GravarPontos(lx, fy, fz);
    GravarPontos(lx, fy, lz);
    ponto.append(QLineF(QPointF(lx, fy), QPointF(lx, fy)));

    GravarPontos(lx, ly, fz);
    GravarPontos(lx, ly, lz);
    ponto.append(QLineF(QPointF(lx, ly), QPointF(lx, ly)));

    GravarPontos(fx, ly, fz);
    GravarPontos(fx, ly, lz);
    ponto.append(QLineF(QPointF(fx, ly), QPointF(fx, ly)));


}

void Molde::Piramide(QString name, float fx, float fy, float fz, float lx, float ly, float lz){

    Base(name, fx, fy, fz, lx, fy, lz);

    if(this->bigy > fy){
        this->smallesty = ly;
        this->bigy = fy;
    }
    else{
        this->smallesty = fy;
        this->bigy = ly;
    }


    this->centry = this->smallesty + (this->bigy - this->smallesty)/2;


    GravarPontos(fx, fy, fz);
    GravarPontos(centrx, ly, centrz);
    ponto.append(QLineF(QPointF(fx, fy), QPointF(centrx, ly)));

    GravarPontos(lx, fy, fz);
    GravarPontos(centrx, ly, centrz);
    ponto.append(QLineF(QPointF(lx, fy), QPointF(centrx, ly)));

    GravarPontos(lx, fy, lz);
    GravarPontos(centrx, ly, centrz);
    ponto.append(QLineF(QPointF(lx, fy), QPointF(centrx, ly)));

    GravarPontos(fx, fy, lz);
    GravarPontos(centrx, ly, centrz);
    ponto.append(QLineF(QPointF(fx, fy), QPointF(centrx, ly)));
}


//======================================= Transformações ====================================

void Molde::Spin(float angz, float angy, float angx, float multpx, float multpy, float multpz)
{

    float radianx = qDegreesToRadians(angx), radiany = qDegreesToRadians(angy), radianz = qDegreesToRadians(angz);


    QMatrix4x4 rotationMatrix, rotationMatriy, rotationMatriz, MN, MP, multiplicador, resultado;

    MN = {1, 0,  0, -centrx,
          0, 1,  0, -centry,
          0, 0,  1, -centrz,
          0, 0,  0,      1};



    rotationMatriy= {qCos(radiany), 0, qSin(radiany), 0,
                     0,             1,             0, 0,
                    -qSin(radiany), 0, qCos(radiany),  0,
                     0,             0,             0, 1};

    rotationMatrix= { 1,             0,              0, 0,
                      0, qCos(radianx), -qSin(radianx),  0,
                      0, qSin(radianx), qCos(radianx),   0,

                      0,             0,              0, 1};

    rotationMatriz= {qCos(radianz), -qSin(radianz), 0, 0,
                      qSin(radianz), qCos(radianz),  0, 0,
                      0,             0,              1, 0,
                      0,             0,              0, 1};

    multiplicador = {multpx, 0,       0, 0,
                     0,      multpy,  0, 0,
                     0,      0,       multpz, 0,
                     0,      0,       0, 1};

    MP = {1, 0, 0, centrx,
          0, 1, 0, centry,
          0, 0, 1, centrz,
          0, 0, 0,      1};


    resultado = MP * rotationMatrix * rotationMatriy * rotationMatriz * multiplicador * MN;




    for(int var = 0; var < xs.size(); var++){



        QVector3D pointo(xs.at(var), ys.at(var), zs.at(var));


        QVector4D FinalResultado = resultado * QVector4D(pointo, 1.0);

        xs.replace(var, FinalResultado.x());
        ys.replace(var, FinalResultado.y());
        zs.replace(var, FinalResultado.z());

        pointz.replace(var, QVector3D(FinalResultado.x(), FinalResultado.y(), FinalResultado.z()));

        if( (var % 2) == 0){

            ponto.replace(var/2, QLineF(QPointF(xs.at(var),ys.at(var)), ponto.at(var/2).p2()));
        }

        else{

            ponto.replace(var/2, QLineF(ponto.at(var/2).p1(), QPointF(xs.at(var),ys.at(var))));

        }
    }



}
void Molde::Translasao(float multpx, float multpy, float multpz){

    float aux1, aux2, aux3;

    for(int var = 0; var < xs.size(); var++){

        aux1 = xs.at(var) - centrx;
        aux2 = ys.at(var) - centry;
        aux3 = zs.at(var) - centrz;

        xs.replace(var, aux1 * multpx + centrx);
        ys.replace(var, aux2 * multpy + centry);
        zs.replace(var, aux3 * multpz + centrz);

        pointz.replace(var, QVector3D(xs.at(var), ys.at(var), zs.at(var)));


        if( (var % 2) == 0){


            ponto.replace(var/2, QLineF(QPointF(xs.at(var),ys.at(var)), ponto.at(var/2).p2()));
        }

        else{


            ponto.replace(var/2, QLineF(ponto.at(var/2).p1(), QPointF(xs.at(var),ys.at(var))));

        }

    }



}





void Molde::Atualizar(float Vup, float RotX, float RotY, float x, float y, float Wcx, float Wcy){

    float radianx = qDegreesToRadians(RotX);
    float radianz = qDegreesToRadians(Vup);
    float radiany = qDegreesToRadians(RotY);

    QMatrix4x4 rotationMatrix,rotationMatriy, rotationMatriz, MN, MP, movimentacao, resultado;

    float EixoRotX = Wcx;
    float EixoRotY = Wcy;

    MN = {1, 0,  0, -EixoRotX,
          0, 1,  0, -EixoRotY,
          0, 0,  1,  0,
          0, 0,  0,  1};

    rotationMatriz= {qCos(radianz), -qSin(radianz), 0, 0,
                      qSin(radianz), qCos(radianz), 0, 0,
                      0,             0,             1, 0,
                      0,             0,             0, 1};

    rotationMatrix= { 1,0              ,0             , 0,
                      0, qCos(radianx), -qSin(radianx), 0,
                      0, qSin(radianx), qCos(radianx) , 0,
                      0, 0             ,0             , 1};

    rotationMatriy= { qCos(radiany),  0, qSin(radiany), 0,
                      0,              1, 0,             0,
                      -qSin(radiany), 0, qCos(radiany), 0,
                      0,              0, 0,             1};

    movimentacao= { 1, 0,  0, -x,
                    0, 1,  0, -y,
                    0, 0,  1, 0,
                    0, 0,  0, 1};


    MP = {1, 0, 0, EixoRotX,
          0, 1, 0, EixoRotY,
          0, 0, 1, 0,
          0, 0, 0, 1};

    resultado = MP * rotationMatrix * rotationMatriy * rotationMatriz * movimentacao * MN;

    for(int var = 0; var < xs.size(); var++){


        QVector3D pointo(xs.at(var), ys.at(var), zs.at(var));


        QVector4D FinalResultado = resultado * QVector4D(pointo, 1.0);

        pointz.replace(var, FinalResultado.toVector3D());



        if( (var % 2) == 0){

            ponto.replace(var/2, QLineF(QPointF(pointz.at(var).x(),pointz.at(var).y()), ponto.at(var/2).p2()));
        }

        else{

            ponto.replace(var/2, QLineF(ponto.at(var/2).p1(), QPointF(pointz.at(var).x(),pointz.at(var).y())));

        }
    }

}


// ==================================== Renderizações ============================================


QLineF Molde::Cliperson(double WSup, double WInf, double WEsq, double WDir, QLineF w, bool IR[4]){

    bool RCP1[4] = {0, 0, 0, 0}, RCP2[4] = {0, 0, 0, 0};



    // RCP = {borda inferior, borda superior, borda direita, borda esquerda}
    if(w.x1() < WEsq) RCP1[3] += 1;
    if(w.x1() > WDir) RCP1[2] += 1;
    if(w.y1() < WSup) RCP1[1] += 1;
    if(w.y1() > WInf) RCP1[0] += 1;

    if(w.x2() < WEsq)RCP2[3] += 1;
    if(w.x2() > WDir)RCP2[2] += 1;
    if(w.y2() < WSup)RCP2[1] += 1;
    if(w.y2() > WInf)RCP2[0] += 1;


    if(RCP1[0] + RCP1[1] + RCP1[2] + RCP1[3] + RCP2[0] + RCP2[1] + RCP2[2] + RCP2[3] == 0){


        return w;
    }

    for (int j = 0; j < 4; ++j)
    {
        if(RCP1[j] && RCP2[j]){

            return QLineF();
        }
    }


//IR = { mudar x do p1, mudar y de p1, mudar o x de p2m mudar o y de p2}
    float m;
    if((w.x2() - w.x1()) != 0) m = (w.y2() - w.y1())/(w.x2() - w.x1());
    else m = 0;

    if(RCP1[3] || RCP1[2]){

        if (IR[1]) return QLineF();



        float aux = qBound(WEsq, w.x1(), WDir);
        float ny = m*(aux - w.x2()) + w.y2();

        w.setP1(QPointF(aux, ny));

        IR[1] = true;
        return this->Cliperson( WSup,  WInf,  WEsq,  WDir, w, IR);
    }

    if(RCP2[3] || RCP2[2]){

        if (IR[3]) return QLineF();

        float aux = qBound(WEsq, w.x2(), WDir);
        float ny = m*(aux - w.x1());

        ny += w.y1();

        w.setP2(QPointF(aux, ny));

        IR[3] = true;
         return this->Cliperson( WSup,  WInf,  WEsq,  WDir, w, IR);

    }

    if(RCP1[0] || RCP1[1]){


        if (IR[0]) return QLineF();

        float nx = 0;
        float aux = qBound(WSup, w.y1(), WInf);
        if(m != 0)
            nx = (aux - w.y2())/m;

        nx += w.x2();
        w.setP1(QPointF(nx, aux));

        IR[0] = true;
        return this->Cliperson( WSup,  WInf,  WEsq,  WDir, w, IR);
    }

    if(RCP2[0] || RCP2[1]){


        if (IR[2]) return QLineF();

        float nx = 0;
        float aux = qBound(WSup, w.y2(), WInf);
        if(m != 0)
            nx = (aux - w.y1())/m;

        nx += w.x1();
        w.setP2(QPointF(nx, aux));

        IR[2] = true;
        return this->Cliperson( WSup,  WInf,  WEsq,  WDir, w, IR);
    }

    return w;

}


void Molde::ClippinZed(){

    qDebug() << pointz.size();
    short IR[2];
    for (int var = 0; var < pointz.size()/2; var++) {

        IR[0] = 0;
        IR[1] = 0;

        if(pointz.at(2 * var).z() < 0) IR[0] = 1;
        if(pointz.at((2 * var) + 1).z() < 0) IR[1] = 1;


        if(IR[0] + IR[1] == 0){

            continue;
        }
        if(IR[0] + IR[1] == 2){



            pointz.replace(var * 2, QVector3D());
            pointz.replace((var * 2) + 1, QVector3D());
            ponto.replace(var, QLineF());

            continue;


        }


        if(IR[0] == 1){


            pointz.replace(2 * var, NovoVetor(pointz.at(2 * var), pointz.at((2 * var) + 1), 0));
            ponto.replace(var, QLineF(QPointF(pointz.at(2 * var).x(),pointz.at(2 * var).y()), ponto.at(var).p2()));


        }

        if(IR[1] == 1){


            pointz.replace((2 * var) + 1, NovoVetor( pointz.at((2 * var) + 1), pointz.at(2 * var), 0));
            ponto.replace(var, QLineF(ponto.at(var).p1(), QPointF(pointz.at((2 * var) + 1).x(),pointz.at((2 * var) + 1).y())));

        }




    }




}


QVector3D Molde::NovoVetor(QVector3D p1, QVector3D p2, float z){
    float m, nx, ny;
    if((p2.z() - p1.z()) != 0) m = (z - p1.z())/(p2.z() - p1.z());
    else m = 0;



    nx = p1.x() + m * (p2.x() - p1.x());

    ny = p1.y() + m * (p2.y() - p1.y());

    return QVector3D(nx, ny, z);
}



void Molde::distancia(){


    /*
    QMatrix4x4 distanciaP1, distanciaP2, MN, MP, resultado;

    MN = {1, 0,  0, -centrx,
          0, 1,  0, -centry,
          0, 0,  1, -centrz,
          0, 0,  0,      1};

    MP = {1, 0,  0, centrx,
          0, 1,  0, centry,
          0, 0,  1, centrz,
          0, 0,  0,     1};


    distanciaP1 = {1, 0, 0,   0,
                   0, 1, 0,    0,
                   0, 0, 1,    0,
                   0, 0, 1/5, 0};


    resultado = MP * distanciaP1 * MN;

    for(int var = 0; var < pointz.size(); var++){


        qDebug() << "original: " << pointz.at(var);

        QVector4D FinalResultado = resultado * QVector4D(pointz.at(var), 1.0);

        pointz.replace(var, FinalResultado.toVector3D());

        qDebug() << "final: " << pointz.at(var);

        if( (var % 2) == 0){

            ponto.replace(var/2, QLineF(QPointF(pointz.at(var).x(),pointz.at(var).y()), ponto.at(var/2).p2()));
        }

        else{

            ponto.replace(var/2, QLineF(ponto.at(var/2).p1(), QPointF(pointz.at(var).x(),pointz.at(var).y())));
            qDebug();
        }
    }

        */


    float som = 90 * 0.5 * M_PI/100;

    QVector3D projecao;
    float d = qTan(qDegreesToRadians(som)), aux;

    for (int var = 0; var < pointz.size(); ++var) {
        aux = pointz.at(var).x() - centrx;
        projecao.setX( (aux/ (d * pointz.at(var).z())) + centrx);

        aux = pointz.at(var).y() - centry;
        projecao.setY( (aux/ (d * pointz.at(var).z())) + centry);

        projecao.setZ(pointz.at(var).z());

        pointz.replace(var, projecao);

        if( (var % 2) == 0){

            ponto.replace(var/2, QLineF(QPointF(pointz.at(var).x(),pointz.at(var).y()), ponto.at(var/2).p2()));
        }

        else{

            ponto.replace(var/2, QLineF(ponto.at(var/2).p1(), QPointF(pointz.at(var).x(),pointz.at(var).y())));
            qDebug();
        }

    }

}


// ==================================== Movimentações ===========================================

void Molde::Movimentar(int direcion){

    QMatrix4x4 virarMatriz;
    switch (direcion) {
    case 1:

        centry--;

        for (int var = 0; var < ys.size(); ++var) {

            ys.replace(var, ys.at(var) - 1);

            if( (var % 2) == 0){


                ponto.replace(var/2, QLineF(QPointF(xs.at(var),ys.at(var)), ponto.at(var/2).p2()));
            }

            else{


                ponto.replace(var/2, QLineF(ponto.at(var/2).p1(), QPointF(xs.at(var),ys.at(var))));

            }

        }
        break;

    case 2:

        centry++;
        for (int var = 0; var < ys.size(); ++var) {

            ys.replace(var, ys.at(var) + 1);


            if( (var % 2) == 0){


                ponto.replace(var/2, QLineF(QPointF(xs.at(var),ys.at(var)), ponto.at(var/2).p2()));
            }

            else{


                ponto.replace(var/2, QLineF(ponto.at(var/2).p1(), QPointF(xs.at(var),ys.at(var))));

            }

        }

        break;

    case 3:

        centrx++;
        for (int var = 0; var < xs.size(); ++var) {

            xs.replace(var, xs.at(var) + 1);



            if( (var % 2) == 0){


                ponto.replace(var/2, QLineF(QPointF(xs.at(var),ys.at(var)), ponto.at(var/2).p2()));
            }

            else{


                ponto.replace(var/2, QLineF(ponto.at(var/2).p1(), QPointF(xs.at(var),ys.at(var))));

            }
        }

        break;

    case 4:

        centrx--;
        for (int var = 0; var < xs.size(); ++var) {

            xs.replace(var, xs.at(var) - 1);


            if( (var % 2) == 0){


                ponto.replace(var/2, QLineF(QPointF(xs.at(var),ys.at(var)), ponto.at(var/2).p2()));
            }

            else{


                ponto.replace(var/2, QLineF(ponto.at(var/2).p1(), QPointF(xs.at(var),ys.at(var))));

            }

        }

        break;

    case 5:

        centrz++;
        for (int var = 0; var < zs.size(); ++var) {

            zs.replace(var, zs.at(var) + 1);


        }

        break;

    case 6:

        centrz--;
        for (int var = 0; var < zs.size(); ++var) {

            zs.replace(var, zs.at(var) - 1);


        }

        break;

    default:
        return;
        break;

    };

}
void Molde::SCN(float sx, float sy, float wx, float wy){

    QMatrix4x4 Transformador, MN, MP, resultado;

    MN = {1, 0,  0, -centrx,
          0, 1,  0, -centry,
          0, 0,  1, -centrz,
          0, 0,  0,      1};



    Transformador= {wx/sx,  0,   0, 0,
                    0,    wy/sy, 0, 0,
                    1,      0,   1, 0,
                    0,      0,   0, 1};

    MP = {1, 0,  0, centrx,
          0, 1,  0, centry,
          0, 0,  1, centrz,
          0, 0,  0,     1};


    resultado = MP * Transformador * MN;

    for(int var = 0; var < xs.size(); var++){



        QVector4D FinalResultado = resultado * QVector4D(pointz.at(var), 1.0);

        pointz.replace(var, FinalResultado.toVector3D());


        if( (var % 2) == 0){

            ponto.replace(var/2, QLineF(QPointF(pointz.at(var).x(),pointz.at(var).y()), ponto.at(var/2).p2()));
        }

        else{

            ponto.replace(var/2, QLineF(ponto.at(var/2).p1(), QPointF(pointz.at(var).x(),pointz.at(var).y())));

        }
    }
}












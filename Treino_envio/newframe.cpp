#include "newframe.h"
#include "moldes.h"
#include <QFrame>
#include <QPainter.h>
#include <QPaintEvent>
#include <QMenu>
#include <QList>

QList <Molde*> list;
newFrame::newFrame(QWidget *parent)
    : QFrame{parent}
{}


void newFrame::paintEvent ( QPaintEvent * event ){
    QFrame::paintEvent(event);

    dbw = event->rect().width()/4, dbh = event->rect().height()/4; // drawing border width, and draing border height (que eu quero, nao do QFrame de verdade);
    QPainter p(this);
    for (QLineF lj : Win.janela.ponto) {

        p.drawLine(lj);
    }

    //int i = 0; // auxilia no clipping
    for(Molde *w : list){

        w->Atualizar(-Win.Vup, -Win.RotX, -Win.RotY, Win.mudarX, Win.mudarY, dbw * 2, dbh * 2);
        w->ClippinZed();
        w->distancia();
        w->SCN(2*dbw, 2*dbh, Win.Wx, Win.Wy);

        for(QLineF u: w->ponto){

            //clipping

            for (int var = 0; var < 4; ++var) {

                auxIR[var] = false;
            }

            u = w->Cliperson(dbh, 3*dbh, dbw, 3*dbw, u, auxIR);
            p.drawLine(u);

        }
    }


}


//============================================================ CRIAR OBJETOS =====================================================================
//cria um novo objeto e adiciona uma linha a ele;

void newFrame::New(){

    list.append(new Molde());
    list.at(maxShape)->Make("jhon", x0 + dbw*2, -y0 + dbh*2, z0, x2 + dbw*2, -y2 + dbh*2, z2);


    update();
    maxShape++;
    index++;

}

// adiciona uma linha no objeto escolhido pelo index

void newFrame::NewLinha(){


    if (index == 0)
        return;

    list.at(maxShape - 1)->Make("jhon", x0 + dbw*2, -y0 + dbh*2, z0, x2 + dbw*2, -y2 + dbh*2, z2);

    update();

}


void newFrame::FazerQuadrado(){


    list.append(new Molde());
    list.at(maxShape)->Quadrado("jhon", x0 + dbw*2, -y0 + dbh*2, z0, x2 + dbw*2, -y2 + dbh*2, z2);



    update();
    maxShape++;
    index++;


}

void newFrame::FazerCasa(){

    list.append(new Molde());
    list.at(maxShape)->Casa("jhon", x0 + dbw*2, -y0 + dbh*2, z0, x2 + dbw*2, -y2 + dbh*2, z2);



    update();
    maxShape++;
    index++;

}

void newFrame::Cubo(){

    list.append(new Molde());
    list.at(maxShape)->Cubo("jhon", x0 + dbw*2, -y0 + dbh*2, z0, x2 + dbw*2, -y2 + dbh*2, z2);



    update();
    maxShape++;
    index++;
}

void newFrame::Piramide(){

    list.append(new Molde());
    list.at(maxShape)->Piramide("jhon", x0 + dbw*2, -y0 + dbh*2, z0, x2 + dbw*2, -y2 + dbh*2, z2);

    update();
    maxShape++;
    index++;

}

void newFrame::Iniciar(){


    Win.janela.Quadrado("jhon", dbw, dbh, 0, 3*dbw, 3*dbh, 0);
    Win.Wx = 2*dbw;
    Win.Wy = 2*dbh;

    update();

}

//=================================================================== MOVIMENTO ===============================================================


void newFrame::Rotar(){


    if (maxShape == 0)
        return;

    if(index < 0)
        return;

    if(index == 0){
        Win.Wx *= multiX;
        Win.Wy *= multiY;
        Win.mudarZ = multiZ;
        Win.Vup += anguloZ;
        Win.RotX += anguloX;
        Win.RotY += anguloY;


    }

    else
        list.at(index - 1)->Spin(anguloZ, anguloY, anguloX, multiX, multiY, multiZ);

    update();
}

void newFrame::Escalar(){


    if (maxShape == 0)
        return;

    if(index < 0)
        return;

    if(index == 0){

        Win.Wx *= multiX;
        Win.Wy *= multiY;
        Win.mudarZ = multiZ;

    }


    else
        list.at(index - 1)->Spin(0, 0, 0, multiX, multiY, multiZ);

    update();
}

void newFrame::SoRodar(){


    if (maxShape == 0)
        return;

    if(index < 0)
        return;

    if(index == 0){
        Win.Vup += anguloZ;
        Win.RotX += anguloX;
        Win.RotY += anguloY;

    }


    else
        list.at(index - 1)->Spin(anguloZ, anguloY, anguloX, 1, 1, 1);


    update();

}


void newFrame::ReadObj(){
    int indice = 0;
    QFile file(FileNome); //"C:\\Users\\E470\\Documents\\Treino_envio\\Charizard.obj"

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){

        qDebug("no file");
        return;

    }
    list.append(new Molde());
    QStringList aux;
    QTextStream in(&file);
    while (!in.atEnd()) {


        QString line = in.readLine();
        if(line.isEmpty())
            continue;


        if(line.contains("v ")){


            indice++;

            aux = line.split(u' ');

            if(indice < 2 ){

                x2 = aux[1].toDouble();
                y2 = aux[2].toDouble();
                z2 = aux[3].toDouble();

                aux[0].clear();
                aux[1].clear();
                aux[2].clear();
                aux[3].clear();




            }
            else{

                x0 = x2;
                y0 = y2;
                z0 = z2;

                x2 = aux[1].toDouble();
                y2 = aux[2].toDouble();
                z2 = aux[3].toDouble();

                aux[0].clear();
                aux[1].clear();
                aux[2].clear();
                aux[3].clear();



                list.at(maxShape)->Make("jhon", x0 + dbw*2, -y0 + dbh*2, z0, x2 + dbw*2, -y2 + dbh*2, z2);


                update();
            }

        }
    }

    maxShape++;
    index++;
    file.close();
}


void newFrame::Acima() {


    if(index < 0)
        return;

    if(index == 0)
        Win.mudarY--;


    else
        list.at(index - 1)->Movimentar(1);


    update();
}


void newFrame::Abaixo() {

    if(index < 0)
        return;

    if(index == 0)
        Win.mudarY++;


    else
        list.at(index - 1)->Movimentar(2);


    update();
}


void newFrame::Direita() {


    if(index < 0)
        return;

    if(index == 0)
        Win.mudarX++;

    else
        list.at(index - 1)->Movimentar(3);


    update();
}


void newFrame::Esquerda() { {


        if(index < 0)
            return;

        if(index == 0)
            Win.mudarX--;


        else
            list.at(index - 1)->Movimentar(4);

    }

    update();


}

void newFrame::Afastar(){


    if(index > 0) list.at(index - 1)->Movimentar(5);


    update();

 }

void newFrame::Aproximar(){

    if(index > 0) list.at(index - 1)->Movimentar(6);


    update();

}








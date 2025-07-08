#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame->setFrameStyle(QFrame::Box | QFrame::Sunken);




    //Pegam as coordenadas do priemrio ponto
    connect(ui->x1, SIGNAL(valueChanged(double)), this, SLOT(CaptureX1(double)));
    connect(ui->y1, SIGNAL(valueChanged(double)), this, SLOT(CaptureY1(double)));
    connect(ui->z1, SIGNAL(valueChanged(double)), this, SLOT(CaptureZ1(double)));

    // coordenadas do segundo ponto
    connect(ui->x2, SIGNAL(valueChanged(double)), this, SLOT(CaptureX2(double)));
    connect(ui->y2, SIGNAL(valueChanged(double)), this, SLOT(CaptureY2(double)));
    connect(ui->z2, SIGNAL(valueChanged(double)), this, SLOT(CaptureZ2(double)));

    // numeros que multiplicam os pontos
    connect(ui->multi_x, SIGNAL(valueChanged(double)), this, SLOT(CaptureMultiplicadorX(double)));
    connect(ui->multi_y, SIGNAL(valueChanged(double)), this, SLOT(CaptureMultiplicadorY(double)));
    connect(ui->multi_y_2, SIGNAL(valueChanged(double)), this, SLOT(CaptureMultiplicadorZ(double)));

    // angulo de rotação (em graus)
    connect(ui->anguloZ, SIGNAL(valueChanged(double)), this, SLOT(CaptureAnguloxy(double)));
    connect(ui->anguloX, SIGNAL(valueChanged(double)), this, SLOT(CaptureAnguloyz(double)));
    connect(ui->anguloY, SIGNAL(valueChanged(double)), this, SLOT(CaptureAnguloxz(double)));


    connect(ui->Index, SIGNAL(valueChanged(int)), this, SLOT(ChangShape(int)));
   // connect(ui->EditorDeNome, SIGNAL(valueChanged(QString)), this, SLOT(SetarFileName(QString)));


}

void MainWindow::VirarDir(){

    ui->frame->girarDir = false;

}

void MainWindow::VirarEsq(){

    ui->frame->girarDir = true;

}

void MainWindow::CaptureX1(double v){

    ui->frame->x0 = v;
}
void MainWindow::CaptureY1(double v){

    ui->frame->y0 = v;
}

void MainWindow::CaptureZ1(double v){

    ui->frame->z0 = v;
}

void MainWindow::CaptureX2(double v){

    ui->frame->x2 = v;
}
void MainWindow::CaptureY2(double u){

    ui->frame->y2 = u;
}

void MainWindow::CaptureZ2(double u){

    ui->frame->z2 = u;
}

void MainWindow::CaptureMultiplicadorX(double u){

    ui->frame->multiX = u;
}

void MainWindow::CaptureMultiplicadorY(double u){

    ui->frame->multiY = u;
}

void MainWindow::CaptureMultiplicadorZ(double u){

    ui->frame->multiZ = u;
}

void MainWindow::CaptureAnguloxy(double u){

    ui->frame->anguloZ = u;
}

void MainWindow::CaptureAnguloyz(double u){

    ui->frame->anguloX = u;
}

void MainWindow::CaptureAnguloxz(double u){

    ui->frame->anguloY = u;
}

void MainWindow::ChangShape(int u){

    u = qBound(0, u, ui->frame->maxShape);

    ui->frame->index = u;


}
void MainWindow::SetarFileName(QString v){

    ui->frame->FileNome = v;


}


MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::on_Index_valueChanged()
{

    if(ui->Index->maximum() != ui->frame->maxShape)
        ui->Index->setMaximum(ui->frame->maxShape);


}

*/

void MainWindow::on_lineEdit_14_textChanged(const QString &arg1)
{
    ui->frame->FileNome = arg1;
}


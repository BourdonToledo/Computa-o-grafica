#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "newframe.h"
#include "ui_mainwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void CaptureX1(double v);
    void CaptureY1(double v);
    void CaptureZ1(double v);
    void CaptureX2(double v);
    void CaptureY2(double u);
    void CaptureZ2(double v);
    void VirarDir();
    void VirarEsq();
    void CaptureAnguloxy(double u);
    void CaptureAnguloyz(double u);
    void CaptureAnguloxz(double u);
    void CaptureMultiplicadorX(double u);
    void CaptureMultiplicadorY(double u);
    void CaptureMultiplicadorZ(double u);
    void ChangShape(int u);
    void SetarFileName(QString v);

private slots:

   // void on_Index_valueChanged();

    void on_lineEdit_14_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

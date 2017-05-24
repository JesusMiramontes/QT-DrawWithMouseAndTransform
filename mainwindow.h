#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matriz.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QPixmap *pix;
    QPainter* paint;
    //QMatrix* matrix;
    QPen* pen;
    matriz* dibujo;
    void dibujarLinea(QPointF *p1, QPointF *p2);
    void dibujarMatriz(matriz *m);
    void configurarDibujo();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

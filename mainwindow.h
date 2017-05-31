#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matriz.h"
#include <QPen>
#include "mouse.h"
#include <QColor>

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
    //QPen* pen;
    matriz* dibujo;
    void dibujarLinea(QPointF *p1, QPointF *p2, QColor c = Qt::green);
    void dibujarMatriz(matriz *m);
    void configurarDibujo();
    void redibujar();
    QColor color;
    ~MainWindow();

private slots:
    void on_btnTrasladar_clicked();

    void on_btnEscalar_clicked();

    void on_btnRotar_clicked();

    void Mouse_current_pos();
    void Mouse_Pressed();
    void Mouse_Left();

    void on_pushButton_clicked();

    void on_btnColor_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

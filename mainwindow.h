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

    // Elementos para dibujar en pantalla
    QPixmap *pix;
    QPainter* paint;

    // Objeto matríz que almacena las coordenadas del dibujo
    matriz* dibujo;

    // Dibuja una línea de un punto A a un punto B usando el color recibido
    void dibujarLinea(QPointF *p1, QPointF *p2, QColor c = Qt::green);

    // Recibe una matriz y dibuja una linea entre cada punto
    void dibujarMatriz(matriz *m);

    // Dibuja un cuadrado simple en la pantalla
    void configurarDibujo();

    // Limpia la pantalla y dibuja la matríz
    void redibujar();

    // Limpia la pantalla
    void configurarCanvas();

    // Almacena el último color seleccionado con el ColorDialog
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

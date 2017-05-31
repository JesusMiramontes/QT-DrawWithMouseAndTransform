#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpixmap.h"
#include "qpainter.h"
#include "qbrush.h"
#include "matriz.h"
#include "math.h"
#include "stdio.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Configuración de pixmap
    // Asigna el tamaño del pixmap con respecto al tamaño del label donde se dibujará
    pix = new QPixmap(ui->drawing_area->width(), ui->drawing_area->height());
    pix->fill(Qt::transparent); //Fondo transparente

    // Instancía el painter
    paint = new QPainter(pix);

    // Instancía QMatrix
    //matrix = new QMatrix();

    // Instancia matriz
    dibujo = new matriz();

    // Configuración de pluma
    pen = new QPen(); // Instancía la pluma
    // pen.setStyle(Qt::SolidLine); // Establece el estilo de la línea
    // pen.setWidth(width); // Establece el ancho de la línea
    // pen.setBrush(Qt::black); // Color de línea
    // pen.setCapStyle(Qt::SquareCap); //Forma de extremos de lina (cuadrado, redondeado, etc)

    configurarDibujo();
    dibujarMatriz(dibujo);

    matriz* nueva = matriz::rotar(dibujo,10);
    nueva = matriz::trasladar(nueva, 300, 300);
    dibujarMatriz( nueva );
}

void MainWindow::dibujarLinea(QPointF *p1, QPointF *p2)
{
    paint->drawLine(*p1, *p2);
    ui->drawing_area->setPixmap(*pix);
}

void MainWindow::dibujarMatriz(matriz* m)
{
    for(int i = 0; i < m->getTamano()-1; i++){
        QPointF* p1 = new QPointF(m->getAbsoluteValue(i,0),m->getValue(i,1));
        QPointF* p2 = new QPointF(m->getAbsoluteValue(i+1,0),m->getValue(i+1,1));
        dibujarLinea(p1, p2);
    }
}

void MainWindow::configurarDibujo()
{
    coordenada* c = new coordenada(10,10);
    dibujo->coordenadas.append(c);
    c = new coordenada(210,10);
    dibujo->coordenadas.append(c);
    c = new coordenada(210,210);
    dibujo->coordenadas.append(c);
    c = new coordenada(10,210);
    dibujo->coordenadas.append(c);
    c = new coordenada(10,10);
    dibujo->coordenadas.append(c);
    //dibujo->coordenadas << (new coordenada(0,0));
    //dibujo->coordenadas << (new coordenada(100,100));
}

MainWindow::~MainWindow()
{
    delete ui;
}

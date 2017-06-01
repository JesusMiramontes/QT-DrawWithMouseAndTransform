#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpixmap.h"
#include "qpainter.h"
#include "qbrush.h"
#include "matriz.h"
#include "math.h"
#include "stdio.h"
#include <QPen>
#include "mouse.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->drawing_area, SIGNAL(mousePosition()), this, SLOT(Mouse_current_pos()));
    connect(ui->drawing_area, SIGNAL(mousePressed()), this, SLOT(Mouse_Pressed()));
    connect(ui->drawing_area, SIGNAL(mouseLeft()), this, SLOT(Mouse_Left()));

    // Configuración de pixmap
    // Asigna el tamaño del pixmap con respecto al tamaño del label donde se dibujará
    pix = new QPixmap(ui->drawing_area->width(), ui->drawing_area->height());
    pix->fill(Qt::black); //Fondo transparente

    // Instancía el painter
    paint = new QPainter(pix);

    // Instancía QMatrix
    //matrix = new QMatrix();

    // Instancia matriz
    dibujo = new matriz();

    // Configuración de pluma
    //pen = new QPen(); // Instancía la pluma
    //pen->setStyle(Qt::SolidLine); //Estilo de linea
    //pen->setWidth(3); //Ancho de linea
    //pen->setBrush(Qt::green); //Color de lina
    //pen->setCapStyle(Qt::RoundCap); //Forma de extremos de lina (cuadrado, redondeado, etc)
    //pen->setJoinStyle(Qt::RoundJoin);

    //configurarDibujo();
    //dibujarMatriz(dibujo);

    //matriz* nueva = matriz::rotar(dibujo,10);
    //nueva = matriz::trasladar(nueva, 300, 300);
    //dibujarMatriz( nueva );
    //color = QColorDialog::getColor(Qt::white, this, "Choose color");
    color = Qt::green;
    configurarCanvas();
}

void MainWindow::dibujarLinea(QPointF *p1, QPointF *p2, QColor c)
{
    QPen pen;  // creates a default pen

    pen.setStyle(Qt::SolidLine); //Estilo de linea
    pen.setWidth(3); //Ancho de linea
    pen.setBrush(c); //Color de linea
    pen.setCapStyle(Qt::RoundCap); //Forma de extremos de lina (cuadrado, redondeado, etc)
    pen.setJoinStyle(Qt::RoundJoin);

    paint->setPen(pen); //Color separador
    paint->drawLine(*p1, *p2);
    ui->drawing_area->setPixmap(*pix);
}

void MainWindow::dibujarMatriz(matriz* m)
{
    // Dibuja todos los puntos
    for(int i = 0; i < m->getTamano()-1; i++){
        QColor c = m->getColor(i+1);
        QPointF* p1 = new QPointF(m->getAbsoluteValue(i,0),m->getValue(i,1));
        QPointF* p2 = new QPointF(m->getAbsoluteValue(i+1,0),m->getValue(i+1,1));
        dibujarLinea(p1, p2, c);
    }

    //Dibuja linea entre el último punto y el primero
    QColor c = m->getColor(m->getTamano()-1);
    c.setAlpha(50);
    QPointF* p1 = new QPointF(m->getAbsoluteValue(0,0),m->getValue(0,1));
    QPointF* p2 = new QPointF(m->getAbsoluteValue(m->getTamano()-1,0),m->getValue(m->getTamano()-1,1));
    dibujarLinea(p1, p2, c);
}

void MainWindow::configurarDibujo()
{ 
    dibujo->addCoord(10,10);
    dibujo->addCoord(210,10);
    dibujo->addCoord(210,210);
    dibujo->addCoord(10,210);
    //dibujo->addCoord(10,10);
}

void MainWindow::redibujar()
{
    pix->fill(Qt::black); //Fondo
    dibujarMatriz(dibujo);
}

void MainWindow::configurarCanvas()
{
    pix->fill(Qt::black);
    ui->drawing_area->setPixmap(*pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnTrasladar_clicked()
{
    dibujo = matriz::trasladar(dibujo, ui->iTx->text().toFloat(), ui->iTy->text().toFloat());
    redibujar();
}

void MainWindow::on_btnEscalar_clicked()
{
    // Almacena la posicion del punto fijo antes de escalar
    float x, y;
    x = dibujo->getValue(0,0);
    y = dibujo->getValue(0,1);

    // Escala el dibujo
    dibujo = matriz::escalar(dibujo, ui->iSx->text().toFloat(), ui->iSy->text().toFloat());

    // Calcula la diferencia de pixeles entre la posicíon original y la nueva
    float dx, dy;
    dx = dibujo->getValue(0,0)-x;
    dy = dibujo->getValue(0,1)-y;

    // Traslada el dibujo a su posición original
    dibujo = matriz::trasladar(dibujo, -dx, -dy);

    redibujar();
}

void MainWindow::on_btnRotar_clicked()
{
    // Almacena la posicion del punto fijo antes de rotar
    float x, y;
    x = dibujo->getValue(0,0);
    y = dibujo->getValue(0,1);

    // Rota el dibujo
    dibujo = matriz::rotar(dibujo, ui->iAngulo->text().toFloat());

    // Calcula la diferencia de pixeles entre la posicíon original y la nueva
    float dx, dy;
    dx = dibujo->getValue(0,0)-x;
    dy = dibujo->getValue(0,1)-y;

    // Traslada el dibujo a su posición original
    dibujo = matriz::trasladar(dibujo, -dx, -dy);

    redibujar();
}

void MainWindow::Mouse_current_pos()
{

}

void MainWindow::Mouse_Pressed()
{
    dibujo->addCoord(ui->drawing_area->x, ui->drawing_area->y,1,color);
    redibujar();
}

void MainWindow::Mouse_Left()
{

}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_btnColor_clicked()
{
    color = QColorDialog::getColor(Qt::white, this, "Choose color");
}

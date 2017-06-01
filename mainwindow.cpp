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
#include <QMatrix>
#include <qmath.h>

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
    QMatrix translationMatrix(1, 0, 0, 1, ui->iTx->text().toFloat(), ui->iTy->text().toFloat());
    paint->setMatrix(translationMatrix);
    redibujar();
}

void MainWindow::on_btnEscalar_clicked()
{
    // Escala el dibujo
    QMatrix scalingMatrix(ui->iSx->text().toFloat(), 0, 0, ui->iSy->text().toFloat(), 0, 0);

    paint->setMatrix(scalingMatrix);
    redibujar();
}

void MainWindow::on_btnRotar_clicked()
{
    double a = qDegreesToRadians(ui->iAngulo->text().toFloat());

    double sina = sin(a);
    double cosa = cos(a);

    QMatrix rotationMatrix(cosa, sina, -sina, cosa, 0, 0);
    paint->setMatrix(rotationMatrix);

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

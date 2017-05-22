#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Asigna el tamaño del pixmap con respecto al tamaño del label donde se dibujará
    pix = new QPixmap(ui->drawing_area->width(), ui->drawing_area->height());

    // Establece el fondo transparente
    pix->fill(Qt::transparent); //Fondo transparente

    // Instancía el painter
    paint = new QPainter(pix);

    // Instancía QMatrix
    matrix = new QMatrix();

    // Configuración de pluma
    // Instancía la pluma
    pen = new QPen();

    // Establece el estilo de la línea
    pen.setStyle(Qt::SolidLine);

    // Establece el ancho de la línea
    pen.setWidth(width);

    // Color de línea
    pen.setBrush(Qt::black);

    // Estílo de línea
    pen.setCapStyle(Qt::SquareCap); //Forma de extremos de lina (cuadrado, redondeado, etc)
}

MainWindow::~MainWindow()
{
    delete ui;
}

#ifndef MATRIZ_H
#define MATRIZ_H
#include "coordenada.h"
#include "QList"
#include <QMatrix>

class matriz
{
public:
    matriz();

    // Recibe una matriz transformación y una matríz dibujo y ejecuta una multiplicacion entre ambas
    // Este método se utiliza en cada una de las transformaciones
    static matriz* transformar(matriz* matriz_transformacion, matriz* matriz_dibujo);

    // Recibe y regresa una matríz despues de trasladarla en x y y según los valores recibidos
    static QMatrix* trasladar(float tx=0, float ty=0);

    // Recibe y regresa una matriz despues de escalarla según los valores recibidos
    static matriz* escalar(matriz* matriz_dibujo, float sx=0, float sy=0);

    // Recibe y regresa una matriz despues de rotarla con respecto al angulo recibido
    static matriz* rotar(matriz* matriz_dibujo, int angle=0);

    // Regresa la cantidad de matrices almacenadas
    int getTamano();

    // Regresa el valor de en la posición recibida
    float getValue(int renglon, int columna);

    // Regresa el color de la coordenada
    QColor getColor(int renglon);

    // Asigna el valor recibido en la posicion indicada
    void setValue(int renglon, int columna, float value);

    // Regresa el valor dividido entre su correspondiente W
    float getAbsoluteValue(int renglon, int columna);

    // Almacena las coordenadas
    QList<coordenada*> coordenadas;

    // Asigna los valores a 0
    void setCeros();

    // Agrega la coordenada recibida a la lista
    void addCoord(float x, float y, float w=1, QColor color = Qt::green);
private:


};

#endif // MATRIZ_H

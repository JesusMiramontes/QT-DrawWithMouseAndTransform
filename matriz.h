#ifndef MATRIZ_H
#define MATRIZ_H
#include "coordenada.h"
#include "QList"

class matriz
{
public:
    matriz();
    static matriz* transformar(matriz* matriz_transformacion, matriz* matriz_escalar);
    static matriz* trasladar(matriz* matriz_a_transformar, float tx=0, float ty=0);
    static void rotar();
    static void escalar();
    int getTamano();
    float getValue(int renglon, int columna);
    void setValue(int renglon, int columna, float value);
    QList<coordenada*> coordenadas;
    void setCeros();
private:


};

#endif // MATRIZ_H

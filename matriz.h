#ifndef MATRIZ_H
#define MATRIZ_H
#include "coordenada.h"
#include "QList"

class matriz
{
public:
    matriz();
    static matriz* transformar(matriz* matriz_transformacion, matriz* matriz_dibujo);
    static matriz* trasladar(matriz* matriz_dibujo, float tx=0, float ty=0);
    static matriz* escalar(matriz* matriz_dibujo, float sx=0, float sy=0);
    static void rotar();
    static void escalar();
    int getTamano();
    float getValue(int renglon, int columna);
    void setValue(int renglon, int columna, float value);
    float getAbsoluteValue(int renglon, int columna);
    QList<coordenada*> coordenadas;
    void setCeros();
private:


};

#endif // MATRIZ_H

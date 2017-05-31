#include "matriz.h"

matriz::matriz()
{
    // coordenada temp = new coordenada(0,0);
    // this->coordenadas << temp;
    // this->coordenadas << temp;
    // this->coordenadas << temp;
}

matriz* matriz::transformar(matriz *matriz_transformacion, matriz *matriz_dibujo)
{
    float result[3] = {0,0,0};
    matriz* temp = new matriz();

    temp = matriz_dibujo;

    int m = 0;

    while(m < matriz_dibujo->getTamano()){
        result[0] = 0; result[1] = 0; result[2] = 0;
        for(int renglon = 0; renglon < 3; renglon++){
            for(int columna = 0; columna < 3; columna++){
                result[renglon] += matriz_transformacion->getValue(columna,renglon) * (matriz_dibujo->getValue(m,columna));
            }
        }

        temp->setValue(m,0,floor(result[0]));
        temp->setValue(m,1,floor(result[1]));
        temp->setValue(m,2,1);
        m++;
    }

    return temp;
}

matriz *matriz::trasladar(matriz* matriz_dibujo, float tx, float ty)
{
    matriz* matriz_transformacion = new matriz();
    matriz_transformacion->setCeros();
    matriz_transformacion->setValue(0,0,1);
    matriz_transformacion->setValue(1,1,1);
    matriz_transformacion->setValue(2,2,1);
    matriz_transformacion->setValue(2,0,tx);
    matriz_transformacion->setValue(2,1,ty);

    return transformar(matriz_transformacion, matriz_dibujo);
}

matriz *matriz::escalar(matriz *matriz_dibujo, float sx, float sy)
{
    matriz* matriz_transformacion = new matriz();
    matriz_transformacion->setCeros();
    matriz_transformacion->setValue(0,0,sx);
    matriz_transformacion->setValue(1,1,sy);
    matriz_transformacion->setValue(2,2,1);

    return transformar(matriz_transformacion, matriz_dibujo);
}

int matriz::getTamano()
{
    return (coordenadas.count());
}

float matriz::getValue(int renglon, int columna)
{
    switch(columna){
        case 0:
            return this->coordenadas[renglon]->x;
                break;
        case 1:
            return this->coordenadas[renglon]->y;
                break;
        case 2:
            return this->coordenadas[renglon]->w;
                break;
        default:
            return -1;
                break;
    }
}

void matriz::setValue(int renglon, int columna, float value)
{
    switch(columna){
        case 0:
            this->coordenadas[renglon]->x = value;
                break;
        case 1:
            this->coordenadas[renglon]->y = value;
                break;
        case 2:
            this->coordenadas[renglon]->w = value;
                break;
        default:
                break;
    }
}

float matriz::getAbsoluteValue(int renglon, int columna)
{
    switch(columna){
        case 0:
            return this->coordenadas[renglon]->x/this->coordenadas[renglon]->w;
                break;
        case 1:
            return this->coordenadas[renglon]->y/this->coordenadas[renglon]->w;
                break;
        case 2:
            return this->coordenadas[renglon]->w/this->coordenadas[renglon]->w;
                break;
        default:
            return -1;
                break;
    }
}

void matriz::setCeros()
{
    coordenada* c = new coordenada(0,0,0);
    coordenadas.append(c);
    c = new coordenada(0,0,0);
    coordenadas.append(c);
    c = new coordenada(0,0,0);
    coordenadas.append(c);
}

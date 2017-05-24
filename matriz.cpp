#include "matriz.h"

matriz::matriz()
{
    // coordenada temp = new coordenada(0,0);
    // this->coordenadas << temp;
    // this->coordenadas << temp;
    // this->coordenadas << temp;
}

matriz* matriz::transformar(matriz *matriz_transformacion, matriz *matriz_escalar)
{
    float result[3] = {0,0,0};
    matriz* temp = new matriz();
    int i = 0;
    int renglon = 0;
    int columna = 0;

    //coordenada* c = new coordenada(0,0);
    //c = new coordenada(0,0);
    //temp->coordenadas.append(c);
    //c = new coordenada(0,0);
    //temp->coordenadas.append(c);
    //c = new coordenada(0,0);
    //temp->coordenadas.append(c);
    temp = matriz_escalar;

    while(i < matriz_transformacion->getTamano()){
        result[0] = 0; result[1] = 0; result[2] = 0;

        while(renglon < 3){
            while(columna < 3){
                float f = matriz_transformacion->getValue(columna,renglon);
                f *= (matriz_escalar->getValue(i,columna));
                result[renglon] += f;
                columna++;
            }

        renglon++;
        }
        i++;
        temp->setValue(i,0,floor(result[0]));
        temp->setValue(i,1,floor(result[1]));
        temp->setValue(i,2,1);

    }

    return temp;
}

matriz *matriz::trasladar(matriz* matriz_a_transformar, float tx, float ty)
{
    matriz* matriz_transformacion = new matriz();
    matriz_transformacion->setCeros();
    matriz_transformacion->setValue(0,0,1);
    matriz_transformacion->setValue(1,1,1);
    matriz_transformacion->setValue(2,0,tx);
    matriz_transformacion->setValue(2,1,ty);

    return transformar(matriz_transformacion, matriz_a_transformar);
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

void matriz::setCeros()
{
    coordenada* c = new coordenada(0,0);
    coordenadas.append(c);
    c = new coordenada(0,0);
    coordenadas.append(c);
    c = new coordenada(0,0);
    coordenadas.append(c);
}

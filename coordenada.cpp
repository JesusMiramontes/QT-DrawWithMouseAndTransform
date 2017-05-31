#include "coordenada.h"
#include "matriz.h"
#include <QColor>

coordenada::coordenada()
{

}

coordenada::coordenada(float x, float y, float w, QColor color)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->color = color;
}

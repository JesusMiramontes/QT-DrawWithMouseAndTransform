#ifndef COORDENADA_H
#define COORDENADA_H
#include <QColor>

class coordenada
{
public:
    coordenada();

    // Constructor que recibe los valores x, y, w, color.
    coordenada(float x, float y, float w=1, QColor color = Qt::green);

    // Propiedades
    float x;
    float y;
    float w;
    QColor color;
};

#endif // COORDENADA_H

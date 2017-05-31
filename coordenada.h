#ifndef COORDENADA_H
#define COORDENADA_H
#include <QColor>

class coordenada
{
public:
    coordenada();
    coordenada(float x, float y, float w=1, QColor color = Qt::green);
    float x;
    float y;
    float w;
    QColor color;
};

#endif // COORDENADA_H

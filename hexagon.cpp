#include "hexagon.h"

#include <QPainter>

#include <cmath>

qreal Hexagon::getRadius() {
    return radius;
}

void Hexagon::setRadius(qreal radius) {
    this->radius = radius;
    // acha medidas importantes
    W = 2 * radius;
    S = 1.5 * radius;
    H = sqrt(3) * radius;
    setImplicitHeight(H + 1);
    setImplicitWidth(W + 1);
    emit radiusChanged();
}

QColor Hexagon::getColor() {
    return color;
}

void Hexagon::setColor(const QColor& color) {
    this->color = color;
    emit colorChanged();
}

void Hexagon::paint(QPainter *painter) {
    const qreal halfH = H / 2;
    const qreal s_radius = S - radius;
    static QPointF points[] = {
        QPointF(0, halfH),
        QPointF(s_radius, 0),
        QPointF(S, 0),
        QPointF(W, halfH),
        QPointF(S, H),
        QPointF(s_radius, H),
    };

    painter->setPen(color);
    painter->drawPolygon(points, 6);
}

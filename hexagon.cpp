#include "hexagon.h"

#include <QPainter>

#include <cmath>

qreal Hexagon::getRaio() {
    return raio;
}

void Hexagon::setRaio(qreal raio) {
    this->raio = raio;
    // acha medidas importantes
    W = 2 * raio;
    S = 1.5 * raio;
    H = sqrt(3) * raio;
    setImplicitHeight(H);
    setImplicitWidth(W);
    emit raioChanged();
}

QColor Hexagon::getCor() {
    return cor;
}

void Hexagon::setCor(const QColor& cor) {
    this->cor = cor;
    emit corChanged();
}

void Hexagon::paint(QPainter *painter) {
    const qreal meioH = H / 2;
    const qreal s_raio = S - raio;
    static QPointF points[] = {
        QPointF(0, meioH),
        QPointF(s_raio, 0),
        QPointF(S, 0),
        QPointF(W, meioH),
        QPointF(S, H),
        QPointF(s_raio, H),
    };

    painter->setPen(cor);
    painter->drawPolygon(points, 6);
}

#include "hexagon.h"

#include <QPainter>

qreal Hexagon::getRadius() const {
    return radius;
}

void Hexagon::setRadius(qreal radius) {
    this->radius = radius;
    emit radiusChanged();

    setImplicitHeight(getH() + 1);
    setImplicitWidth(getW() + 1);

    emit WChanged();
    emit SChanged();
    emit HChanged();
}

qreal Hexagon::getW() const {
    return 2 * radius;
}

qreal Hexagon::getS() const {
    return 1.5 * radius;
}

qreal Hexagon::getH() const {
    return sqrt(3) * radius;
}

QColor Hexagon::getLineColor() const {
    return lineColor;
}

QColor Hexagon::getFillColor() const {
    return fillColor;
}

void Hexagon::setLineColor(const QColor& color) {
    lineColor = color;
    emit lineColorChanged();
}

void Hexagon::setFillColor(const QColor& color) {
    fillColor = color;
    emit fillColorChanged();
}

void Hexagon::paint(QPainter *painter) {
    const qreal H = getH(), S = getS(), W = getW();
    const qreal halfH = H / 2;
    const qreal s_radius = S - radius;

    const QVector<QPointF> points = {
        QPointF(0, halfH),
        QPointF(s_radius, 0),
        QPointF(S, 0),
        QPointF(W, halfH),
        QPointF(S, H),
        QPointF(s_radius, H),
        QPointF(0, halfH),
    };
    const QPolygonF poly(points);
    QPainterPath path;
    path.addPolygon(poly);

    painter->fillPath(path, fillColor);
    painter->setPen(lineColor);
    painter->drawPath(path);
}

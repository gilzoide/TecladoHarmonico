#ifndef HEXAGON_H
#define HEXAGON_H

#include <QQuickPaintedItem>

class Hexagon : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(qreal radius READ getRadius WRITE setRadius NOTIFY radiusChanged)
    Q_PROPERTY(QColor color READ getColor WRITE setColor NOTIFY colorChanged)

public:
    void paint(QPainter *painter) override;

    qreal getRadius();
    void setRadius(qreal radius);

    QColor getColor();
    void setColor(const QColor& color);

signals:
    void radiusChanged();
    void colorChanged();

private:
    qreal radius;
    /// Medidas importantes pra vários cálculos. Veja: http://blog.ruslans.com/2011/02/hexagonal-grid-math.html
    qreal W, S, H;
    /// Cor do traçado
    QColor color;
};

#endif // HEXAGON_H

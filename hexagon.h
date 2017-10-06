#ifndef HEXAGON_H
#define HEXAGON_H

#include <QQuickPaintedItem>

class Hexagon : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(qreal radius READ getRadius WRITE setRadius NOTIFY radiusChanged)
    Q_PROPERTY(qreal W READ getW NOTIFY WChanged)
    Q_PROPERTY(qreal S READ getS NOTIFY SChanged)
    Q_PROPERTY(qreal H READ getH NOTIFY HChanged)
    Q_PROPERTY(QColor color READ getColor WRITE setColor NOTIFY colorChanged)

public:
    void paint(QPainter *painter) override;

    qreal getRadius() const;
    void setRadius(qreal radius);

    qreal getW() const;
    qreal getS() const;
    qreal getH() const;

    QColor getColor() const;
    void setColor(const QColor& color);

signals:
    void radiusChanged();
    void WChanged();
    void SChanged();
    void HChanged();
    void colorChanged();

private:
    qreal radius;
    /// Medidas importantes pra vários cálculos. Veja: http://blog.ruslans.com/2011/02/hexagonal-grid-math.html
    qreal W, S, H;
    /// Cor do traçado
    QColor color;
};

#endif // HEXAGON_H

#ifndef HEXAGON_H
#define HEXAGON_H

#include <QQuickPaintedItem>

#include <cmath>

class Hexagon : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(qreal radius READ getRadius WRITE setRadius NOTIFY radiusChanged)
    /// Important measures used for some calculations. See: http://blog.ruslans.com/2011/02/hexagonal-grid-math.html
    Q_PROPERTY(qreal W READ getW NOTIFY WChanged)
    Q_PROPERTY(qreal S READ getS NOTIFY SChanged)
    Q_PROPERTY(qreal H READ getH NOTIFY HChanged)

    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor NOTIFY lineColorChanged)
    Q_PROPERTY(QColor fillColor READ getFillColor WRITE setFillColor NOTIFY fillColorChanged)

public:
    void paint(QPainter *painter) override;

    qreal getRadius() const;
    void setRadius(qreal radius);

    qreal getW() const;
    qreal getS() const;
    qreal getH() const;

    QColor getLineColor() const;
    QColor getFillColor() const;
    void setLineColor(const QColor& color);
    void setFillColor(const QColor& color);

signals:
    void radiusChanged();
    void WChanged();
    void SChanged();
    void HChanged();
    void lineColorChanged();
    void fillColorChanged();

private:
    /// Hexagon radius
    qreal radius;
    /// Line color
    QColor lineColor;
    /// Fill color
    QColor fillColor;
};

#endif // HEXAGON_H

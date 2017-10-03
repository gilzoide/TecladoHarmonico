#ifndef HEXAGON_H
#define HEXAGON_H

#include <QQuickPaintedItem>

class Hexagon : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(qreal raio READ getRaio WRITE setRaio NOTIFY raioChanged)
    Q_PROPERTY(QColor cor READ getCor WRITE setCor NOTIFY corChanged)

public:
    void paint(QPainter *painter) override;

    qreal getRaio();
    void setRaio(qreal raio);

    QColor getCor();
    void setCor(const QColor& cor);

signals:
    void raioChanged();
    void corChanged();

private:
    qreal raio;
    /// Medidas importantes pra vários cálculos. Veja: http://blog.ruslans.com/2011/02/hexagonal-grid-math.html
    qreal W, S, H;
    /// Cor do traçado
    QColor cor;
};

#endif // HEXAGON_H

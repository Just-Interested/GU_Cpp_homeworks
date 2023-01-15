#ifndef MYGRAPHICITEM_H
#define MYGRAPHICITEM_H

#include <QObject>
#include <QGraphicsItem>



class MyGraphicItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    enum MyItemType {RECTANGLE, ELLIPSE, STAR};
    explicit MyGraphicItem(QObject *parent = nullptr);
    MyGraphicItem(MyItemType t, QObject *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setItemSize(uint8_t w, uint8_t h) {width = w, height = h;}

private:
    MyItemType type;
    uint8_t width;
    uint8_t height;
    QColor color;
    bool moving;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

signals:

};

#endif // MYGRAPHICITEM_H

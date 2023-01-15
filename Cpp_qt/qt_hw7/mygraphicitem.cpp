#include "mygraphicitem.h"
#include <QPainter>

#include <QGraphicsSceneMouseEvent>

MyGraphicItem::MyGraphicItem(QObject *parent)
    : QObject{parent}, QGraphicsItem(), type(MyItemType::STAR), width(100), height(100)
{
    moving = false;
    color = QColor(rand() % 256, rand() % 256, rand() % 256);
}

MyGraphicItem::MyGraphicItem(MyItemType t, QObject *parent)
    : QObject{parent}, QGraphicsItem(), type(t), width(200), height(200)
{
    moving = false;
    color = QColor(rand() % 256, rand() % 256, rand() % 256);
}

QRectF MyGraphicItem::boundingRect() const
{
    return QRectF(QPointF(0,0), QSizeF(width, height));
}

void MyGraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setBrush(QBrush(color));
    painter->setPen(QPen(color));
    if (type == MyItemType::STAR){
        QPainterPath starPath;
        uint8_t min = (width < height) ? width : height;
        starPath.moveTo(min, min/2);
        for (int i = 1; i < 5; ++i) {
            starPath.lineTo(min/2 + min/2 * std::cos(0.8 * i * M_PI),
                            min/2 + min/2 * std::sin(0.8 * i * M_PI));
        }
        starPath.closeSubpath();
        starPath.setFillRule(Qt::WindingFill);
        painter->drawPath(starPath);
    }
    if (type == MyItemType::ELLIPSE){
        painter->drawEllipse(0, 0, width, height);
    }
    if (type == MyItemType::RECTANGLE){
        painter->drawRect(0, 0, width, height);
    }
}

void MyGraphicItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    if (!event->isAccepted()){
        if (event->button() == Qt::LeftButton){
            moving = true;
            event->accept();
        }
    }
}

void MyGraphicItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (moving == true){
        this->setPos(mapToScene(event->pos()));
    }
}

void MyGraphicItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    moving = false;
}

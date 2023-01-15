#include "customgraphicscene.h"

#include <QGraphicsSceneMouseEvent>

#include "mygraphicitem.h"

#include <QDebug>

CustomGraphicScene::CustomGraphicScene() : QGraphicsScene()
{
    add_item_type = 0;
}

void CustomGraphicScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
    if(!event->isAccepted()){
        if(event->button() == Qt::LeftButton){
            MyGraphicItem* item = nullptr;
            switch (add_item_type){
            case 0:
                item = new MyGraphicItem(MyGraphicItem::MyItemType::RECTANGLE, this);
                item->setPos(event->scenePos());
                item->setItemSize(60, 30);
                add_item_type = 1;
                break;
            case 1:
                item = new MyGraphicItem(MyGraphicItem::MyItemType::ELLIPSE, this);
                item->setPos(event->scenePos());
                item->setItemSize(60, 30);
                add_item_type = 2;
                break;
            case 2:
                item = new MyGraphicItem(MyGraphicItem::MyItemType::STAR, this);
                item->setPos(event->scenePos());
                item->setItemSize(50, 50);
                add_item_type = 0;
                break;
            default:
                item = new MyGraphicItem(MyGraphicItem::MyItemType::RECTANGLE, this);
                item->setPos(event->scenePos());
                item->setItemSize(60, 30);
                break;
            }
            addItem(item);
        } else if (event->button() == Qt::RightButton){
            for (auto item : this->items(event->scenePos())){
                // без break можно удалить все что "под" курсором сразу
                removeItem(item);
                break;
            }
        }
    }
}

#ifndef CUSTOMGRAPHICSCENE_H
#define CUSTOMGRAPHICSCENE_H

#include <QGraphicsScene>

class CustomGraphicScene : public QGraphicsScene
{
public:
    CustomGraphicScene();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    uint8_t add_item_type;
};

#endif // CUSTOMGRAPHICSCENE_H

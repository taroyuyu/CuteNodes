#pragma once

#include <QGraphicsScene>


// Adapted from http://stackoverflow.com/a/15054118/578536

class NodeScene : public QGraphicsScene
{
public:
    explicit NodeScene();
    ~NodeScene() override;

protected:
    void drawBackground(QPainter* painter, const QRectF& rect) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

private:
    QGraphicsItem* _draggedItem;
    QPointF        _draggedOffset;
    QSize          _gridSize;
};

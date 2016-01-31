#pragma once

#include <QGraphicsScene>


// Adapted from http://stackoverflow.com/a/15054118/578536

class NodeScene : public QGraphicsScene
{
public:
    explicit NodeScene(const QRectF& sceneRect);
    ~NodeScene() override;

public slots:
    void toggleGridSnapping();

private:
    void drawBackground(QPainter* painter, const QRectF& rect) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    bool draggedNodePositionIsValid(const QPointF& nodePos) const;

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void wheelEvent(QGraphicsSceneWheelEvent* event) override;

private:
    QGraphicsItem* _draggedItem{nullptr};
    QPointF        _draggingMousePointerOffset{0.0, 0.0};
    QSize          _gridSize{20, 20};
    bool           _gridSnapping{true};
};

#pragma once

#include <QGraphicsPathItem>


class CuteConnection : public QGraphicsPathItem
{
public:
    explicit CuteConnection(QGraphicsItem* startItem);
    ~CuteConnection() override;

    enum { Type = UserType + 5 };
    int type() const override { return Type; }

    QGraphicsItem* getEndItem() const;
    void setEndItem(QGraphicsItem* item);
    QGraphicsItem* getStartItem() const;

    void setAsValid();
    void updateEndPoint(const QPointF& endPoint);

private:
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

    QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void snapEndPointsToItems();
    void calculateSpline();
    void addArrowToSpline(QPainterPath& spline) const;

private:
    std::pair<QGraphicsItem*, QGraphicsItem*> _connectedItems;

    // temps
    QPointF _endPoint;
    QPointF _startPoint;
};

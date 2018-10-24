#ifndef BODYPARTSELECTIONSQUARE_H
#define BODYPARTSELECTIONSQUARE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include "Model/DICOM_ENUMS.h"

class BodyPartSelectionSquare : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit BodyPartSelectionSquare(int x,
                                     int y,
                                     int width,
                                     int height,
                                     QObject* parent = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void SetSelectionSquareName(iBEX::BODY_PART name);

signals:
    void NotifyBodyPartSelectionChanged(iBEX::BODY_PART bodypart,bool isSelected);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    int _x,_y,_width,_height;
    bool selected;
    iBEX::BODY_PART _name;

};

#endif // BODYPARTSELECTIONSQUARE_H

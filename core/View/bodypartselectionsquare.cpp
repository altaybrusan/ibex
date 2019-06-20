#include "bodypartselectionsquare.h"
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include "Model/DICOM_ENUMS.h"
#include "Utils/logmgr.h"

BodyPartSelectionSquare::BodyPartSelectionSquare(int x,
                                                 int y,
                                                 int width,
                                                 int height,
                                                 QObject *parent):
    QObject(parent),
    selected(false)
{
    setFlag(ItemIsSelectable); // you need this
    _x = x;
    _y = y;
    _width = width;
    _height = height;
}

QRectF BodyPartSelectionSquare::boundingRect() const
{

    return QRectF(_x,_y,_width,_height);
}

void BodyPartSelectionSquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    widget->hasFocus();// Dummy function no need
    painter->setClipRect( option->exposedRect );
    painter->setPen(QPen(Qt::transparent));


    QRectF rect =boundingRect();
    QBrush brush(QColor(255, 255, 100, 128));

    if(selected)
    {
        brush.setColor(QColor(255, 255, 100, 128));
        emit NotifyBodyPartSelectionChanged(_name,true);
    }
    else
    {
        brush.setColor(QColor(128, 220, 255, 128));
        emit NotifyBodyPartSelectionChanged(_name,false);
    }

    painter->fillRect(rect,brush);
    painter->drawRect(rect);
}

void BodyPartSelectionSquare::SetSelectionSquareName(iBEX::BODY_PART name)
{
    _name = name;
}

void BodyPartSelectionSquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    selected=!selected;
    update();
    QGraphicsItem::mousePressEvent(event);
}


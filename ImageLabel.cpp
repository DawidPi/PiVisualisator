//
// Created by dawid on 8/31/17.
//

#include "ImageLabel.hpp"
#include "Data2PixmapAdapter.hpp"
#include <QMouseEvent>
#include <iostream>

void ImageLabel::mousePressEvent(QMouseEvent *event) {
    QLabel::mousePressEvent(event);
    auto relativePoint = getPositionFromEvent(event);

    if(relativePoint.x() < 0.05f){
        mMousePressed=true;
        auto newResult = relativePoint.y() * ImageData::MAX_VALUE - ImageData::MAX_VALUE/2;
        Q_EMIT newInputValue(static_cast<int>(newResult));
    }
}

void ImageLabel::mouseReleaseEvent(QMouseEvent *event) {
    mMousePressed=false;
    QLabel::mouseReleaseEvent(event);
}

QPointF ImageLabel::getPositionFromEvent(const QMouseEvent *event) {
    auto position = event->globalPos();
    auto imageRelativePos = mapFromGlobal(position);
    auto widgetSize = size();
    auto relativeWidth = (float)imageRelativePos.x() / widgetSize.width();
    auto relativeHeight = 1.0f - (float)imageRelativePos.y() / widgetSize.height();

    return QPointF(relativeWidth, relativeHeight);
}

void ImageLabel::mouseMoveEvent(QMouseEvent *event) {
    if(mMousePressed){
        auto relativePoint = getPositionFromEvent(event);
        auto newResult = relativePoint.y() * ImageData::IMAGE_HEIGHT - ImageData::IMAGE_HEIGHT/2;
        Q_EMIT newInputValue(static_cast<int>(newResult));
    } else {
        QLabel::mouseMoveEvent(event);
    }
}

void ImageLabel::setImageData(const ImageData& data) {
    setPixmap(QPixmap(Data2PixmapAdapter().convert(data)));
}

//
// Created by dawid on 8/31/17.
//

#ifndef PIVISUALISATOR_IMAGELABEL_HPP
#define PIVISUALISATOR_IMAGELABEL_HPP


#include <QtWidgets/QLabel>
#include "ImageData.hpp"

class ImageLabel : public QLabel{
Q_OBJECT
public:
    using QLabel::QLabel;

protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

public:
    void mouseMoveEvent(QMouseEvent *ev) override;
    void setImageData(const ImageData& data);

    Q_SIGNALS:
        void newInputValue(int32_t value);
private:
    QPointF getPositionFromEvent(const QMouseEvent *event);
    bool mMousePressed = false;
};


#endif //PIVISUALISATOR_IMAGELABEL_HPP

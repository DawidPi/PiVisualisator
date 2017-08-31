//
// Created by dawid on 8/30/17.
//

#ifndef PIVISUALISATOR_DATA2PIXMAPADAPTER_HPP
#define PIVISUALISATOR_DATA2PIXMAPADAPTER_HPP


#include <QtGui/QPixmap>
#include "ImageData.hpp"

class Data2PixmapAdapter {
public:
    static QPixmap convert(const ImageData& data);
};


#endif //PIVISUALISATOR_DATA2PIXMAPADAPTER_HPP

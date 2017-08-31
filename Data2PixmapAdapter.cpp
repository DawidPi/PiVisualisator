//
// Created by dawid on 8/30/17.
//

#include "Data2PixmapAdapter.hpp"

QPixmap Data2PixmapAdapter::convert(const ImageData& data) {
    QImage image(data.IMAGE_WIDTH, data.IMAGE_HEIGHT, QImage::Format_Mono);

    for(uint32_t width=0; width < ImageData::IMAGE_WIDTH; ++width){
        for(uint32_t height=0; height < ImageData::IMAGE_HEIGHT; ++height){
            image.setPixel(width, height, static_cast<uint>(data.getPixel(width, height)));
        }
    }

    return QPixmap::fromImage(image);
}

//
// Created by dawid on 8/30/17.
//

#include <QtWidgets/QScrollArea>
#include <QtWidgets/QLabel>
#include <QtCore/QTimer>
#include <QMouseEvent>
#include <iostream>
#include <unitypes.h>
#include "MainWindow.hpp"
#include "ImageData.hpp"
#include "Data2PixmapAdapter.hpp"


MainWindow::MainWindow() : QMainWindow(nullptr) {
    setWindowTitle("PiOS Visualisator");

    mImageLabel = new ImageLabel;
    mImageLabel->setScaledContents(true);
    setCentralWidget(mImageLabel);
    displayGreetings();

    connect(mImageLabel, &ImageLabel::newInputValue, this, &MainWindow::newInput);
}

void MainWindow::displayGreetings() {
    mCurrentImage.fill(false);

    //cross top left to bottom right
    for(uint32_t xSize = 0; xSize < ImageData::IMAGE_HEIGHT; ++xSize){
        mCurrentImage.setPixel(xSize+ImageData::IMAGE_HEIGHT/2,xSize);
    }

    //cross bottom left to top right
    for(uint32_t xSize = 0; xSize < ImageData::IMAGE_HEIGHT; ++xSize){
        mCurrentImage.setPixel(xSize+ImageData::IMAGE_HEIGHT/2,(ImageData::IMAGE_HEIGHT-1)-xSize);
    }

    mCurrentImage.setInput(ImageData::IMAGE_HEIGHT/2);
    mImageLabel->setImageData(mCurrentImage);
}

void MainWindow::newInput(int newValue) {
    mCurrentImage.setInput(newValue);
    mImageLabel->setPixmap(QPixmap(Data2PixmapAdapter().convert(mCurrentImage)));
}

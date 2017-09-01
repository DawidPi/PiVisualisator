//
// Created by dawid on 8/30/17.
//

#include <QtWidgets/QScrollArea>
#include <QtWidgets/QLabel>
#include <QtCore/QTimer>
#include <QMouseEvent>
#include <iostream>
#include "MainWindow.hpp"
#include "ImageData.hpp"
#include "Data2PixmapAdapter.hpp"
#include <QDebug>


MainWindow::MainWindow() : QMainWindow(nullptr) {
    setWindowTitle("PiOS Visualisator");

    qDebug() << "MainWindow::MainWindow()";
    mImageLabel = new ImageLabel;
    mImageLabel->setScaledContents(true);
    setCentralWidget(mImageLabel);
    qDebug() << "MainWindow::MainWindow(): image label created";
    displayGreetings();

    qDebug() << "MainWindow::MainWindow(): connect ImageLabel(newInputValue) -> MainWindow(newInput)";
    connect(mImageLabel, &ImageLabel::newInputValue, this, &MainWindow::newInput);

    qDebug() << "MainWindow::MainWindow(): Creating Qemu manager";
    mQemu = new QemuManager(this);

    qDebug() << "MainWindow::MainWindow(): connect QemuManager(newInputValueAccepted) -> MainWindow(newInputSent)";
    connect(mQemu, &QemuManager::newInputValueAccepted, this, &MainWindow::newInputSent);
    qDebug() << "MainWindow::MainWindow(): connect QemuManager(newDataArrived) -> MainWindow(newImageDataAvailable)";
    connect(mQemu, &QemuManager::newDataArrived, this, &MainWindow::newImageDataAvailable);

    qDebug() << "MainWindow::MainWindow(): starting Qemu";
    mQemu->start();
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
    mQemu->writeNewValue(newValue);
}

void MainWindow::newInputSent(int newValue) {
}

void MainWindow::newImageDataAvailable(ImageData data) {
    mImageLabel->setImageData(data);
}

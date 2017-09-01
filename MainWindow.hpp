//
// Created by dawid on 8/30/17.
//

#ifndef PIVISUALISATOR_MAINWINDOW_HPP
#define PIVISUALISATOR_MAINWINDOW_HPP


#include <QtWidgets/QMainWindow>
#include "ImageData.hpp"
#include "ImageLabel.hpp"
#include "QemuManager.hpp"

class QLabel;
class QTimer;

class MainWindow : public QMainWindow {
public:

public:
    MainWindow();

private:
    ImageLabel* mImageLabel;
    QemuManager* mQemu;
    ImageData mCurrentImage;

    void displayGreetings();
    void newInput(int newValue);

private Q_SLOTS:
    void newInputSent(int newValue);
    void newImageDataAvailable(ImageData data);

};


#endif //PIVISUALISATOR_MAINWINDOW_HPP

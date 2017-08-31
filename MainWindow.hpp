//
// Created by dawid on 8/30/17.
//

#ifndef PIVISUALISATOR_MAINWINDOW_HPP
#define PIVISUALISATOR_MAINWINDOW_HPP


#include <QtWidgets/QMainWindow>
#include "ImageData.hpp"
#include "ImageLabel.hpp"

class QLabel;
class QTimer;

class MainWindow : public QMainWindow {
public:

public:
    MainWindow();

private:
    ImageLabel* mImageLabel;
    ImageData mCurrentImage;

    void displayGreetings();
    void newInput(int newValue);

    Q_SLOTS
};


#endif //PIVISUALISATOR_MAINWINDOW_HPP

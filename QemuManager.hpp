//
// Created by dawid on 8/31/17.
//

#ifndef PIVISUALISATOR_QEMUMANAGER_HPP
#define PIVISUALISATOR_QEMUMANAGER_HPP


#include <QtCore/QObject>
#include "ImageData.hpp"

class QemuManager : public QObject{
    Q_OBJECT
public:
    void start();
    void writeNewValue(int32_t newValue);

Q_SIGNALS:
    //rvalue references not yet available. deal with it.
    void newDataArrived(ImageData newData);

};


#endif //PIVISUALISATOR_QEMUMANAGER_HPP

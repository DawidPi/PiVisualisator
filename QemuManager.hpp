//
// Created by dawid on 8/31/17.
//

#ifndef PIVISUALISATOR_QEMUMANAGER_HPP
#define PIVISUALISATOR_QEMUMANAGER_HPP


#include <QtCore/QObject>
#include "ImageData.hpp"

class QProcess;

class QemuManager : public QObject{
    Q_OBJECT
public:
    using QObject::QObject;

    void start();
    void writeNewValue(int32_t newValue);
    ~QemuManager();

private:
    QByteArray mReadOutput;
    QProcess* mQemuProcess;

private Q_SLOTS:
    void dataRedyToRead();
    void started();

Q_SIGNALS:
    //rvalue references not yet available. deal with it.
    void newDataArrived(ImageData newData);
    void newInputValueAccepted(int);

};


#endif //PIVISUALISATOR_QEMUMANAGER_HPP

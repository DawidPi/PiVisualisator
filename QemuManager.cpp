//
// Created by dawid on 8/31/17.
//

#include <QtCore/QProcess>
#include <QtWidgets/QMessageBox>
#include "QemuManager.hpp"
#include <QMessageBox>
#include "Settings.hpp"
#include <QtCore/QDebug>
#include <QtCore/QThread>

void QemuManager::start(){
    qDebug() << "QemuManager::QemuManager(): creating qemu process";
    mQemuProcess = new QProcess(this);

    qDebug() << "QemuManager::QemuManager(): connect QProcess(readyReadStandardOutput), QemuManager(dataRedyToRead)";
    connect(mQemuProcess, &QProcess::readyReadStandardOutput, this, &QemuManager::dataRedyToRead);
    connect(mQemuProcess, &QProcess::started, this, &QemuManager::started);

    Settings settings;
    QStringList qemuArguments;
    qemuArguments << "-M" << "versatilepb" << "-kernel" << settings.getBinaryPath() << "-nographic";

    qDebug() << "QemuManager::QemuManager(): Qemu arguments: " << qemuArguments.join(' ');

    qDebug() << "QemuManager::QemuManager(): starting qemu process ";
    mQemuProcess->start(settings.getQemuPath(), qemuArguments);

    auto error = mQemuProcess->error();
    qDebug() << "QemuManager::QemuManager(): error: " << static_cast<int>(error);

}

void QemuManager::dataRedyToRead(){
    qDebug() << "QemuManager::dataRedyToRead()";
    QByteArray readOutput = mQemuProcess->readAllStandardOutput();
    mReadOutput.append(readOutput);

    qDebug() << "QemuManager::dataRedyToRead(): input buffer size: " << mReadOutput.size();
    qDebug() << "QemuManager::dataRedyToRead(): IMAGE_SIZE_BYTES: " << ImageData::IMAGE_SIZE_BYTES;
    qDebug() << "QemuManager::dataRedyToRead(): " << readOutput;

    if(mReadOutput.size() >= ImageData::IMAGE_SIZE_BYTES){
        qDebug() << "new Image available!";
        ImageData imgData;
        imgData.initFromData(mReadOutput.data());
        QByteArray restBytes(mReadOutput.data()+ImageData::IMAGE_SIZE_BYTES, mReadOutput.size() - ImageData::IMAGE_SIZE_BYTES);
        mReadOutput = restBytes;
        Q_EMIT newDataArrived(imgData);
    }
}

void QemuManager::writeNewValue(int32_t newValue) {
    QString newValueString = QString::number(newValue);
    newValueString += "\n";
    qDebug() << "QemuManager::writeNewValue() : value: " << newValueString;
    mQemuProcess->write(newValueString.toLocal8Bit());
    auto succeed = mQemuProcess->waitForBytesWritten();
    if(succeed){
        qDebug() << "QemuManager::writeNewValue() : value sent ";
        Q_EMIT newInputValueAccepted(newValue);
    } else{
        qDebug() << "QemuManager::writeNewValue() : value not sent ";
        QMessageBox messageBox("PiOS Visualiser",
                               "Could not send value to qemu",
                               QMessageBox::Warning,
                               QMessageBox::NoButton,
                               QMessageBox::NoButton,
                               QMessageBox::Ok);
        messageBox.exec();
    }
}

void QemuManager::started() {
    qDebug() << "QemuManager::started() : process started";
}

QemuManager::~QemuManager() {
    mQemuProcess->kill();
    mQemuProcess->waitForFinished();
}

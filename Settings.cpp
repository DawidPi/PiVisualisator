//
// Created by dawid on 9/1/17.
//

#include "Settings.hpp"
#include <QFile>
#include <cassert>
#include <QStringList>
#include <QString>

Settings::Settings(){
    QFile file("config.txt");
    if(file.exists()){
        file.open(QIODevice::ReadOnly);
        for(unsigned int currentLine=0; currentLine<2; ++currentLine){
            QString line = file.readLine();
            QStringList keyValue = line.split("=");
            assert(keyValue.size() == 2);
            if(keyValue[0] == "qemu_path"){
                mQemuPath = keyValue[1].trimmed();
            } else if (keyValue[0] == "binary_path"){
                mBinaryPath = keyValue[1].trimmed();
            }
        }
    }

    if(mQemuPath.isEmpty()){
        mQemuPath = "qemu-system-arm";
    }

    if(mBinaryPath.isEmpty()){
        mBinaryPath = "AutomaticsControlExample.bin";
    }

}

QString Settings::getQemuPath() {
    return mQemuPath;
}

QString Settings::getBinaryPath() {
    return mBinaryPath;
}

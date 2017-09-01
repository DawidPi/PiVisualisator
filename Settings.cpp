//
// Created by dawid on 9/1/17.
//

#include "Settings.hpp"

QString Settings::getQemuPath() {
    return QString("qemu-system-arm");
}

QString Settings::getBinaryPath() {
    return QString("AutomaticsControlExample.bin");
}

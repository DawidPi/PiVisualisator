//
// Created by dawid on 9/1/17.
//

#ifndef PIVISUALISATOR_SETTINGS_HPP
#define PIVISUALISATOR_SETTINGS_HPP


#include <QtCore/QString>

class Settings {
public:
    Settings();
    QString getQemuPath();
    QString getBinaryPath();

private:
    QString mQemuPath;
    QString mBinaryPath;
};


#endif //PIVISUALISATOR_SETTINGS_HPP

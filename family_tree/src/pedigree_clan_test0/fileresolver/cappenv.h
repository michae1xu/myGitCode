#ifndef CAPPENV_H
#define CAPPENV_H

#include <QString>
#include <QDir>



class CAppEnv
{
    CAppEnv() = default;
    ~CAppEnv() = default;

    CAppEnv(const CAppEnv &) = delete;
    CAppEnv& operator = (const CAppEnv &) = delete;

public:
    static QString getAppName();
    static QString getAppFilePath();
    static QDir getAppDir();
    static QString getAppDirPath();
    static QString getRPUDesignerDirPath();
    static QString stpToNm(const QString &fullFileName);
    static QString getImageDirPath();
};

#endif // CAPPENV_H

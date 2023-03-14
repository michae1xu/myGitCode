#include "cappenv.h"
#include <QApplication>
#include <QDir>

QString CAppEnv::getAppName()
{
    return qApp->applicationName();
}

QString CAppEnv::getAppFilePath()
{
    return qApp->applicationFilePath();
}

QDir CAppEnv::getAppDir()
{
    QDir dir(qApp->applicationDirPath());
    dir.cdUp();
    return dir;
}

QString CAppEnv::getAppDirPath()
{
    return getAppDir().absolutePath();
}

QString CAppEnv::getRPUDesignerDirPath()
{
#if defined(Q_OS_WIN)
    return QDir::homePath() + "/Documents/" + qApp->applicationName();
#elif defined(Q_OS_UNIX)
    return QDir::homePath() + "/Documents/" + qApp->applicationName();
#endif
}

QString CAppEnv::stpToNm(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

QString CAppEnv::getImageDirPath()
{
    return getAppDirPath() + "/image";
}

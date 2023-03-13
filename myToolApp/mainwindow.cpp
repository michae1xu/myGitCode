#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString curDirName = QFileDialog::getExistingDirectory();

    QDir dir(curDirName);
    if(!dir.exists())
    {
        QMessageBox::critical(this,tr("错误"),tr("文件夹找不到"));
        return;
    }

    QStringList fileNames = dir.entryList(QDir::AllEntries);

    int iCount = 0;
    for (QString file : fileNames) {
        if(file.contains("exe",Qt::CaseSensitive))
        {
            QString comFileOldName = curDirName+"\\"+file;
            QFile newfile(comFileOldName);
            QString comFileNewName = curDirName+"\\"+file.left(file.length()-8)+".lnk";
            bool ok = newfile.rename(comFileNewName);
            if(!ok)
                QMessageBox::critical(this,tr("错误"),tr("文件夹找不到"));
            else
                iCount++;
        }
    }
    QString strLog = "替换成功："+QString::number(iCount)+"个文件名！";
    QMessageBox::critical(this,strLog,tr("ok"));
    return;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <ClanGraphEdit/clangraphview.h>
#include <ClanGraphEdit/ClanGraphDef.h>
#include <fileresolver/cappenv.h>

#include <QListWidgetItem>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initXmlEditorElement();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initXmlEditorElement()
{
    QStringList elementList;
    elementList << "PEOPLE" << "LINE";
    int i = 0;
    for(; i < elementList.size(); i++)
    {
        QString str = elementList.at(i);
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_element);
        item->setData(Qt::UserRole, i + Normal);
        item->setText(str);
        item->setToolTip(str);
        switch (i) {
        case 0:
            item->setIcon(QIcon(CAppEnv::getImageDirPath() + "/operator/mouse.png"));
            break;
        case 1:
            item->setIcon(QIcon(CAppEnv::getImageDirPath() + "/operator/line.png"));
            break;
        }
        item->setSizeHint(iconSize() * 2);
    }

    ui->listWidget_element->setIconSize(iconSize()*3);
}

void MainWindow::on_action_About_triggered()
{
    QMessageBox::about(this,tr("xuf first demo"),tr("a"));
}

void MainWindow::on_action_newFile_triggered()
{
    m_curClanGraphView = new ClanGraphView(this);
    m_curClanGraphView->newFile();
}

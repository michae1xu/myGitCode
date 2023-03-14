#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "helpform.h"

class ClanGraphView;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    ClanGraphView *m_curClanGraphView = nullptr;

    void initXmlEditorElement();
private slots:
    void on_action_About_triggered();
    void on_action_newFile_triggered();
};

#endif // MAINWINDOW_H

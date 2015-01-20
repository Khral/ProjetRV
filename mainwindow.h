#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include "ui_mainwindow.h"
#include "fonctionOSG.h"
#include "ViewerWidget.h"

#define SHP 0
#define SLD 1

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void browseSLD();
    void browseSHP();
    void jouerScene();
    void stopperScene();

private:
    void browse(int mode);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

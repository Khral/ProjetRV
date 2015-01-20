#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_pathSHP, SIGNAL(clicked()), SLOT(browseSHP()));
    connect(ui->pushButton_pathSLD, SIGNAL(clicked()), SLOT(browseSLD()));
    connect(ui->pushButton_generer, SIGNAL(clicked()), SLOT(jouerScene()));
    connect(ui->pushButton_stopSimu, SIGNAL(clicked()), SLOT(stopperScene()));
}

void MainWindow::jouerScene()
{
    if(ui->layout_scene->count()<1)
    {
        //osg::ArgumentParser arguments(&argc, argv);

    #if QT_VERSION >= 0x050000
        // Qt5 is currently crashing and reporting "Cannot make QOpenGLContext current in a different thread" when the viewer is run multi-threaded, this is regression from Qt4
        osgViewer::ViewerBase::ThreadingModel threadingModel = osgViewer::ViewerBase::SingleThreaded;
    #else
        osgViewer::ViewerBase::ThreadingModel threadingModel = osgViewer::ViewerBase::CullDrawThreadPerContext;
    #endif

        /*while (arguments.read("--SingleThreaded")) threadingModel = osgViewer::ViewerBase::SingleThreaded;
        while (arguments.read("--CullDrawThreadPerContext")) threadingModel = osgViewer::ViewerBase::CullDrawThreadPerContext;
        while (arguments.read("--DrawThreadPerContext")) threadingModel = osgViewer::ViewerBase::DrawThreadPerContext;
        while (arguments.read("--CullThreadPerCameraDrawThreadPerContext")) threadingModel = osgViewer::ViewerBase::CullThreadPerCameraDrawThreadPerContext;*/

        ViewerWidget* viewWidget = new ViewerWidget(threadingModel, ui);
        viewWidget->setGeometry( 100, 100, 800, 600 );

        ui->layout_scene->addWidget(viewWidget);
    }
    else
    {
        stopperScene();
        jouerScene();
    }
}

void MainWindow::stopperScene()
{
    if(ui->layout_scene->count()>0)
        delete ui->layout_scene->itemAt(0)->widget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::browseSHP()
{
    browse(SHP);
}

void MainWindow::browseSLD()
{
    browse(SLD);
}

void MainWindow::browse(int mode)
{
    QString directory = QFileDialog::getOpenFileName(this,tr("Choisir un fichier"), QDir::currentPath());
    if (!directory.isEmpty()) {
        switch(mode){
            case SHP:
                ui->label_pathSHP->setText(directory);
                break;
            case SLD:
                ui->label_pathSLD->setText(directory);
                break;
        }
    }
}

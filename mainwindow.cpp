#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ding = new Ding(this, 180);

    connect(ding, SIGNAL(onPlay(int)), ui->progressBar, SLOT(setMaximum(int)));
    connect(ding, SIGNAL(elapsedTimeChanged(int)), ui->progressBar, SLOT(setValue(int)));

    connect(ui->pushButtonPlay, SIGNAL(clicked()), ding, SLOT(play()));
    connect(ui->pushButtonStop, SIGNAL(clicked()), ding, SLOT(stop()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ding;
}

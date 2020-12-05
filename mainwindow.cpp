#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&game, &Game::signal, this, &MainWindow::setButton);//коннектор функций класса Game для изменения ui окна MainWindow
    game.CreateButton(game.n_s,game.m_s);//создание поля

    this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);//запрет на изменение размера окна
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setButton(QWidget *qwidget,int x, int y)
{
    ui->gridLayout->addWidget(qwidget, x,y);
}

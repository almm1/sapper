#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Game *game=new Game(5);
    Game *game=new Game;
    connect(game, &Game::signal, this, &MainWindow::setButton);
    game->CreateButton(game->n_s,game->m_s);
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

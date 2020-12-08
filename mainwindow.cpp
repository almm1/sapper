#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(int n, int m, int b, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&game, &Game::signalCreate, this, &MainWindow::setButton);//коннектор функций класса Game для изменения ui окна MainWindow
    connect(&game, &Game::signalLabel, this, &MainWindow::setLabel);
    connect(&game, &Game::exit, this, &MainWindow::close);
    game.setM(m);
    game.setN(n);
    game.setBomb(b);
    game.CreateButton();//создание поля

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

void MainWindow::setLabel(int n)
{
    ui->label->setText(QString::number(n));
}

void MainWindow::on_pushButton_clicked()
{
    game.restart();
}

void MainWindow::close()
{
    showMenu();
}

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
    connect(&game, &Game::stopSignal, this, &MainWindow::stop);
    connect(&game, &Game::resetSignal, this, &MainWindow::reset);
    game.setM(m);
    game.setN(n);
    game.setBomb(b);
    game.CreateButton();//создание поля

    timer = new QTimer();
    timer->setInterval(1000);

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

void MainWindow::setTime(QTime t, int f)
{
    cnt=f;
    time=t;
    time_2=t;
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    timer->start();
}

void MainWindow::on_pushButton_clicked()
{
    game.restart();
}

void MainWindow::updateTime()
{
    ui->label_2->setText(time.toString("mm:ss"));
    time=time.addSecs(cnt);
    if(time==QTime(0,0,0))
        game.gameLose(1);
}
void MainWindow::reset()
{
    time=time_2;
    timer->start();
}
void MainWindow::stop()
{
    timer->stop();
}

void MainWindow::close()
{
    showMenu();
}

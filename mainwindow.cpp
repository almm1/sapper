#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdynamicbutton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CreateButton(qdynamicbutton.getN(), qdynamicbutton.getM());//создание кнопок(карты)
    this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);//запрет на изменение размера окна
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::CreateButton(int N, int M)
{
    for (int i = 0; i<N; i++)
    {
        for (int j = 0; j<M; j++)
        {
            QDynamicButton *button = new QDynamicButton(this);  // Создаем объект динамической кнопки
            ui->gridLayout->addWidget(button, i,j);
            button->setX(i);
            button->setY(j);
            //подключение сигнала
            connect(button, &QMyPushButton::clicked, this, &MainWindow::slotGetButton);//для левой кнопки мыши
            //connect(button, &QMyPushButton::rClicked, this, &MainWindow::slotRclick);//для правой кнопки мыши
        }
    }
}

void MainWindow::slotGetButton()
{
    /* Определяем объект, который вызвал сигнал
     * */
    int x,y;
    QDynamicButton *button = (QDynamicButton*) sender();
    x=button->getX();
    y=button->getY();
    ui->label_2->setText(QString::number(x)+ ":"+ QString::number(y));
}

void MainWindow::slotRclick()
{
    QDynamicButton *button = (QDynamicButton*) sender();
    button->setIcon(QIcon("/image/flag"));
}

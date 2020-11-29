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
            /* Подключаем сигнал нажатия кнопки к СЛОТ получения номера кнопки
             * */
            connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
        }
    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdynamicbutton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CreateButton(qdynamicbutton.getN(), qdynamicbutton.getM());//создание кнопок(карты)
    createBomb(qdynamicbutton.getN(), qdynamicbutton.getM(), qdynamicbutton.getBomb());

    this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);//запрет на изменение размера окна
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateButton(int N, int M)
{
    button = new QDynamicButton* [N];
      for (int i = 0; i<N; i++)
        button[i]=new QDynamicButton[M];

    for (int i = 0; i<N; i++)
    {
        for (int j = 0; j<M; j++)
        {
           // QDynamicButton *button = new QDynamicButton;  // Создаем объект динамической кнопки
            ui->gridLayout->addWidget(&button[i][j], i,j);
            button[i][j].setX(i);
            button[i][j].setY(j);
            //подключение сигнала
            connect(&button[i][j], &QMyPushButton::lClicked, this, &MainWindow::slotGetButton);//для левой кнопки мыши
            connect(&button[i][j], &QMyPushButton::rClicked, this, &MainWindow::slotRclick);//для правой кнопки мыши
        }
    }
}

void MainWindow::slotGetButton()
{
    /* Определяем объект, который вызвал сигнал
     * */
    int x,y;
    QDynamicButton *but = (QDynamicButton*) sender();
    x=but->getX();
    y=but->getY();
    ui->label_2->setText(QString::number(x)+ ":"+ QString::number(y));
    but->hide();
}

void MainWindow::slotRclick()
{
    QDynamicButton *but = (QDynamicButton*) sender();
    QIcon icon;
    icon.addFile(QString(":/image/flag.ico"), QSize(20, 20), QIcon::Normal, QIcon::Off);
    but->setIcon(icon);
}

bool checkValue(int *arr, int size, int value)//функция проверки повторяющихся значений
{
   for(int i = 0; i < size; i++)
   {
     if(arr[i] == value)
        return false;
   }
   return true;
}

void MainWindow::createBomb(int N, int M, int bomb)
{
    qsrand(QTime::currentTime().msecsSinceStartOfDay());//рандом

    QIcon icon;
    icon.addFile(QString(":/image/bomb.ico"), QSize(20, 20), QIcon::Normal, QIcon::Off);

    int *b= new int [bomb];
    int random;

    for(int k = 0; k < bomb; k++)
    {
       do
       {
        random = (qrand() % (N*M + 1));
       } while(checkValue(b, k, random) == false);
      b[k] = random;
    }

    for (int i =0; i < bomb; i++)
    {
        button[b[i]/10][b[i]%10].setIcon(icon);
    }
}

#include "game.h"

Game::Game()
{
    pressLeftCnt = 0;
    n_s=map.getN();
    m_s=map.getM();
}


void Game::CreateButton(int N, int M)
{
    button = new Cell* [N];
      for (int i = 0; i<N; i++)
        button[i]=new Cell[M];

    for (int i = 0; i<N; i++)
    {
        for (int j = 0; j<M; j++)
        {
           // this->setButton(&button[i][j],i,j);
            //ui->gridLayout->addWidget(&button[i][j], i,j);
            signal(&button[i][j], i,j);
            button[i][j].setX(i);
            button[i][j].setY(j);
            //подключение сигнала
            connect(&button[i][j], &QMyPushButton::lClicked, this, &Game::slotGetButton);//для левой кнопки мыши
            connect(&button[i][j], &QMyPushButton::rClicked, this, &Game::slotRclick);//для правой кнопки мыши
        }
    }
}

void Game::slotGetButton()
{
    /* Определяем объект, который вызвал сигнал
     * */
    int x,y;
    Cell *but = (Cell*) sender();

    x=but->getX();
    y=but->getY();

    if (pressLeftCnt == 0)
    {
        pressLeftCnt++;
        createBomb(map.getN(), map.getM(), map.getBomb(), x, y);
        clearZone(x, y, map.getN(), map.getM());
    }
    else{ clearZone(x, y, map.getN(), map.getM());}
     //ui->label_2->setText(QString::number(x)+ ":"+ QString::number(y));
     //ui->label->setText(QString::number(x*map.getM()+y));
}

void Game::slotRclick()
{
    Cell *but = (Cell*) sender();
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

void Game::createBomb(int N, int M, int bomb, int x, int y)
{
    qsrand(QTime::currentTime().msecsSinceStartOfDay());//рандом

    int current=x*M+y;//выбранная точка(точка на которую нажали первой)
    int *b= new int [bomb];//массив с id метками нахождения бомб
    int random;

    for(int k = 0; k < bomb; k++)
    {
       do {
            do {
            random = (qrand() % (N*M));
            }while(random == current);//проверка чтобы бомба не попала в выброную точку
       } while(checkValue(b, k, random) == false);//проверка на повторение
      b[k] = random;
    }
    QIcon icon;
    icon.addFile(QString(":/image/bomb.ico"), QSize(30, 30), QIcon::Normal, QIcon::Off);
    for (int i =0; i < bomb; i++)
    {
        button[b[i]/M][b[i]%M].status = map.BOMB;

        button[b[i]/M][b[i]%M].setIcon(icon);
       // button[b[i]/M][b[i]%M].setEnabled(false);
    }


    for (int i = 0; i<N; i++)
    {
        for (int j =0; j<M; j++)
        {
            if (button[i][j].status!=map.BOMB)
           {
                if ((button[i][j].bombAround=searchBomb(i,j,N,M))==0)
             {
                    button[i][j].status=map.HOLE;
                    setImageNumber(i,j,button[i][j].bombAround);
              }
                else
                {
                    button[i][j].status=map.NUMB;
                    setImageNumber(i,j,button[i][j].bombAround);
                }
            }
        }
    }
}

int Game::searchBomb(int x, int y, int N, int M)
{
    int cntBomb=0;

    if (x==0)
    {
        if (y==0)
        {
            for (int i = 0; i<2; i++)
            {
                for (int j = 0; j<2; j++)
                {
                    if(button[x+i][y+j].status==map.BOMB)
                        cntBomb++;
                }
            }
        }
        else if (y == M-1)
        {
            for (int i = 0; i<2; i++)
            {
                for (int j = 0; j<1; j++)
                {
                    if(button[x+i][y+j].status==map.BOMB)
                        cntBomb++;
                }
            }
        }
        else
        {
            for (int i = 0; i<2; i++)
            {
                for (int j = -1; j<2; j++)
                {
                    if(button[x+i][y+j].status==map.BOMB)
                        cntBomb++;
                }
            }
        }
    }
    else if (x==N-1)
    {
        if (y==0)
        {
            for (int i = -1; i<1; i++)
            {
                for (int j = 0; j<2; j++)
                {
                    if(button[x+i][y+j].status==map.BOMB)
                        cntBomb++;
                }
            }
        }
        else if (y == M-1)
        {
            for (int i = -1; i<1; i++)
            {
                for (int j = 0; j<1; j++)
                {
                    if(button[x+i][y+j].status==map.BOMB)
                        cntBomb++;
                }
            }
        }
        else {
            for (int i = -1; i<1; i++)
            {
                for (int j = -1; j<2; j++)
                {
                    if(button[x+i][y+j].status==map.BOMB)
                        cntBomb++;
                }
            }
        }

    }

    else if (y==0 and x != N-1)
    {
        for (int i = -1; i<2; i++)
        {
            for (int j = 0; j<2; j++)
            {
                if(button[x+i][y+j].status==map.BOMB)
                    cntBomb++;
            }
        }
    }
    else if (y==M-1)
    {
        for (int i = -1; i<2; i++)
        {
            for (int j = -1; j<1; j++)
            {
                if(button[x+i][y+j].status==map.BOMB)
                    cntBomb++;
            }
        }
    }

    else
    {
        for (int i = -1; i<2; i++)
        {
            for (int j = -1; j<2; j++)
            {
                if(button[x+i][y+j].status==map.BOMB)
                    cntBomb++;
            }
        }
    }
    return cntBomb;
}

void Game::setImageNumber(int x, int y, int num)
{
    QIcon icon;
    icon.addFile(QString(":/image/"+QString::number(num)+".ico"), QSize(30, 30), QIcon::Normal, QIcon::Off);
    button[x][y].setIcon(icon);
    button[x][y].setStyleSheet("QPushButton { border:solid; background: #DCDCDC}");
  //  button[x][y].setEnabled(false);
}

void Game::clearZone(int x, int y, int N, int M)
{
   int cntBomb=searchBomb(x,y,N,M);

}

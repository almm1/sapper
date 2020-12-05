#include "game.h"

Game::Game()
{
    pressLeftCnt = 0;
    n_s=map.getN();
    m_s=map.getM();
}


void Game::CreateButton()
{
    button = new Cell* [n_s];
      for (int i = 0; i<n_s; i++)
        button[i]=new Cell[m_s];

    for (int i = 0; i<n_s; i++)
    {
        for (int j = 0; j<m_s; j++)
        {
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
        createBomb(map.getBomb(), x, y);
        clearZone(x, y);
    }
    else{ clearZone(x, y);}
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

void Game::createBomb(int bomb, int x, int y)
{
    qsrand(QTime::currentTime().msecsSinceStartOfDay());//рандом

    int current=x*m_s+y;//выбранная точка(точка на которую нажали первой)
    int *b= new int [bomb];//массив с id метками нахождения бомб
    int random;

    for(int k = 0; k < bomb; k++)
    {
       do {
            do {
            random = (qrand() % (n_s*m_s));
            }while(random == current);//проверка чтобы бомба не попала в выброную точку
       } while(checkValue(b, k, random) == false);//проверка на повторение
      b[k] = random;
    }
    QIcon icon;
    icon.addFile(QString(":/image/bomb.ico"), QSize(30, 30), QIcon::Normal, QIcon::Off);
    for (int i =0; i < bomb; i++)
    {
        button[b[i]/m_s][b[i]%m_s].status = map.BOMB;

        button[b[i]/m_s][b[i]%m_s].setIcon(icon);
       // button[b[i]/m_s][b[i]%m_s].setEnabled(false);
    }


    for (int i = 0; i<n_s; i++)
    {
        for (int j =0; j<m_s; j++)
        {
            if (button[i][j].status!=map.BOMB)
           {
                if ((button[i][j].bombAround=searchBomb(i,j))==0)
             {
                    button[i][j].status=map.HOLE;
                  //  setImageNumber(i,j,button[i][j].bombAround);
              }
                else
                {
                    button[i][j].status=map.NUMB;
                 //   setImageNumber(i,j,button[i][j].bombAround);
                }
            }
        }
    }
}

int Game::searchBomb(int x, int y)
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
        else if (y == m_s-1)
        {
            for (int i = 0; i<2; i++)
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
    else if (x==n_s-1)
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
        else if (y == m_s-1)
        {
            for (int i = -1; i<1; i++)
            {
                for (int j = -1; j<1; j++)
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

    else if (y==0 and x != n_s-1)
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
    else if (y==m_s-1)
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
    button[x][y].setStyleSheet("QPushButton { border:solid; background: #f2f0f2}");
  //  button[x][y].setEnabled(false);
}

void Game::clearZone(int x, int y)
{
    if(x>=0 && x<n_s && y >=0 && y<=m_s)
    {
       if (button[x][y].status==map.NUMB)
             setImageNumber(x,y,button[x][y].bombAround);
      else if(button[x][y].status==map.HOLE)
       {
           button[x][y].status=map.NUMB;
          setImageNumber(x,y,button[x][y].bombAround);
          clearZone(x+1,y);
          clearZone(x-1,y);
          clearZone(x,y+1);
          clearZone(x,y-1);
          clearZone(x-1,y-1);
          clearZone(x+1,y+1);
          clearZone(x+1,y-1);
          clearZone(x-1,y+1);
        }
    }
}

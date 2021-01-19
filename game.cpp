#include "game.h"

Game::Game()
{

}

Game::~Game()
{
    for (int i = 0; i < N; i++)
         delete[] button[i];
     delete[] button;
}

void Game::CreateButton()
{
    bombLeft=bomb;

    button = new Cell* [N];
      for (int i = 0; i<N; i++)
        button[i]=new Cell[M];

      signalLabel(bomb);
    for (int i = 0; i<N; i++)
    {
        for (int j = 0; j<M; j++)
        {
            signalCreate(&button[i][j], i,j);
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
        createBomb(bomb, x, y);
        clearZone(x, y);
    }
    else
    {
        if (but->status==BOMB && but->isFlag==false)
        {
            gameLose(0, x , y);
        }
        else clearZone(x, y);
        if (checkWin()==1)
            gameWin();
    }
}

void Game::slotRclick()
{
   Cell *but = (Cell*) sender();
    QIcon icon;
    if(but->isOpen==false)
    {
        if (but->isFlag==false && bombLeft>0)
        {
            icon.addFile(QString(":/image/flag.ico"), QSize(20, 20), QIcon::Normal, QIcon::Off);
            but->setIcon(icon);
            but->isFlag=true;

            bombLeft--;
            signalLabel(bombLeft);

            if (checkWin()==1)
                gameWin();
        }
        else if (but->isFlag==true)
        {
            icon.addFile(QString(""), QSize(0, 0), QIcon::Normal, QIcon::Off);
            but->setIcon(icon);
            but->isFlag=false;

            bombLeft++;
            if (bombLeft>bomb)
                bombLeft=bomb;
            signalLabel(bombLeft);
        }
    }
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
        button[b[i]/M][b[i]%M].status = BOMB;

      //  button[b[i]/M][b[i]%M].setIcon(icon);
       // button[b[i]/M][b[i]%M].setEnabled(false);
    }

    for (int i = 0; i<N; i++)
    {
        for (int j =0; j<M; j++)
        {
            if (button[i][j].status!=BOMB)
           {
                if ((button[i][j].bombAround=searchBomb(i,j))==0)
             {
                    button[i][j].status=HOLE;
                  //  setImageNumber(i,j,button[i][j].bombAround);
              }
                else
                {
                    button[i][j].status=NUMB;
                 //   setImageNumber(i,j,button[i][j].bombAround);
                }
            }
        }
    }
    delete[]  b;
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
                    if(button[x+i][y+j].status==BOMB)
                        cntBomb++;
                }
            }
        }
        else if (y == M-1)
        {
            for (int i = 0; i<2; i++)
            {
                for (int j = -1; j<1; j++)
                {
                    if(button[x+i][y+j].status==BOMB)
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
                    if(button[x+i][y+j].status==BOMB)
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
                    if(button[x+i][y+j].status==BOMB)
                        cntBomb++;
                }
            }
        }
        else if (y == M-1)
        {
            for (int i = -1; i<1; i++)
            {
                for (int j = -1; j<1; j++)
                {
                    if(button[x+i][y+j].status==BOMB)
                        cntBomb++;
                }
            }
        }
        else {
            for (int i = -1; i<1; i++)
            {
                for (int j = -1; j<2; j++)
                {
                    if(button[x+i][y+j].status==BOMB)
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
                if(button[x+i][y+j].status==BOMB)
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
                if(button[x+i][y+j].status==BOMB)
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
                if(button[x+i][y+j].status==BOMB)
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
}

void Game::clearZone(int x, int y)
{
    if(x>=0 && x<N && y >=0 && y<=M)
    {
        if (button[x][y].status!=BOMB)
        {
           if (button[x][y].status==NUMB  && button[x][y].isFlag!=true)
           {
               button[x][y].isOpen=true;
               setImageNumber(x,y,button[x][y].bombAround);
           }
          else if(button[x][y].status==HOLE && button[x][y].isFlag!=true)
           {
              button[x][y].isOpen=true;
              button[x][y].status=NUMB;
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
}

void Game:: gameLose(int mode, int x, int y)
{
    stopSignal();
    button[x][y].setStyleSheet("QPushButton { background: red}");

    QIcon icon;
    QIcon icon2;

    icon.addFile(QString(":/image/logo.ico"));

    QMessageBox box;
    box.setWindowTitle("");
    if (mode == 0)
    box.setText("Вы проиграли:(");
    if (mode == 1)
    box.setText("Вы проиграли:(, Время вышло.");
    box.setWindowIcon(icon);
    QPushButton *rep = box.addButton(tr("Заново"), QMessageBox::ActionRole);
    QPushButton *Output = box.addButton(tr("Выйти"), QMessageBox::ActionRole);
    box.setDefaultButton(Output);

    icon2.addFile(QString(":/image/cross.ico"), QSize(30, 30), QIcon::Normal, QIcon::Off);
    icon.addFile(QString(":/image/bomb.ico"), QSize(30, 30), QIcon::Normal, QIcon::Off);
    for (int i = 0; i<N; i++)
       for (int j = 0; j<M; j++)
            {
           button[i][j].setEnabled(false);
           if (button[i][j].status==BOMB && button[i][j].isFlag!=true)
              {
                    button[i][j].setIcon(icon);
              }
           else if(button[i][j].status!=BOMB && button[i][j].isFlag==true)
               button[i][j].setIcon(icon2);
        }

        box.exec();

        if(box.clickedButton()== rep)
        {
               restart();
        }
        else if(box.clickedButton()== Output)
        {
                exit();
        }
}
int Game::checkWin()
{
    int cnt=0;
    int cnt2=0;
    for (int i = 0; i<N; i++)
       for (int j = 0; j<M; j++)
            if (button[i][j].status==BOMB && button[i][j].isFlag==true)
               cnt++;
            else if (button[i][j].isOpen==true)
                cnt2++;

    if (cnt==bomb && cnt2==N*M - bomb)
        return 1;
    else
        return 0;
}

void Game::gameWin()
{
    stopSignal();
    QIcon icon;

    icon.addFile(QString(":/image/logo.ico"));

    QMessageBox box;
    box.setWindowTitle("");
    box.setText("Вы выиграли!!!");
    box.setWindowIcon(icon);
    QPushButton *rep = box.addButton(tr("Заново"), QMessageBox::ActionRole);
    QPushButton *Output = box.addButton(tr("Выйти"), QMessageBox::ActionRole);
    box.setDefaultButton(Output);

    box.exec();

    if(box.clickedButton()== rep)
    {
           restart();
    }
    else if(box.clickedButton()== Output)
    {
            exit();
    }
}

void Game::restart()
{
    resetSignal();
    for (int i = 0; i < N; i++)
         delete[] button[i];
     delete[] button;

    pressLeftCnt=0;
    bombLeft=bomb;
    CreateButton();
}

void Game::setBomb(int Bomb){bomb = Bomb;}

 int Game::getBomb(){return bomb;}

void Game::setN(int number){N = number;}

int Game::getN(){return N;}

void Game::setM(int number){M = number;}

int Game::getM(){return M;}

#ifndef MAP_H
#define MAP_H


class Map
{
public:
    Map();

    void setBomb(int Bomb);
    int getBomb();

    void setN(int number);
    int getN();

    void setM(int number);
    int getM();

    enum {BOMB, NUMB, HOLE};
private:
    int N = 0;
    int M = 0;
    int bomb = 0;
};

#endif // MAP_H

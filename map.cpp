#include "map.h"

Map::Map()
{
    setN(9);

    setM(9);

    setBomb(10);
}

void Map::setBomb(int Bomb){bomb = Bomb;}

int Map::getBomb(){return bomb;}

void Map::setN(int number){N = number;}

int Map::getN(){return N;}

void Map::setM(int number){M = number;}

int Map::getM(){return M;}
#include "objPos.h"

// Default constructor for objPos class, initializes x, y, and symbol to 0
objPos::objPos()
{
    x = 0;
    y = 0;
    symbol = 0; 
}

// Copy constructor
//copies values from another objPos object
objPos::objPos(objPos &o)
{
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}


objPos::objPos(int xPos, int yPos, char playerSymbol)
{
    x = xPos;
    y = yPos;
    symbol = playerSymbol;
}

void objPos::setObjPos(objPos o)
{
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char playerSymbol)
{
    x = xPos;
    y = yPos;
    symbol = playerSymbol;
}

void objPos::getObjPos(objPos &returnPos)
{
    returnPos.setObjPos(x, y, symbol);
}

char objPos::getSymbol()
{
    return symbol;
}

// Check if the position of the object is equal to a reference objPos object
bool objPos::isPosEqual(const objPos* refPos)
{
    return (refPos->x == x && refPos->y == y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos)
{
    if(isPosEqual(refPos))
        return getSymbol(); // Get the symbol of the object
    else
        return 0;
}
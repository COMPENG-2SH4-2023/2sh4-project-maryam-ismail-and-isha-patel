#include "Food.h"


Food::Food(GameMechs& gm) : gameMechs(gm)
{
    i = 0;   
    n = 0;
    foodSymbol = 'o';   //food symbol
}

void Food::generateFood(objPosArrayList &blockOff)
{
    int randomX;   //Random number of x and y position
    int randomY;

    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(NULL))); 

    while(true){
        randomX = (rand() % (gameMechs.getBoardSizeX() - 2)) + 2; //generate a random number starting at 2 because border is set to 1
        randomY = (rand() % (gameMechs.getBoardSizeY() - 2)) + 2; //generate random number for y pos

        int overlap = false; //no overlap
        objPos tempBlock;
        //iterates through blocked lsit (positions where player cant be generted)
        for (int i = 0; i < blockOff.getSize(); i++)    //check if generated position is in list
        {
            blockOff.getElement(tempBlock,i);   
            if (randomX == (tempBlock.x && randomY == tempBlock.y)) //if random x and y match blocked position
            {
                overlap = true; //overlap set to true
                break;
            }
        }
        if (!overlap)
            break;

    }

    //if no overlap, sets random x,y and symbol to foodpos
    foodPos.x = randomX;
    foodPos.y = randomY;
    foodPos.symbol = foodSymbol;
}

//returns position and symbol of food generated
void Food::getFoodPos(objPos &returnPos)
{
    returnPos = foodPos; 
}
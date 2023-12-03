#include "GameMechs.h"
#include "MacUILib.h"

//Initializing Variables
GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;  //initialized to false
    loseFlag=false;
    score = 0;
    boardSizeX = 20;  //size of rows
    boardSizeY = 10;  //size of columns

}

GameMechs::GameMechs(int boardX, int boardY)
{
    //Initialize variables
    input = '\0';
    exitFlag = false;   
    loseFlag = false;
    score = 0;            //score set to 0
    boardSizeX = boardX;
    boardSizeY = boardY;

}


// Get the status of the exitFlag

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;

}

//Asynchronus input
char GameMechs::getInput()
{
    if(MacUILib_hasChar()){
        input = MacUILib_getChar();
    } 

    return input;

}

//Get the value of boardSizeX
int GameMechs::getBoardSizeX()
{
    return boardSizeX;

}

// Get the value of boardSizeY
int GameMechs::getBoardSizeY()
{

    return boardSizeY;

}


void GameMechs::setExitTrue()
{
    exitFlag = true;

}

// Set the value of input
void GameMechs::setInput(char this_input)
{
    input = this_input;

}

// Clear the input by setting it to null character
void GameMechs::clearInput()
{
    input ='\0';

}

void GameMechs::incrementScore() {
    score++;
}

int GameMechs::getScore() {
    return score;
}

bool GameMechs::getLoseFlagStatus() {
    return loseFlag;
}

void GameMechs::setLoseFlag() {
    loseFlag = true;
}
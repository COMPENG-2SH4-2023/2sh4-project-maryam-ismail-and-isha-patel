#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

//pointers to object
GameMechs * myGM;
Player*myPlayer;
Food* myFood;

//objPos myPos;

//Function declarations
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM -> getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(26, 13);

    //adds objects on the heap
    myFood = new Food(*myGM);
    myPlayer = new Player(myGM, myFood);

    //generate food position based on player's position
    objPosArrayList* body;
    objPos head;
    body = myPlayer->getPlayerPos();
    body->getHeadElement(head);
    myFood->generateFood(*body);
    


}

//user input
void GetInput(void)
{
    myGM->getInput();
   
}

void RunLogic(void)
{
    myPlayer->movePlayer();
    myPlayer -> updatePlayerDir();
    myGM->clearInput();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); //clear previous frame

    objPosArrayList *playerBody = myPlayer->getPlayerPos(); //get current list
    objPos tempBody, tempFood;
    bool isObjFound;

    //title
    MacUILib_printf("-----------------Welcome to Snake!-------------------");




    myFood->getFoodPos(tempFood);
    MacUILib_printf("\n\n");

    //Display Game board
    for (int col = 1; col <= myGM->getBoardSizeY(); col++) {
        for (int row = 1; row <= myGM->getBoardSizeX(); row++) {
            isObjFound = false;
            if (col == 1 || col == (myGM->getBoardSizeY()) || row == 1 || row == (myGM->getBoardSizeX() )){
                MacUILib_printf("* ");
             } 
             //display food symbol at position
             else if (row == tempFood.x && col==tempFood.y) {
                MacUILib_printf("%c ", tempFood.symbol);    
            }
            
            else{
                //loop through the player's positon
                for (int m =0; m<playerBody ->getSize(); m++){
                    playerBody -> getElement(tempBody, m);
                    if(row == tempBody.x && col == tempBody.y){  //checks if current poition is equal to players body
                        MacUILib_printf("%c ", tempBody.symbol);
                        isObjFound = true;
                        break;
                    }
            
                }
                //if no object found put a space
                if (!isObjFound)
                MacUILib_printf("  ");
            }
        }

        MacUILib_printf("\n");
       
    }

    //Display Information
    MacUILib_printf("Your Score: %d\n", myGM->getScore());
    MacUILib_printf("Board size:%dx%d \nSnake Size: %d \n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), playerBody->getSize());
    playerBody->getHeadElement(tempBody);
    MacUILib_printf("Player Positions: <%d,%d>", tempBody.x, tempBody.y);
    MacUILib_printf("\nFood Position: <%d,%d>\n", tempFood.x, tempFood.y);
    MacUILib_printf("\nInstructions:\n1.Use WASD Keys to Navigate\n2.Catch the food to grow!\n3.If you collide with yourself, YOU LOOSE!");

    //Game over message (due to collision with body)
     if (myGM->getLoseFlagStatus())
    {
        MacUILib_printf("\nGame Over!\n");
        MacUILib_Delay(35000000);    //to allow player to see message
        myGM->setExitTrue();
    }

   
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  
    delete myGM;
    delete myFood;
    delete myPlayer; 
    MacUILib_uninit();
}
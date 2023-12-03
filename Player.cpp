#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* thisFood)
{
    mainGameMechsRef = thisGMRef;   // Set the reference to the GameMechs object
    foodRef = thisFood;             //reference for Food object
    myDir = STOP;                   // Initialize the player's direction to STOP

    // more actions to be included

    
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY()/2, '@');

    playerPosList = new objPosArrayList();
    playerPosList -> insertHead(tempPos);
}

//Destructor
Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

// reference to the player's position list
 objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
}

// Update the player's direction based on input
void Player::updatePlayerDir()
{
    // PPA3 input processing logic  

    //where do you get the input? how do you check for input)
    //not by calling get char!!
    //somewhere in part 1b
    //will be a method in game mech class that collectively checks input 
    //and stores the most recent input (FIND IT!)

    //How it lies within the game mech refrence inside the private
    
    //input from Game Mech object
    char input = mainGameMechsRef->getInput();
    if (input != 0){
        switch(input)
        {
                case ' ':  // exit
                mainGameMechsRef -> setExitTrue();
                break;

            // Add more key processing here

            //if character is pressed and is not in its opposite state , change the state so it moves in that direction
            case 'A':
            case 'a':

                if (myDir != RIGHT){  //As long as direction is not right, object is allowed to move left
                    myDir = LEFT;
                }
                break;

            case 'D':
            case 'd':
             
                if (myDir != LEFT){
                    myDir = RIGHT;
                }
                break;

            case 'W':
            case 'w':

                if (myDir != DOWN){
                    myDir = UP;
                }
                break;


            case 'S':
            case 's':

                if (myDir != UP){
                    myDir = DOWN;
                }
                break;

                default:
                break;
 
            }      
        }
        mainGameMechsRef -> clearInput(); //avoid double-processing
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    if (checkSelfCollision())
    {
        mainGameMechsRef->setLoseFlag(); 
    }

    objPos currentPos;
    playerPosList->getHeadElement(currentPos); //adds a character to the head of list if there is a collision

    //update position depending on direction
    switch (myDir){
        case LEFT:
            currentPos.x--;
            break;
        
        case RIGHT:
            currentPos.x++;
            break;
        
        case UP:
            currentPos.y--;
            break;

        case DOWN:
            currentPos.y++;
            break;
         case STOP:
             currentPos.x = 10;
             currentPos.y= 5 ;
             break;
 

    }

    // Wrap-around logic

    if (currentPos.x <= 1)  //if ti hits border
        currentPos.x = mainGameMechsRef->getBoardSizeX() - 1; //set to endposition
    else if (currentPos.x >= mainGameMechsRef->getBoardSizeX())
        currentPos.x = 1;

    if (currentPos.y <= 1)
        currentPos.y = mainGameMechsRef->getBoardSizeY() - 1;
    else if (currentPos.y >= mainGameMechsRef->getBoardSizeY())
        currentPos.y = 1;



    playerPosList->insertHead(currentPos);
    if (checkFoodConsumption())
    {
        foodRef->generateFood(*playerPosList);    //generate new food and add to score
        mainGameMechsRef->incrementScore();       //increase score by 1
    }
    else
    {
        playerPosList->removeTail(); //remove tail if no food is present
    }

}

//if the player has consumed food(collision)
bool Player::checkFoodConsumption() 
{
    objPos head, foodPos;
    playerPosList->getHeadElement(head); 
    foodRef->getFoodPos(foodPos);

    return head.isPosEqual(&foodPos);
}

//if the player collides with itself
bool Player::checkSelfCollision()
{
    objPos head,body;
    playerPosList->getHeadElement(head);
    for(int i = 1; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(body,i);
        if (head.isPosEqual(&body))        //checks the position of head matches a position on the body
        {
            return true;    
        }
    }
    return false;
}
#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {STOP, LEFT, RIGHT, UP, DOWN};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFood);
        ~Player();
        objPosArrayList* getPlayerPos();
        void getPlayerPos(objPos &returnPos); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();

        bool checkFoodConsumption();
        bool checkSelfCollision();
        

    private:
        objPosArrayList* playerPosList; 
        Food* foodRef; 
        //objPos playerPos;   // Upgrade this in iteration 3.       
        enum Dir myDir;
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif
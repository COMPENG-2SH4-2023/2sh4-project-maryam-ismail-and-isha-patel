#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    sizeArray = ARRAY_MAX_CAP;     // Set the initial maximum size for the array
    sizeList = 0;                 // Initialize the size of the list to 0

    //create space on heap for arraylist
    aList = new objPos[sizeArray];

}

objPosArrayList::~objPosArrayList()
{
    //deallocate space on heap
    delete[] aList;
    
}

// Insert a new objPos at the head of the array list
void objPosArrayList::insertHead(objPos thisPos)
{
    //check if max size of array is reached, if so increase it
    if (sizeList == sizeArray)
    {
        increaseArraySize();
    }

    //shift elements over one then insert thisPos as first element
    for(int i = sizeList; i > 0; i--)
    {
        aList[i].setObjPos(aList[i-1]);
    }
    aList[0].setObjPos(thisPos); 
    sizeList++; 

}

void objPosArrayList::insertTail(objPos thisPos)
{
    //check if max size of array is reached, if so increase it
    if (sizeList == sizeArray)
    {
        increaseArraySize();
    }

    sizeList++; //increase size of list
    aList[sizeList-1] = thisPos;    //add new object to end of list
}

void objPosArrayList::removeHead()
{
    //overwrite elements to the leftmost element
    for(int i = 0; i < sizeList - 1; i++)
    {
        aList[i] = aList[i+1];
    }
    sizeList--; //decrease size of list
}

void objPosArrayList::removeTail()
{
    sizeList--; //decrease list size to cut off tail
}

void objPosArrayList::increaseArraySize()
{
    //copy array to temp variable
    objPos temp[sizeArray];

    for(int i = 0; i < sizeArray; i++)
    {
        temp[i] = aList[i];
    }
    sizeArray += UNIT_SIZE;

    //deallocate memory associated with member variable then allocate new memory
    delete[] aList;
    aList = new objPos[sizeArray];

    //copy elements from temp back to list
    for(int i = 0; i < sizeArray; i++)
    {
        aList[i] = temp[i];
    }
}

// Get the size of the list
int objPosArrayList::getSize()
{
    //return size of LIST not entire array
    return sizeList;
} 

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos = aList[0]; //returns first element
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos = aList[sizeList - 1]; //returns last element in list
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    if(index < 0 || index > sizeList)   //check if index is invalid
    {
        returnPos = objPos(-1,-1,'\0');   //return invalid object
    }
    else
    {
        returnPos = aList[index];
    }
}
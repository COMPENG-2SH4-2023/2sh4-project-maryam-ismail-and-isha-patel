#include "objPosArrayList.h"
 
// Check lecture contents on general purpose array list construction,
// and modify it to support objPos array list construction.
 
objPosArrayList::objPosArrayList()
{
        // Array List Constructor
    sizeArray = ARRAY_MAX_CAP;  // Default array capacity is 200
    aList = new objPos[sizeArray];
    sizeList = 0;
 
}
 
objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}
 
int objPosArrayList::getSize()
{
    return sizeList;
 
}
 
void objPosArrayList::insertHead(objPos thisPos)
{
        for (int i = sizeList; i > 0; --i)
    {
        aList[i] = aList[i - 1];
    }
    aList[0] = thisPos;
    sizeList++;
 
 
}
 
void objPosArrayList::insertTail(objPos thisPos)
{
    aList[sizeList] = thisPos;
 
    // Increment the list size
    sizeList++;
 
 
}
 
void objPosArrayList::removeHead()
{
     if (sizeList > 0)
    {
        // Shift elements to the left to remove the head
        for (int i = 0; i < sizeList - 1; ++i)
        {
            aList[i] = aList[i + 1];
        }
 
        // Decrement the list size
        sizeList--;
    }
    
}
 
void objPosArrayList::removeTail()
{
    if (sizeList > 0)
    {
        // Decrement the list size
        sizeList--;
    }
 
}
 
void objPosArrayList::getHeadElement(objPos &returnPos)
{
     if (sizeList > 0)
    {
        returnPos = aList[0];
    }
 
}
 
void objPosArrayList::getTailElement(objPos &returnPos)
{
    if (sizeList > 0)
    {
        returnPos = aList[sizeList - 1];
    }
 
}
 
void objPosArrayList::getElement(objPos &returnPos, int index)
{
     if (index >= 0 && index < sizeList)
    {
        returnPos = aList[index];
    }
 
}
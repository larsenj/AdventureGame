/*******************************************************************************
 ** Program Filename: Ruins.cpp 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: class derived from Space, representing a Ruins.
 ** Input: none.
 ** Output: varies by player input.
 ******************************************************************************/
#include "Ruins.h"

/*******************************************************************************
 ** Function: Space* run(inventory &inv)
 ** Description: runs the events for this class.
 ** Parameters: the struct for the inventory.
 ** Pre-Conditions: valid struct, adjavent spaces initialized.
 ** Post-Conditions: returns a Space ptr based on player input.
 ******************************************************************************/
Space* Ruins::run(inventory& inventory)
{
    //check if been here before
    if(beenHere)
        std::cout << messages[0];
    else
    {
        std::cout << messages[1];
        beenHere = true;
    }

    //exits if wheel solved
    if ( inventory.inv & (1 << (WHEELSOLVED/2)) )
    {
        std::cout << messages[2];
        int selection = getSelection(1,5);
        switch(selection)
        {
            case 1:
                return North;
            case 2:
                return South;
            case 3:
                return East;
            case 4:
                return West;
            default:
                return this;
        }
    }
    //exits if wheel not solved
    else
    {
        std::cout << messages[3];
        int selection = getSelection(1,2);
        switch(selection)
        {
            case 1:
                return West;
            default:
                return this;
        }
    }

}//end run

/*
    Ruins.txt messages
0 - been here before
1 - this is new
2 - where to go, wheel solved
3 - where to go, wheel unsolved

*/

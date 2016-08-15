/*******************************************************************************
 ** Program Filename: Start.cpp 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: class derived from Space, representing the starting point.
 ** Input: none.
 ** Output: varies by player input.
 ******************************************************************************/
#include "Start.h"

/*******************************************************************************
 ** Function: Space* run(inventory &inv)
 ** Description: runs the events for this class.
 ** Parameters: the struct for the inventory.
 ** Pre-Conditions: valid struct, adjavent spaces initialized.
 ** Post-Conditions: returns a Space ptr based on player input.
 ******************************************************************************/
Space* Start::run(inventory& inventory)
{
    //check if been here before
    if(~beenHere)
        std::cout << messages[0];
    else
        std::cout << messages[1];
    
    int selection = getSelection(1,4);
    beenHere = true;
    switch(selection)
    {
        case 1:
            return North;
        case 2:
            return South;
        case 3:
            return East;
        default:
            return this;
    }
    

}


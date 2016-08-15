/*******************************************************************************
 ** Program Filename: End.cpp 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: class derived from Space, representing the end of the game.
 ** Input: none.
 ** Output: varies by player input.
 ******************************************************************************/
#include "End.h"

/*******************************************************************************
 ** Function: Space* run(inventory &inv)
 ** Description: runs the events for this class.
 ** Parameters: the struct for the inventory.
 ** Pre-Conditions: valid struct, adjavent spaces initialized.
 ** Post-Conditions: returns null.
 ******************************************************************************/
Space* End::run(inventory& inv)
{
    std::cout << messages[0];
    return NULL;
}


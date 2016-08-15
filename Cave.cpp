/*******************************************************************************
 ** Program Filename: Cave.cpp 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: class derived from Space, representing a cave.
 ** Input: none.
 ** Output: varies by player input.
 ******************************************************************************/
#include "Cave.h"

using namespace std;

/*******************************************************************************
 ** Function: Space* run(inventory &inv)
 ** Description: runs the events for this class.
 ** Parameters: the struct for the inventory.
 ** Pre-Conditions: valid struct, adjavent spaces initialized.
 ** Post-Conditions: returns a Space ptr based on player input.
 ******************************************************************************/
Space* Cave::run(inventory &inv)
{
    if(beenHere)
        cout << messages[0];
    else
        cout << messages[1];

    cout << messages[2];
        
    int selection = getSelection(1, 5);
    beenHere = true;

    switch(selection)
    {
        case 1:
            return North;;
        case 2:
            return South;
        case 3:
            return East;
        case 4:
            return West;
        default:
            return NULL;
    }
}

/*
    Cave.txt messages:
    0 - been here before
    1 - room is new 
    2 - Explanation, which way to go?
        1 - N
        2 - S  
        3 - E
        4 - W
*/

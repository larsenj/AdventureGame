/*******************************************************************************
 ** Program Filename: River.cpp 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: class derived from Space, representing a river with a ferry.
 ** Input: none.
 ** Output: varies by player input.
 ******************************************************************************/
#include "River.h"

/*******************************************************************************
 ** Function: Space* run(inventory &inv)
 ** Description: runs the events for this class.
 ** Parameters: the struct for the inventory.
 ** Pre-Conditions: valid struct, adjavent spaces initialized.
 ** Post-Conditions: returns a Space ptr based on player input.
 ******************************************************************************/
Space* River::run(inventory& inventory)
{
    //check if been here already
    if (beenHere)
        std::cout << messages[0];
    else
    {
        std::cout << messages[1];
        beenHere = true;
    }

    //check if any coins
    bool coin = false;
    if ( inventory.inv & (1 << (COPPERCOIN/2))
        || inventory.inv & (1 << (SILVERCOIN/2))
        || inventory.inv & (1 << (GOLDCOIN/2))
       )
        coin = true;

    //if no coins in inventory
    if(!coin)
    {
        std::cout << messages[2];
        std::cout << messages[3];
        int selection = getSelection(1, 4);
        switch(selection)
        {
            case 1:
                return North;
            case 2:
                return South;
            case 3:
                return West;
            default:
                return this;
        }
    }//end !coin    

    //if has coins in inventory
    std::cout << messages[4];
    int selection = getSelection(1, 4);
    switch(selection)
    {
        case 1:
        {
            //if it's the copper coin
            if ( inventory.inv & (1 << (COPPERCOIN/2)))
            {
                inventory.inv &= ~(1 << (COPPERCOIN/2));
                std::cout << messages[5];
                return East;
            }
            else
            {
                inventory.inv &= ~(1 << (SILVERCOIN/2));
                inventory.inv &= ~(1 << (GOLDCOIN/2));
                std::cout << messages[6];
                return this;
            }   
        }
        case 2:
            return North;
        case 3:
            return South;
        case 4:
            return West;
        default:
            return this;
    }

    return this;
}


/*
    River.txt messages
0 - been here
1 - this is new
2 - no coins
3 - no coinc, exit
    1.N
    2.S
    3.E
    4.W
4 - has coin
    1. place
    2. N
    3. S
    4. W
5 - placed copper coin
6 - placed other coin
*/

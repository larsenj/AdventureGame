/*******************************************************************************
 ** Program Filename: Fountain.cpp 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: class derived from Space, representing a Fountain.
 ** Input: none.
 ** Output: varies by player input.
 ******************************************************************************/
#include "Fountain.h"

using namespace std;

/*******************************************************************************
 ** Function: Space* run(inventory &inv)
 ** Description: runs the events for this class.
 ** Parameters: the struct for the inventory.
 ** Pre-Conditions: valid struct, adjavent spaces initialized.
 ** Post-Conditions: returns a Space ptr based on player input.
 ******************************************************************************/
Space* Fountain::run(inventory& inventory)
{
    bool solved = false;

    //check if wheel solved
    if ( inventory.inv & (1 << (WHEELSOLVED/2)) )
    {
        solved = true;
    }

    //check if have a coin
    bool coin = false;
    if ( inventory.inv & (1 << (COPPERCOIN/2))
        || inventory.inv & (1 << (SILVERCOIN/2))
        || inventory.inv & (1 << (GOLDCOIN/2))
       )
        coin = true;

    int selection;

    cout << messages[0];

    //if no coin
    if (!coin)
    {
        //menu to pick up a coin or leave alone
        cout << messages[1] << endl;
        selection = getSelection(1, 4);
        switch(selection)
        {
            //inv |= (1 << (c/2)); // sets the bit
            //get copper coin
            case 1:
                inventory.inv |= (1 << (COPPERCOIN/2));
                break;
            //get silver coin
            case 2:
                inventory.inv |= (1 << (SILVERCOIN/2));
                break;
            //get gold coin
            case 3:
                inventory.inv |= (1 << (GOLDCOIN/2));
                break;
            //leave coins alone
            default:
                break;
        }//end switch
    }//end if !coin

    //if have a coin
    if(coin)
    {
        //option to throw back
        cout << messages[2] << endl;
        selection = getSelection(1, 3);
        switch(selection)
        {
            //inv &=  ~(1 << (b/2)); //unsets the bit
            case 1: //thorw it back
                inventory.inv &= ~(1 << (COPPERCOIN/2));
                inventory.inv &= ~(1 << (SILVERCOIN/2));
                inventory.inv &= ~(1 << (GOLDCOIN/2));
                break;
            case 2: //do nothing
                break;
            default:
                break;
        }
    }

    //if wheel solved, go options
    if(solved)
    {
        cout << messages[3] << endl;
        selection = getSelection(1, 5);
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
    //else options
    else
    {
        cout << messages[4] << endl;
        selection = getSelection(1, 3);
        switch(selection)
        {
            case 1:
                return West;
            case 2:
                return South;
            default:
                return this;
        }
    }

    return this;

}

/*
    Fountain.txt messages:
0 - intro to the room
1 - menu if don't have a coin
    1. get copper
    2. get silver
    3. get gold
    4. leave
2 - thow back the coin if have
    1. yes
    2. no
3 - leave, w/ wheel solved
    1. N
    2. S
    3. E    
    4. W
    5. Stay
4 - leave, wheel not solved
    1. E
    2. S
    3. Stay
*/


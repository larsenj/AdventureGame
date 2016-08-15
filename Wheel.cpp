/*******************************************************************************
 ** Program Filename: Wheel.cpp 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: class derived from Space, representing a cave with a complex dial.
 ** Input: none.
 ** Output: varies by player input.
 ******************************************************************************/
#include "Wheel.h"

/*******************************************************************************
 ** Function: Space* run(inventory &inv)
 ** Description: runs the events for this class.
 ** Parameters: the struct for the inventory.
 ** Pre-Conditions: valid struct, adjavent spaces initialized.
 ** Post-Conditions: returns a Space ptr based on player input.
 ******************************************************************************/
Space* Wheel::run(inventory& inventory)
{
    bool solved = false;
    
    //if wheel solved
    if ( inventory.inv & (1 << (WHEELSOLVED/2)) )
    {
        solved = true;
        std::cout << messages[3];
    }
    //if wheel not solved
    else
    {
        if(beenHere)
        {
            std::cout << messages[0];
        }
        else
        {
            std::cout << messages[1];
        }
    }
    
    if(!solved)
    {    
        beenHere = true;
        int innerWheel = 1;
        int outerWheel = 0; 
        
        //loop until inner and outer wheels correct
        do
        {
            //output inner wheel status
            switch(innerWheel)
            {
                case 0:
                    std::cout << messages[5];
                    break;
                case 1:
                    std::cout << messages[6];
                    break;
                default:
                    std::cout << messages[7];
                    break;
            }

            //output outer wheel
            switch(outerWheel)
            {
                case 0:
                    std::cout << messages[8];
                    break;
                case 1:
                    std::cout << messages[9];
                    break;
                default:
                    std::cout << messages[10];
                    break;
            }

            //menu selection
            std::cout << messages[2];
            int selection = getSelection(1, 7);

            switch(selection)
            {
                //inner counter-clockwise
                case 1:
                    innerWheel = (innerWheel + 1)%3;
                    break;
                //inner clockwise
                case 2:
                    if(innerWheel == 0)
                        innerWheel = 2;
                    else
                        innerWheel = (innerWheel - 1)%3;
                    break;
                //outer counter-clockwise
                case 3:
                    outerWheel = (outerWheel + 1)%3;
                    break;
                //outer clockwise
                case 4:
                    if(outerWheel == 0)
                        outerWheel = 2;
                    else
                        outerWheel = (outerWheel - 1)%3;
                    break;
                case 5:
                    return North;
                case 6:
                    return West;
                default:
                    return NULL;
            }//end selection switch

            //std::cout << "Inner: " << innerWheel << " Outer: " << outerWheel << endl;
        }while (innerWheel != 1 || outerWheel != 1);//end while

        //set wheel solved
        //inv |= (1 << (c/2)); // sets the bit
        inventory.inv |= (1 << (WHEELSOLVED/2));

        //passages opening
        std::cout << messages[11];

    }//end if !solved



    //selection if solved
    if (solved)
    {
        std::cout << messages[4];
        int selection = getSelection(1, 5);

        switch(selection)
        {
            case 1:
                return North;
            case 2:
                return South;
            case 3:
                return East;
            default:
                return West;
        }
    }//end if solved

    return this;

}//end run

/*
    Wheel.txt messages:
    0 - been here before
    1 - room is new, explanation 
    2 - menu and with exit options
        1. Turn inner wheel c-clock
        2. Turn inner wheel clock
        3. Turn outer wheel c-clock
        4. Turn outer wheel clock
        5. North
        6. West
    3 - arriving with wheel solved
    4 - wheel solved, exit options
        1. North
        2. South
        3. East
        4. West
    5 - innerWheel value is 0(sun)
    6 - innerWheel value is 1(star)
    7 - innerWheel value is 2(moon)
    8 - outerWheel value is 0(moon)
    9 - outerWheel value is 1(star)
    10 - outerwheel value is 2(sun)
    11 - passages opening
*/




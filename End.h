/*******************************************************************************
 ** Program Filename: End.h 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: class derived from Space, representing the end of the game.
 ** Input: none.
 ** Output: varies by player input.
 ******************************************************************************/
#ifndef END_H
#define END_H

#include "Space.h"

class End : public Space
{
    public:
        Space* run(inventory&);

        inline End(std::string fileName): Space(fileName){}
};

#endif

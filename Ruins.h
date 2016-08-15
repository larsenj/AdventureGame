/*******************************************************************************
 ** Program Filename: Ruins.h 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: class derived from Space, representing a Ruins.
 ** Input: none.
 ** Output: varies by player input.
 ******************************************************************************/
#ifndef RUINS_H
#define RUINS_H

#include "Space.h"

class Ruins : public Space
{
    public:
        Space* run(inventory&);

        inline Ruins(std::string fileName): Space(fileName){}
};

#endif

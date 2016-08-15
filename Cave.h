/*******************************************************************************
 ** Program Filename: Cave.h 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: class derived from Space, representing a cave.
 ** Input: none.
 ** Output: varies by player input.
 ******************************************************************************/
#ifndef CAVE_H
#define CAVE_H

#include "Space.h"

class Cave : public Space
{
    public:
        Space* run(inventory&);

        inline Cave(std::string fileName): Space(fileName){}
};

#endif

/*******************************************************************************
 ** Program Filename: River.h 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: class derived from Space, representing a river with a ferry.
 ** Input: none.
 ** Output: varies by player input.
 ******************************************************************************/
#ifndef RIVER_H
#define RIVER_H

#include "Space.h"

class River : public Space
{
    public:
        Space* run(inventory&);

        inline River(std::string fileName): Space(fileName){}
};

#endif

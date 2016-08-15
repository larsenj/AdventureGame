/*******************************************************************************
 ** Program Filename: Start.h 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: class derived from Space, representing the starting point.
 ** Input: none.
 ** Output: varies by player input.
 ******************************************************************************/
#ifndef START_H
#define START_H

#include "Space.h"

class Start : public Space
{
    public:
        Space* run(inventory&);

        inline Start(std::string fileName): Space(fileName){}
};

#endif

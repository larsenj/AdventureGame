/*******************************************************************************
 ** Program Filename: Fountain.h 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: class derived from Space, representing a Fountain.
 ** Input: none.
 ** Output: varies by player input.
 ******************************************************************************/
#ifndef FOUNTAIN_H
#define FOUNTAIN_H

#include "Space.h"

class Fountain : public Space
{
    public:
        Space* run(inventory&);

        inline Fountain(std::string fileName): Space(fileName){}
};

#endif

/*******************************************************************************
 ** Program Filename: Wheel.h
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: class derived from Space, representing a cave a complex dial
 ** Input: none.
 ** Output: varies by player input.
 ******************************************************************************/
#ifndef WHEEL_H
#define WHEEL_H

#include "Space.h"

class Wheel : public Space
{
    public:
        Space* run(inventory&);

        inline Wheel(std::string fileName): Space(fileName){}
};

#endif

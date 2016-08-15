/*******************************************************************************
 ** Program Filename: Space.h 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: abstract base class for the different spaces.
 ** Input: string with name of a text file.
 ** Output: varies by derived class.
 ******************************************************************************/
#ifndef SPACE_H
#define SPACE_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include "Inventory.h"

class Space
{
    public:
        Space* North;
        Space* South;
        Space* East;
        Space* West;

        bool beenHere;
        std::vector<std::string> messages;

        void setAdjacency (Space*, Space*, Space*, Space*); 
        int getSelection(int, int);

        virtual Space* run(inventory&) = 0;

        Space(std::string);
        virtual inline ~Space()
        {
            North = NULL;
            South = NULL;
            West = NULL;
            East = NULL;
        }
};

#endif

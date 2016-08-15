/*******************************************************************************
 ** Program Filename: Space.cpp
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: abstract base class for the different spaces.
 ** Input: string with name of a text file.
 ** Output: varies by derived class.
 ******************************************************************************/
#include "Space.h"

/*******************************************************************************
 ** Function: void setAdjacency(Space* N, Space* S, Space* E, Space* W)
 ** Description: sets the adjecencies of the current room.
 ** Parameters: 4 Space ptrs
 ** Pre-Conditions: the ptrs are not null.
 ** Post-Conditions: adjacent rooms set.
 ******************************************************************************/
void Space::setAdjacency(Space* N, Space* S, Space* E, Space* W)
{
    North = N;
    South = S;
    East = E;
    West = W;
}

/*******************************************************************************
 ** Function: int getSelection(int min, int max)
 ** Description: prompts the user to input a number and checks for errors. 
 ** Parameters: min and max range of required numbers.
 ** Pre-Conditions: none.
 ** Post-Conditions: a valid int is returned.
 ******************************************************************************/
int Space::getSelection(int min, int max)
{
    int selection;
    std::cin >> selection;

    //check for valid input
    while (std::cin.fail() || selection > max || selection < min)
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Do not tarry, enter a valid selection! ";
        std::cin >> selection;
    }
    return selection;
}

/*******************************************************************************
 ** Function: Space(std::string fileName) : beenHere(false)
 ** Description: constructor, opens relevant text file. 
 ** Parameters: string name of text file.
 ** Pre-Conditions: file exists.
 ** Post-Conditions: corresponding text file loaded into string vector.
 ******************************************************************************/
Space::Space(std::string fileName) : beenHere(false)
{
    std::ifstream inFile(fileName.c_str());
    std::string s = "Cannot open " + fileName;
    if (!inFile)
    {
        std::cout << s << std::endl;
        throw s;
    }
    std::string temp;
    while ( std::getline(inFile, temp, '~') )
        messages.push_back(temp);
}

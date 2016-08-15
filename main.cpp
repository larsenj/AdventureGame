/*******************************************************************************
 ** Program Filename: main.cpp 
 ** Author: Jon Larsen
 ** Date: 7 Aug 2016
 ** Description: 
 ** Input: may take a command line argument of "hints".
 ** Output: text based on the game.
 ******************************************************************************/

#include <cstring>

#include "Cave.h"
#include "Fountain.h"
#include "Wheel.h"
#include "Ruins.h"
#include "River.h"
#include "Start.h"
#include "End.h"

void initRooms(Space**);
void getHint(Space**, Space*);
void death(Space*&);

int main(int argc, char* argv[])
{
    //check if hints are enabled
    bool hints = false;
    if(argc == 2)
        if( strcmp(argv[1], "hints") == 0 )
            hints = true;
    
    int timer = 0;
    int limit = 15;

    //initialize the rooms
    Space* game[7];
    initRooms(game);

    //initialize the inventory
    inventory inv;
    inv.inv = 0;

    //main game loop
    bool wheelSolved = false;
    Space* player = game[0];
    do
    {
        if(hints)
            getHint(game, player);
        player = player->run(inv);
        if ( inv.inv & (1 << (WHEELSOLVED/2)) )
        {
            wheelSolved = true;
        }

        timer++;
        if(timer == limit)
            death(player);

    }while (!wheelSolved && player != NULL);
    
    if (player != NULL)
    {
        //change up rooms if the wheel is solved
        std::cout << "I also hear in the distance the sound of rock scraping against"
            << " rock. I feels as though some passageways have opened up" << std::endl;
        delete game[0];
        game [0] = new Cave("Cave.txt");
        game[0]->setAdjacency(game[2], game[3], game[4], game[0]);
    }

    //resume game
    while (player != NULL)
    {
        if(hints)
            getHint(game, player);
        player = player->run(inv);

        timer++;
        if(timer == limit)
            death(player);
    }//while (player != NULL);

    //cleanup
    for(int i = 0; i < 7; i++)
    {
        delete game[i];
        game[i] = NULL;
    }

}

/*******************************************************************************
 ** Function: void initRooms(Space** game)
 ** Description: initializes the array of rooms and sets their adjacencies.
 ** Parameters: an array of Space pointers.
 ** Pre-Conditions: relevant text files exist.
 ** Post-Conditions: array initialized with adjacencies set. 
 ******************************************************************************/
void initRooms(Space** game)
{
    //create the rooms
    game[0] = new Start("Start.txt");
    game[1] = new Cave("Cave.txt");
    game[2] = new Fountain("Fountain.txt");
    game[3] = new Wheel("Wheel.txt");
    game[4] = new Ruins("Ruins.txt");
    game[5] = new River("River.txt");
    game[6] = new End("End.txt");

    //set adjacencies     north    south    east     west 
    game[0]->setAdjacency(game[3], game[2], game[4], game[0]); //start w,f,r,c
    game[1]->setAdjacency(game[2], game[3], game[4], game[0]); //cave 
    game[2]->setAdjacency(game[4], game[1], game[5], game[0]); //fountain
    game[3]->setAdjacency(game[1], game[4], game[5], game[0]); //wheel
    game[4]->setAdjacency(game[3], game[2], game[5], game[0]); //ruins
    game[5]->setAdjacency(game[3], game[2], game[6], game[4]); //river
    game[6]->setAdjacency(game[6], game[6], game[6], game[6]); //end
} 

/*******************************************************************************
 ** Function: void getHint(Space** game, Space* player)
 ** Description: provides hints for each room.
 ** Parameters: the array of Space pointers, the current player pointer.
 ** Pre-Conditions: array initialized properly, player not null.
 ** Post-Conditions: hints printed to stdout.
 ******************************************************************************/
void getHint(Space** game, Space* player)
{
    if (player == game[0])      //start
        std::cout << "\n(HINT: go north)" << std::endl;
    else if (player == game[1]) //cave
        std::cout << "\n(HINT: get back to one of other rooms)" << std::endl;
    else if (player == game[2]) //fountain
        std::cout << "\n(HINT: get the copper coin then go East if possible)" 
            << std::endl;
    else if (player == game[3]) //wheel
        std::cout << "\n(HINT: turn the two wheels until the stars are up top"
            << " then go South to the fountain)" << std::endl;
    else if (player == game[4]) //ruins
        std::cout << "\n(HINT: move North or South if you haven't been there"
            << "  before)" << std::endl;
    else if (player == game[5]) //river
        std::cout << "\n(HINT: put the copper coin in the can)" << std::endl;
    else if (player == game[6]) //end
        std::cout << "\n(HINT: you've reached the end)" << std::endl;
}

/*******************************************************************************
 ** Function: void death(Space*& player)
 ** Description: player death, called if the timer reaches a limit.
 ** Parameters: a reference to the player pointer.
 ** Pre-Conditions: timer counter reached limit.
 ** Post-Conditions: player pointer set to NULL.
 ******************************************************************************/
void death(Space*& player)
{
    std::cout << "As I continue to walk I hear the multitudes of the echos of\n"
       << "  my steps bouncing against what passes for walls. I stop for a moment\n"
       << " to catch my breath, but find this impossibly difficult once I realize\n"
       << " the echoing of the steps did not stop! I turn around, only to face the\n"
       << " personification of my nightmares made flesh. I heard horrid screaming,\n"
       << " and dispite my horror I feel a pang of pity for whatever poor soul\n"
       << " it is I head making the kinds of sounds no human should ever make.\n"
       << " It is only then that I realize the screams are coming from me." 
       << std::endl;
    player = NULL;
}

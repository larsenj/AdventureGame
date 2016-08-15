/*
 * test.cpp
 * A primitive test suite for the various classes and their function
 */

#include "Cave.h"
#include "Fountain.h"
#include "Wheel.h"
#include "Ruins.h"
#include "River.h"
#include "Start.h"
#include "End.h"

using namespace std;

int main()
{
    inventory inv;
    inv.inv = 0;
    
    Space* player = NULL; 

    Space* c = new Cave("Cave.txt");

    //void setAdjacency (Space*, Space*, Space*, Space*); 
    c->setAdjacency(c, c, c, c);
    player = c;

    //test changing rooms until null
    do
    {
        player = player->run(inv);
    } while (player != NULL);

    //test the wheel room
    Space* w = new Wheel("Wheel.txt");
    w->setAdjacency(c, c, c, c);
    player = w->run(inv);
    player = w->run(inv);

    //test the fountain room
    Space* f = new Fountain("Fountain.txt");
    f->setAdjacency(c, c, c, c);
    player = f->run(inv);
    player = f->run(inv);

    //test the ruins room
    Space* r = new Ruins("Ruins.txt");
    r->setAdjacency(c, c, c, c);
    player = r->run(inv);
    player = r->run(inv);
    
    //test the river room
    Space* rv = new River("River.txt");
    rv->setAdjacency(c, c, rv, c);
    player = rv->run(inv);
    inv.inv |= (1 << (COPPERCOIN/2)); // sets the bit
    player = rv->run(inv);

    //test the start and the end rooms
    Space* st = new Start("Start.txt");
    Space* end = new End("End.txt");
    st->setAdjacency(end, end, end, end);
    player = st->run(inv);
    player = player->run(inv);

}

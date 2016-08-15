#ifndef INVENTORY_H
#define INVENTORY_H

enum item { COPPERCOIN = 1, SILVERCOIN = 2, GOLDCOIN = 4, WHEELSOLVED = 8};

struct inventory
{
    int inv;
    /* Inventory Items:
     * 1 - Copper coin
     * 2 - Silever coin
     * 4 - Gold coin
     * 8 - NYI
     * 16 - NYI
     * 32 - NYI
     * 64 - NYI
     * 128 - NYI
     */
};

/* Notes:
 * if ( inv & (1 << (item/2)) )//returns true if bit was set
 * inv |= (1 << (c/2)); // sets the bit
 * inv &=  ~(1 << (b/2)); //unsets the bit
 */





#endif

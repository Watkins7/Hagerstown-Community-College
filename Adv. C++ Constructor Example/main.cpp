#include <iostream>
#include "Weapon.h"
using namespace std;

int main() {

    // the "*" means it is a location in memory, it is a refrence not a copy
Weapon* bow = new Weapon;
Weapon* bow2 = new Weapon(6, "DragonSlayer Bow", 99, 50.5, true);

bow2->lowerDurability(9);


delete bow2;


}
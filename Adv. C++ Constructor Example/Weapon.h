//
// Created by willi on 1/23/2019.
//

#ifndef UNTITLED2_WEAPON_H
#define UNTITLED2_WEAPON_H

#include <string>

class Weapon {

protected:
    int defaultDamage;
    std::string name;
    int durability;
    float weight;
    bool magicResist;

public:
    //Creates and empty object (constructor)
    Weapon();

    //specific everything at the time of creating an object (constructor)
    Weapon(int defaultDamage, std::string name, int durability, float weight, bool magicResist);

    //Destructor
    ~Weapon();


    int use();

    //Lowers durability
    void lowerDurability(int i);

};


#endif //UNTITLED2_WEAPON_H

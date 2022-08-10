//
// Created by willi on 1/23/2019.
//

using namespace std;

#include "Weapon.h"
#include "iostream"





//the "::" limits the scope to the Weapon.h file
Weapon::Weapon() {

    //this points to the protected value in the .h file
    this->defaultDamage = 0;
    this->name = "";
    this->durability = 0;
    this->weight = 0;
    this->magicResist = false;
}


//specific everything at the time of creating an object (constructor)
Weapon::Weapon(int defaultDamage, std::string name, int durability, float weight, bool magicResist)
{
    //this means looks in the header file first
    this->defaultDamage = defaultDamage;
    this->name = name;
    this->durability = durability;
    this->weight = weight;
    this->magicResist = magicResist;
}



//Destructor
Weapon::~Weapon(){
    cout << "Destroying object" << this->name;
}


int Weapon::use(){
    lowerDurability(1);
    return this->defaultDamage;


}


void Weapon::lowerDurability(int i){
    this->durability -=1;
    cout << durability;
}

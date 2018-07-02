//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Recitation 11- #1 Planet class

#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <iostream>

using namespace std;

class planet{
    public:
        planet();
        planet(string planetName, float planetRadius); //Constructor that takes two arguments, the name of the planet and the radius of the planet (in km)
        ~planet(); //Destructor
        
        void setName(string);
        string getName();
        void setRadius(float);
        float getRadius();
    
    private:
        string name;
        float radius;
};
#endif //PLANET_H
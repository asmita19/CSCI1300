//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Recitation 11: #2 Solar System 

#include "planet.h"
#include "solarSystem.h"
#include "math.h" 


solarSystem::~solarSystem(){ //complier handles the deconstruction of the class
}
solarSystem::solarSystem(string nameofSystem){
    systemName = nameofSystem;
    numPlanets = 0;
    maxNumPlanets = 10;
}

string solarSystem::getName(){//getter for system name
    return systemName;
}

int solarSystem::getNumPlanets(){
    return numPlanets; //number of planets in the solar system
}

bool solarSystem::addPlanet(string planetName, float planetRadius){
    for(int i = 0; i < numPlanets; i++){
        if(systemPlanets[i].getName() == planetName){
            return false;
        }
    }
    systemPlanets[numPlanets] = planet(planetName, planetRadius);
    numPlanets++;
    return true;
}

planet solarSystem::getPlanet(int planetNumber){
    return systemPlanets[planetNumber]; //returns planet name at index of system planet
}

float solarSystem::radiusDifference(planet one, planet two){
    float difference = one.getRadius() - two.getRadius();
    int absdifference = fabs(difference);
    cout<<"Radius difference between planet "<<one.getName()<<" and planet "<<two.getName()<<" is: "<<absdifference<<endl;
}
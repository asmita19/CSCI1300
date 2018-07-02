//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Recitation 11- Solar System class  


#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <string>
#include <iostream>
#include "planet.h"
using namespace std;

class solarSystem{
	public:
		solarSystem(string);//constructor 
		~solarSystem(); //Destructor

		string getName();// return the name of the solar system
		int getNumPlanets();// return the number of planets in the system
		bool addPlanet(string, float);	//Adds a single planet to solar system
		planet getPlanet(int);  	// return an object of planet at provided index
		float radiusDifference(planet, planet);
	
	private:
		int maxNumPlanets; // This should be initialized to 10 in the constructor
		string systemName;
		int numPlanets;
		planet systemPlanets[10]; // array of object planet, each object is a planet
		
};
#endif // SOLAR_SYSTEM_H

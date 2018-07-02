//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Recitation 11: Solar System main

#include "planet.h"
#include "planet.cpp"
#include "solarSystem.cpp"
#include "solarSystem.h"
#include "math.h"

using namespace std;


/*
	This function implements the logic to find the difference between the radius
	of all the planets in the system.
	Notes:
	* having more or less outputs means that your logic is not quite correct.
	* do not hard code the cout statements; use a smart logic instead.
	* use fabs() to compute the absolute value of the difference (do it either in your impementation of
	radiusDifference(planet,planet) or use it after you return the function call to radiusDifference(planet,planet)
	* your output should have the following structure:
	cout<<"Radius difference between planet " <<  <<" and planet "<< <<
	" is => "<< <<endl;
	* for 5 planets you should have 10 outputs.
*/
void compareRadii(solarSystem thisSystem, int num_of_planets) {
	// Logic for 2 goes here
	for (int i = 0; i < num_of_planets; i++){
		for (int j = i + 1; j < num_of_planets; j++){
			planet one = thisSystem.getPlanet(i);
			planet two = thisSystem.getPlanet(j);
			cout<<"Radius difference between planet "<<one.getName()<<" and planet "<<two.getName()<<" is: "<<thisSystem.radiusDifference(one, two)<<endl;
		}
	}
}


int main() {

/*
	1) Ask the user to create a solar system by promting him for 5 instances
	of type Planet. You will ask the user for name and radius of each
	Planet. Each object will have to have a unique name.
	Notes and hints:
	* you can use getline() to make the process faster
	* if you use getline use a smart delimeter to process name and radius in one user input
	* make sure to check if name already exists. If it does, ask the user to enter another name.
*/
	int i;
	int j = 5;
	bool unique;
	string name;
	string radius;

// Logic for 1 goes here

	solarSystem thisSystem("neptune");

	for(i = 0; i < j; i++){
		cout <<"Enter name of the planet: "<< endl;
		getline(cin, name);
		cout<<"Enter radius of the planet: "<<endl;
		getline(cin, radius);
		float newRadius = stof(radius);
		unique = thisSystem.addPlanet(name, newRadius);
		
		if(!unique){
			cout<<"Same name, please enter differnt name."<<endl;
			cout<<"Enter name of the planet: "<<endl;
			getline(cin, name);
			cout<<"Enter radius of the planet: "<<endl;
			getline(cin, radius);
			newRadius = stoi(radius);
		}
	}

// Use the following snipped of code to test that you filled your system correctly
// !!NOTE: here "<obj_of_type_solarSystem>" is a placeholder you should use the name
//  of your solarSystem instance created (hopefully) above.

	i = 0;
	int num_of_planets = thisSystem.getNumPlanets();
	if(num_of_planets <= 5){
		cout<<"Your system has less than 5 planets!"<< endl;
	}
	while(i < num_of_planets){
		cout<<"This is planet "<<i<<" with name: "<<thisSystem.getPlanet(i).getName()<<" and radius: "<<thisSystem.getPlanet(i).getRadius()<<endl;
		i++;
	}

/*
	2) Add the method radiusDifference(...) to the SolarSytem class. This method
	takes two objects of type Planet and returns the difference of their
	radius. Develop a logic to return the difference among all the planets in a
	function called compareRadii(...) that takes two params, a solarSystem and the
	number of planets in the system. You can find the function definition above
	the main. Once you are done implementing it call it.
*/


// !!NOTE: here "<obj_of_type_solarSystem>" and "<num_of_planets> are placeholders
// you should use the name of your solarSystem instance created (hopefully) above
// and the number of planets currently in the solarSystem

	compareRadii(thisSystem, 5);
	return 0;
}
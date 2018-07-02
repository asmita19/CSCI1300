//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Recitation 11: Planet


#include "planet.h"

planet::planet(){
	radius = 0.0;
}

planet::planet(string planetName, float planetRadius){
	name = planetName;
	radius = planetRadius;
}

planet::~planet(){
	//letting compiler handle deconstruction of the class
}

void planet::setName(string planetName){
	name = planetName;
}

string planet::getName(){
	return name;
}

void planet::setRadius(float planetRadius){
	radius = planetRadius;
}

float planet::getRadius(){
	return radius;
}

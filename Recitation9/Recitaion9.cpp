//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Recitation 8

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

/**Algorithm:Every Robot has an x position, y position, and a heading. 
 * We want to represent these attributes of the Robot by data members in the class.
 * A class "Robot" with the following public attributes:
 * 1.an integer x for the robot's x position
 * 2.an integer y for the robot's y position
 * 3.a character heading for the robot's heading ('N', 'S', 'E', "W')
 * 4.add a  public constructor that takes
 * --an int start_x
 * --an int start_y
 * --a char start_heading and sets the robot's attributes.
 */
//Problem1:
class Robot{
  public:
    int x, y;
    char heading;
    Robot(int start_x, int start_y, char start_heading){
     x = start_x;
     y = start_y;
     heading = start_heading;
    }
};

/**Algorithm: change the x, y, and heading attributes(from problem 1) so that they have the private modifier.  
 * Then, create the getter and setter methods for the Robot class. 
 * writen methods to get and set the values of the x, y, and heading attributes.
 * Getters: getX, getY, getHeading
 * Setters:setX, setY, setHeading
 * getters returns the corresponding attribute 
 * -the setters takes in a value and set the attribute accordingly.
 */
//Problem2:
class Robot{
  public:
    int x, y;
    char heading;
    Robot(int start_x, int start_y, char start_heading){
        x = start_x;
        y = start_y;
    }
    void setX(int i){
        x = i;
    }
    void setY(int i){
        y = i;
    }
    
    int getX(){
        return x; 
    }
    int getY(){
        return y;
    }
    void setHeading(char c){
        heading = c;
    }
    char getHeading(){
     return heading; 
    }
};

/**Algorithm:Adds the public functions turnLeft, turnRight, and moveForward. 
 * The functions updates the robot's x, y, and heading attributes and doesn't return anything.
 * turnLeft and turnRight updates the robot's heading. 
 * --If the robot's heading is 'N', turnLeft results in the new heading being 'W'
 * moveForward updates the robot's x or y position by 1. 
 * --If the robot's heading is 'N', moveForward results in the y position increasing by one. 
 * --If the robot's heading is 'S', moveForward results in the y position decreasing by one.
 */
//Problem3:
class Robot{
  public:
    int x, y;
    char heading;
    Robot(int start_x, int start_y, char start_heading){
     x = start_x;
     y = start_y;
     heading = start_heading;
    }
    void setX(int i){
        x = i;
    }
    void setY(int i){
        y = i;
    }
    void setHeading(char c){
        heading = c;
    }
    void turnLeft(){
        if (heading == 'N')
            heading = 'W';
        else if(heading == 'W')
            heading = 'S';
        else if (heading == 'S')
            heading = 'E';
        else if (heading == 'E')
            heading = 'N';
    }
    void turnRight(){
        if (heading == 'N')
            heading = 'E';
        else if(heading == 'E')
            heading = 'S';
        else if (heading == 'S')
            heading = 'W';
        else if (heading == 'W')
            heading = 'N';
    }
    void moveForward(){
       if (heading == 'N')
            y++;
        else if(heading == 'E')
            x++;
        else if (heading == 'S')
            y--;
        else if (heading == 'W')
            x--;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    char getHeading(){
        return heading;
    }
};

/**Algorithm:The constructor battleShip(string) takes the ship name and should set all the data members of the ship to the correct value. 
 * The default size of a ship is -1.
 * The function recordHit() should print "<name> has been hit <hits> times." 
 * For example, if a ship named "Carrier" with size 5 had 4 hits, I would expect the output
 * 1."Carrier has been hit 4 times."
 * The function isSunk() should print "<name> has been sunk."
 * 1.For example, if a ship named "Destroyer" has sunk, I would expect the output
 * --"Destroyer has been sunk."
 */
//Problem4:
class battleShip{
	public:
		battleShip(string);
		~battleShip();
		void setShipName(string);
		string getShipName();
		void setSize(int);
		int getSize();
		void recordHit();	// Increments the hits data member
		bool isSunk();	// returns true if hits is greater than equal to size
	private:
		string name;
		int size;
		int hits;
};

battleShip::battleShip(string shipName){
  name = shipName;
  size = -1;
  hits = 0;//hits is set to 0 for a new ship
}

battleShip::~battleShip(){
}
void battleShip::setShipName(string newName){
  name = newName;
}

string battleShip::getShipName(){
  return name;
}

void battleShip::setSize(int newSize){
  size = newSize;
}

int battleShip::getSize(){
  return size;
}

void battleShip::recordHit(){
  hits++;
  cout<<name<<" has been hit "<<hits<<" times."<<endl;
}

bool battleShip::isSunk(){
  if (hits >= size){
    cout<<name<<" has been sunk."<<endl;
    return true;
  } 
  else{
    return false;
  }
}

/**Algorithm: play function that uses the battleShip class and runs a game of Battleship.
 * Keeps hitting all three ships until all three have been sunk, 
 * --and always hit them in the order Destroyer, Carrier, then Cruiser.
 */
//Problem5:
void play(){
    class battleShip{
	public:
		battleShip(string);
		~battleShip();
		void setShipName(string);
		string getShipName();
		void setSize(int);
		int getSize();
		void recordHit();	// Increments the hits data member
		bool isSunk();	// returns true if hits is greater than equal to size
	private:
		string name;
		int size;
		int hits;
};
    //TODO: Declare 3 instances/objects of the battleship class: Destroyer Carrier Cruiser
    battleShip Destroyer("Destroyer");
    battleShip Carrier("Carrier");
    battleShip Cruiser("Cruiser");
    //TOD0: Give the ships a size: Destroyer-3 Carrier-5 Cruiser-2
	// you will need to call the appropriate methods
	Destroyer.setSize(3);
	Carrier.setSize(5);
	Cruiser.setSize(2);
	    // Once you have this running for one, expand this while loop to include the
	// other two instances. Have the while loop end when all three ships have been sunk.
        // Make your while condition while ship one is not sunk OR ship two is not sunk OR ship three is not sunk.

    while(Destroyer.isSunk() == false || Carrier.isSunk() == false || Cruiser.isSunk() == false){
		Destroyer.recordHit();
		Carrier.recordHit();
		Cruiser.recordHit();
	}
}

//main:
int main(){
    //make two robots and make 2 ships in the main to run it
}


int i = 0;
while(i < size){
    i++;
}



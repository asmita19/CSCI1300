//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun Kim
//Homework # 2

#include <iostream>
using namespace std;
/**
 * Algorithm: Calculates the U.S. population in exactly one year
 * Given:birth every 8 seconds, death every 12 seconds, and new immigrant arriving in the US every 33 seconds.
 * returns the current population after calulating the givens in the year to the user. 
*/
//Problem 1:
int population (int current_pop)
{
  current_pop += (365*60*60*24/8)-(365*60*60*24/12)+(365*60*60*24/33);//Caculating the population given the births, deaths, and immigrants. 
  return current_pop;//returning the new population.
}

/**
 * Algorithm: Calculates the initial seconds into days, hours, minutes, and seconds. 
 * Check if seconds is less than 0
 *  -if it is then seconds = 0. 
 * Initial seconds = seconds, which is the parameter
 * initialize days, hours, and minutes to 0.
 * calculate days, hours, and minutes. 
 * Outputs: the initial seconds broke down to days, hours, minutes, and calculated seconds. 
*/
//Problem 2:
void howLong(int seconds){
    if(seconds < 0){
        seconds = 0;
    }
    int ini_seconds = seconds;//creating a new variable for seconds so when outputed calculated seconds doesn't come up as initial seconds.
    int days = 0;
    int hours = 0;
    int minutes = 0;
    days = seconds/86400;//breaks down the days in the initial seconds
    seconds = seconds-days*86400;
	hours = seconds/3600;//breaks down the hours in the initial seconds
	seconds = seconds-hours*3600;
	minutes = seconds/60;//breaks down the minites in the initial seconds
	seconds = seconds-60*minutes;

    cout<<ini_seconds<<" seconds is "<<days<<" days, "<<hours<<" hours, "<<minutes<<" minutes, and "<<seconds<<" seconds."<<endl;
}

/**
 * Algorithm: Calculating the Carnot effiency with it being the maximum possible 
 * efficiency of a heat engine operating between two reservoirs at different temperatures.
 * Calculates the effiency "1 - tc/th" and then reutns the effiency to the user.  
*/
//Problem 3:
float carnot(float tc, float th){
    float efficiency;
    efficiency = 1 - tc/th;//calculating the efficiency. 
    return efficiency;//returns the efficiency.
}

//Main function to test the problems. 2 test cases for each problem.  
int main(){
    cout<<"The population is "<<population(20000)<<" people in the US."<<endl;
    howLong(3000032);
    cout<<"The Carnot effiency is "<<carnot(345.50, 75.94)<<"."<<endl;
    cout<<endl;
    cout<<"The population is "<<population(23060)<<" people in the US."<<endl;
    howLong(7000342);
    cout<<"The Carnot effiency is "<<carnot(33.00, 67.54)<<"."<<endl;
}

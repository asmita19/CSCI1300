//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Homework 3: Problem 2

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/**Algorithm:For part A, uses the formula provided by the pdf/writeup to do the calculations
 * floats the parameters T(air temp) and V(wind speed) 
 * calculates the wind chill given the equation from write up and returns the wind chill
 * While loop to say if wind chill is less than or equal to 0, output "Not applicable" with the wind chill value.
 */ 
 
//part1:
float windChillCalculator(float T, float V){
    
     if (V < 0){
        cout<<"Not applicable"<<endl;
        return 0;
    }
    float wind_chill = 35.74 + 0.6215 * T - (35.75 * pow(V, 0.16)) + (0.4275 * T * pow(V, 0.16));//floats the wind chill variables and initilizes it as with the equation given. 
    return wind_chill;
}

/**Algorithm:For part B, changes wind speed to a variable and creates a loop to calculate all the output which varies with the variables 
 * from low wind speed to high wind speed.
 * -if statement says if low wind speed is greater than high wind speed or wind speed step is less than 0 then output "Invalid input."
 * -while loop says while low wind speed is less than or equal to high wind speed output the windchill with the windchill calculator and variables T(air temp) and low wind speed. 
 * --then adds low wind speed to itself plus wind speed step.
 */

//Part2:
float printWindChill(float T, float low_wind_speed, float high_wind_speed, float wind_speed_step){
   
    if(low_wind_speed > high_wind_speed || wind_speed_step < 0){// if low wind speed is greater than high wind speed or wind speed is less than zero then the following conditions is ran
        cout<<"Invalid input"<<endl;
        return 0;
    }
   while(low_wind_speed <= high_wind_speed){
       cout << "The wind chill is "<<windChillCalculator(T,low_wind_speed)<<" degrees F for an air temperature of "<<T<<" degrees F and a wind speed of "<<low_wind_speed<< " mph."<<endl;
       low_wind_speed += wind_speed_step;//low wind speed = low wind speed + wind speed step
   }
}
/**Algorithm: Main function for test cases
 * Part 1 test case: floats windchill and calls the windChillCalculator function with the parameters.
 * Part 2 test case: floats the values with the given numberds for test cases, calls the printWindChill function with the parameters. 
 * -returns 0 if the all runs through.
 */
int main(){
    //part1 test
    float wind_chill = windChillCalculator(30.0, 5.0);
    cout<<"The wind chill is "<<wind_chill<<" degrees F."<<endl;
    
    //part2 test
    float T= 30.0;
    float V= 5.0;
    float low= 5.0;
    float high= 8.0;
    float step=1.0;
    printWindChill(T, low, high, step);//calls the print wind chill function with the variables.
    return 0;
    
}


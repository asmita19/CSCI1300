#include <iostream>
#include <string>
#include <math.h>
using namespace std;
/**Question:Write a function named CoffeeCost to calculate the cost of a student's coffee consumption. 
 * The function will take an integer for the number of cups of coffee and a floating point value for the cost per cup. 
 * The function will return a floating point value for the total cost of coffee. 
The students use a coffee house that rewards the student for caffeine overload by giving a free cup for buying every 12 cups.

Calculate the cost as units times the per unit cost: 
                 cost = units * cost per unit
 */
//#1: DONE
float CoffeeCost(int cup, float c_cups){
    float cost = 0.0;
    int i = 0;
    while(i <= cup){
        if(i % 13 != 0){
            cost = cost + c_cups;
        }
        i++;
    }
    return cost;
}

/**Question:Write a function, GasBill, that is given integer value for units used. 
 * The function will return a floating point value for the total cost.  

Your function will calculate a cost using the following conditions as the cost of the gas depends on how much is used. 
       First 100 units are charged at $1.23 per unit, 
       the next 100 units are $1.14 per unit, 
       any units above 200 are charged at $1.08 per unit.

For invalid parameter value, print "Incorrect input" and return 0
For example: 
      if 244 units were used, 100*1.23 + 100*1.14 + 44*1.08 would calculate the cost. 
      If only 87 units were used, the cost would be 87*1.23.
 */
//#2: DONE
float GasBill(int units){
    float cost;
    if(units < 0){
        cout<<"Incorrect input"<<endl;
    }
    else if(units <= 100){
        cost = units * 1.23;
    }
    else if(units > 100 && units < 199){
        cost = (100 * 1.23)+((units - 100) * 1.14);
    }
    else{
        cost = 237 + ((units- 200) * 1.08);
    }
    return cost;
}

/**Question:Write a function, GolfName, that is given an integer value for the number of strokes above or below par. 
 * The function will return a string value for the golf name of the that score.

Your function will return the following values depending on the number of strokes: 
   -2 - "EAGLE"
   -1 - "BIRDIE"
   0 - "PAR"
   1 - "BOGIE"
   2 - "DOUBLE BOGIE"
   3 - "TRIPLE BOGIE"
  otherwise return "NO COMMENT"
 */
//#3: DONE
string GolfName(int strokes){
    if(strokes == -2){
        return "EAGLE";
    }
    else if(strokes == -1){
        return "BIRDIE";
    }
    else if(strokes == 0){
        return "PAR";
    }
    else if(strokes == 1){
        return "BOGIE";
    }
    else if(strokes == 2){
        return "DOUBLE BOGIE";
    }
    else if(strokes == 3){
        return "TRIPLE BOGIE";
    }
    else{
        return "NO COMMENT";
    }
}

/**Question:Write a function named PaintHouse to calculate the cost to paint a house.  
 * The function will take an integer for the width, the depth of the house, and the number of windows/doors in the house. 
 * The function returns a floating point value for the total cost of the work.

Total cost of painting of house = cost of painting wall + cost of painting doors and windows

The cost to paint the windows and doors is $6.75 per door/window

The cost of painting the walls is calculated as the perimeter of house times the cost per feet.
    Perimeter of house = 2 * (width + depth)
Painting cost for first 100 feet of the house perimeter is $8 per feet
Painting cost for next 100 feet of the house perimeter is $10 per feet
Painting cost for house perimeter above 200 feet is $15 per feet

For any invalid parameter value, return -1
 */
//#4:DONE
float PaintHouse(int width, int depth, int wd){
    float t_cost;
    float wall;
    int feet = width + depth;
    float peri = 2 * feet;
    float windoor = 6.75 * wd;
    
    if(width < 0 || depth < 0 || wd < 0){
        return -1;
    }
    else if(peri <= 100){
        wall = 8*peri;
    }
    else if(peri > 100 && peri <= 200){
        wall = ((peri - 100) * 10) + 800;
    }
    else{
        wall = ((peri - 200) * 15) + 1800; 
    }
    t_cost = wall + windoor;
    return t_cost;
}

/**Question:Write a function named TuitionCost to calculate the cost of a student's tuition. 
 * The function will take an integer for the number of units and a floating point value for the cost per unit. 
 * The function will return a floating point value for the total cost of tuition. 

Calculate the cost as units times the per unit cost: 
                 cost = units * cost per unit 

If the number of units is greater than 16, then cost is calculated as:
                 cost = 16 * cost per unit + ((number of units over 16) * (cost per unit * 1/2))

Return -1 if any parameter is invalid.
 */
//#5:DONE
float TuitionCost(int units, float c_unit){
    float cost;
    if(units < 0 || c_unit < 0){
        return -1;
    }
    else if(units <= 16){
        cost = units * c_unit;
    }
    else if(units > 16){
        cost = 16 * c_unit + ((units - 16)* (c_unit * 0.5));
    }
    return cost;
}

/**Question:Complete the function IsPrime, which returns true if the integer number given is a prime number and false otherwise.  
 * A prime Number can be divided evenly only by 1, or itself. A prime number must be a whole number greater than 1. 

Example: 5 can only be divided evenly by 1 or 5, so it is a prime number. 

But 6 can be divided evenly by 1, 2, 3 and 6 so it is NOT a prime number.
 */
//#6:DONE
bool IsPrime(int num){
    if(num == 1 || num < 0){
        return false;
    }
    else{
        bool f = true;
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            f = false;
            break;
        }
    }
    return f;
    }
}

/**Question:Write a function, CountVowels, that takes a string as input and count the number of vowels (a,e,i,o,u either upper or lower case) alphabetic characters. 
 * The function returns an integer value for the number of vowels.
Example:
Calling function with a string "One1, Two2", should return 3.

Edge Cases:
If the string is empty, return -1
If there are no vowel characters in the string, return -2
 * 
 */
//#7:DONE
int CountVowels(string vowels){
    int amount = 0;
    if(vowels==""){
            return -1;
    }
    for(int i = 0; i < vowels.length(); i++){
        if(vowels[i]=='a' || vowels[i]=='e' || vowels[i]=='i' || vowels[i]=='o' || vowels[i]== 'u'
        || vowels[i]=='A' || vowels[i]=='E' || vowels[i]=='I' || vowels[i]=='O' || vowels[i]=='U'){
            amount++;
        }
    }
    if(amount == 0){
        return -2;
    }
    else{
     return amount;
    }
}

/**Question:Write a function, Is_All_Lower, that takes a string as input and returns true if all the 
 * alphabetic characters in the string are lowercase alphabetic characters. The function returns false otherwise.

Example:

Calling function with string "onetwo", should return true.
Calling function with string "onEtwo", should return false.
 * 
 */
//8:NOT DONE
int Is_All_Lower(string lower){
    for(int i=0;i<lower.length();i++){
        if(lower[i]>96 && lower[i]<123){
        return false;
        }
    }
    return true;
}
/**Question:Write a function, Is_All_Alpha, that takes a string as input and returns true if all the characters are alphabetic characters in the string. 
 * The function returns false otherwise.
Example:

Calling function with string "ONETWO", should return true.
Calling function with string "One two", should return false.
Calling function with string "one2", should return false.
 */
//#9:


/**Question:Write a function, Print_NON_Letters, that takes a string as input and only prints the NON-alphabetic characters. 
 * The function does not return a value.
Example:

If the string is empty, print "NULL"
If there are no NON-alphabetic characters in the string, print "-2"

 */
//#10:NOT DONE
string Print_NON_Letters(string non){
    if(non == ""){
        cout<<"NULL";
    }
    for(int i = 0; i < non.length(); i++){
        if(non[i]<96 && non[i]>123){
            i++;
        }
        else{
            cout<<"-2";
        }
    }
}

}

int main(){
   int a = 5;
   int b = 2;
   float c = a/b;
   cout<<c<<endl;
}
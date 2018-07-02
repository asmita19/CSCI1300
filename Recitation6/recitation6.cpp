//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Recitation 6

#include <iostream>
#include <string>
using namespace std;

/**Algorithm:arrayOne - array of integers with 49 elements
     arrayTwo - floating point values, one for each practicum
     arrayTri - booleans for attendance in each of the 14 recitations
     arrayFor - hold names for each month
 */
//Problem1:
int arrayOne[49];
float arrayTwo[4];
bool arrayTri[14];
string arrayFor[12];

/**Algorithm: prints all the values in an array, one per line. 
 * Function will take two parameters, the array and the array length. 
 */
//Problem2:
void printValues(int myArray[], int length){
    for(int i = 0; i < length;i++){//for loop to ieterate through the length 
        cout<<myArray[i]<<endl;//outputs the array given by user with i
    }
}

/**Algorithm:calculates the sum of the elements in an integer array. 
 * Function takes two parameters, an integer array and the array length (in this order). 
 * Returns the sum of the elements as an integer.
 */
//Problem3:
int getArraySum(int myArray[], int length){
    int sum = 0;
    for(int i = 0; i < length; i++){
        sum+=myArray[i];//sum = sum + myArray[i]
    }
    return sum;
}

/**Algorithm: replaces each element except the first and last by the larger of its two neighbors. 
 * Function takes two parameters, an integer array and the array length (in this order). 
 * Function doesn't return or print anything.
 */
//Problem4:
void replaceNums(int myArray[], int length){
    int arr[length];
    int i;
    for(i = 1; i < length-1; i++){
        if(myArray[i-1] > myArray[i+1]){
            arr[i] = myArray[i-1];
        }
        else{
            arr[i] = myArray[i+1];
        }
    }
    for(int i = 1; i < length-1; i++){
        myArray[i] = arr[i];
    }
    
}
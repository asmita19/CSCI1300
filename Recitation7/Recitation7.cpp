//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Recitation 7

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


/**Algorithm:function Split(...) that is given a string, a separator character, an array to fill and the max number of elements 
 * in the array as parameters and returns an integer result.  
 * The function will separate each substring of the given string between separator characters and place it in the array.  
 * The function returns the number of substrings extracted.
 */
 
//Problem1:
int Split(string words, char delimiter, string fill[], int size){
    int n = 0;
    int count = 0;
    int ccount = 1;
    size = words.length();//size = the length of the string words from function parameter
    if(size == 0){//if the length of the string words parameter is empty
        ccount -=  1;
    }
    else{
        for(int i = 0; i < words.length(); i++){
            if(words[i] == delimiter){
                fill[n] = words.substr(count, i - count);
                ccount++;
                n+=1;
                count= i+1;
            }
            if(i == (size - 1)){
                fill[n] = words.substr(count, i + 1);
            }
        }
    }
    return ccount;
}

/**Algorithm:Function GetScores(...) that is given a string,  
 * an int type array to fill and the max number of elements in the array as parameters and returns an integer result.  
 * The function will find each substring of the given string separated by space characters and place it in the array.  
 * The function returns the number of integers extracted.
 * Calls the split function from above.
 */
 
//Problem2:
int GetScores(string str, int values[], int max){
    int count = 0;
    int start = 0;
    if(str == ""){
        return 0;
    }
    str = str + ' ';//adds the parameter str to  itself and a space. 
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            int x = stoi(str.substr(start, i - start));//converts string to integer.
            values[count] = x;
            count++;//increments count
            start = i + 1;
        }
    }
    return count;
}

/**Algorithm:Function fillMatrix which takes 2 parameters- an int type 2-D array 
 * and number of rows. There will always be 4 columns in the array. 
 * The function will fill the array such that each element in the array is the sum of its indexes.
 */
 
//Problem3:
void fillMatrix(int matrix[][4], int nrows){
    for(int i = 0; i < nrows; i++){//for loop of rows
        for(int j = 0; j<4; j++){//for loop for columns
            matrix[i][j] = i+j;//combines the cloumns and rows together
        }
    }
}

/**Algorithm:function floodMap(...) which takes three arguments, 
 * a two dimensional array of doubles indicating the height of the terrain at a particular 
 * point in space (assume that there are 4 columns), an int indicating the number of rows in the map, 
 * and a double indicating the current water level. The function should print out a "map" 
 * of which points in the array are below the water level. 
 * In particular, each position at or below the water level will be represented with a "*" 
 * and each position above the water level will be represented with a "_".
 */
 
//Problem4:
void floodMap(double height[][4], int rows, double cwl){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < 4; j++){
            if(height[i][j] <= cwl){
                cout<<"*";
            }
            else{
                cout<<"_";
            }
        }
        cout<<"\n";//outputs a new line after the inner for loop
    }
}


//main function to test the previous functions:
int main(){
    string words[10];
    cout<<"Split: "<<Split("cow/chicken/fish", '/', words[], size);
    cout<<"Fill Matrix: "<<fillMatrix([3][4], 5)<<endl;
    cout<<"Flood map: "floodMap([5][4], 7, 8.456)<<endl;
}
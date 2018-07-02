//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Project: Users

#include <iostream>
#include <string>
using namespace std;

/* Algorithm: Separate each substring of the given string between separator characters and place it in array
* 1. Declare array size counter and string to use for storing extracted substrings.
  2. Use for loop to go through string. If a character is not the last one or the separator character, then add it to the substring. Otherwise, put the substring into the array.
  3. Add one to array size for each time a string is put into the array.
* Input: string, separator (character type), array to fill (string type), max number of elements (integer type)
* Output: nothing
* Return: number of substrings extracted (integer type)
*/


int Split(string str, char separator, string newArray[], int maxElements){
  newArray[maxElements]; //array of maximum element size
  int arraySize=0; //start array size counter at 0
  string filler; //string to store extracted substrings
  for (int i=0; i < str.length(); i++) //for loop to go through string
  {
    if (str[i] != separator) //character in string is not separator
    {
      filler= filler + str[i]; //add to substring
    }
    if ((str[i] == separator) || (i == str.length()-1)) //character is a separator or is last character in string
    {
      newArray[arraySize]= filler; //put substring into new array
      arraySize++; //add one to array size
      filler= ""; //clear out the old extracted substring
    }
  }
  return arraySize;
}

// int main()
// {
//   string words[10];
//   int size = 10;
//   cout << Split("cow/chicken/fish", '/', words, size) << endl; //test case 1, expected output: 3
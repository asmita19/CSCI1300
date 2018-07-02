//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Homework 7 Pt.1

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

/**Algorithm:function bubbleSort that takes an array of integers and the number of elements in the array. 
 * Parameters: an interger array and integer size
 * Function sorts the array using bubble sort and print the number of comparisons and swaps (a "swap" is whenever two numbers change places).
 * implement the bubble sort algorithm with a flag.
 * Function should not return anything but should display the sorted array, number of comparisons and the number of swaps executed.
*/
//Problem #1
void bubbleSort(int array[], int size){
    bool flag = false;
    int temp = 0;
    int swap = 0;
    int comp = 0;
    for(int i = 0; i < size && !flag; i++){//for loop to count ith element 
        flag = true;
        for(int j= 0; j< size-1-i; j++){
            if(array[j] > array[j+1]){//if ith element of array is greater than i+1 element 
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swap++;
                flag = false;
            }
            comp++;
        }
   }
    cout<< "Bubble Sort: " << endl;
    for (int i=0; i< size; i++){
        cout <<array[i] << " ";
    }
    
    cout<<endl<<"Number of comparisons: "<<comp<<endl;
    cout<< "Number of swaps: "<<swap<<endl;
}
 
/**Algorithm:function cocktailSort that takes an array of integers and the number of elements in the array. 
 * function sorts the array using cocktail sort and print the number of comparisons and swaps (a "swap" is whenever two numbers change places).
 * implement the cocktail sort algorithm with a flag.
 * Function should not return anything but should display the sorted array, number of comparisons and the number of swaps executed.
*/
//Problem2:
void cocktailSort(int array[], int size){
    bool flag = true;
    int temp = 0;
    int swap = 0;
    int comp = 0;
    int start = 0;
    int end = size - 1;
    while (flag && start < end){
        flag = false;
        for(int j= start; j< end; ++j){
            comp++;
            if(array[j] > array[j+1] ){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = true;
                swap++;
            }
        }
        if(!flag){
            break;
        }
        flag = false;
        --end;
        for(int i = end - 1; i >= start; --i){//for loop to go backwards
            comp++;
            if(array[i] > array[i+1]){
                temp = array[i + 1];
                array[i+1] = array[i];
                array[i] = temp;
                swap++;
                flag = true;
            }
        }
        
        ++start;
    }
    cout<<"Cocktail Sort: "<< endl;
    for (int i = 0; i < size; i++){
        cout <<array[i] << " ";
    }
    cout<<endl<<"Number of comparisons: "<<comp<<endl;
    cout<<"Number of swaps: " <<swap<<endl;
}
 
//main function:
//Bubble test:
int L = 5;
int A[L] = {55, 51, 51, 87, 8};
bubbleSort(A, L);

int L = 5;
int A[L] = {0,1,2,3,4};
bubbleSort(A, L);

//Cocktain test:
int L = 5;
int A[L] = {0,0,0,0,0};
cocktailSort(A, L);

int L = 5;
int A[L] = {0,1,2,3,4};
cocktailSort(A, L);
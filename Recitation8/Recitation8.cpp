//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Recitation 7

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/**Algorithm: Function checkFile that opens up a file. 
 * The function takes one parameter, the name of the file filename. 
 * The function should return true if the file was open successfully 
 * otherwise it should return false.
*/
 

//Problem1:
bool checkFile(string filename){
    ifstream filenames;
    filenames.open(filename);
    if(filenames){
        return true;
    }
    else{
        return false;
    }
}
 
/**Algorithm: Function fileLoadWrite that opens a file and writes to it the squares of the numbers 1-10, each on its own line. 
 * The function takes one parameter, the name of the file filename.
 * It should open the file in write mode and write 10 lines to the file, each containing the 
 * --square of the number line it is on (e.g. line 1 will contain 1, line 2 will contain 4, etc.).
 * The function should close the file and return 0 if the file was opened successfully.
 * Otherwise it should return -1. 
*/

//Problem2:
int fileLoadWrite(string filename){
    ofstream myfile;
    myfile.open(filename);
        if(myfile.is_open()){
            for(int i = 1; i <= 10; i++){
                myfile<<i*i<<"\n";
            }
            return 0;
        }
        else{
            return -1;
        }
}


/**Algorithm: Function fileLoadRead that reads a file. 
 * The function takes one parameter, the name of the file filename.
 * The function returns the number of lines in the file. 
 * If the file was not opened successfully, return -1.
 * If the file exists but is empty (contains no non-newline characters), return 0.
 * If the file exists and is not empty, return the number of lines. Include all the lines in your count, even those that are blank.
*/
//Problem3:
int fileLoadRead(string filename){
    int lines = 0;
    ifstream myfile;
    myfile.open(filename);
    string line;
    if(myfile.is_open()){
        while(getline(myfile, line)){
            lines++;
        }
    }
    else{
        lines = -1;
        myfile.close();
    }
    return lines;
}


/**Algorithm: Function getLinesFromFile that reads from a file and stores its content in an array. 
 * The function takes three parameters: a string fileName, a string array wordArray, an integer sizeArray.
 * getLinesFromFile should open the file in read mode, read each line, store each line in the array. 
 * The function should return the number of lines placed into the array.
 * If any empty lines are encountered, those should not count towards the count of the number of lines and should not be added to the array.
 * If the file does not exist, return -1.
*/
//Problem4:
int getLinesFromFile(string filename, string wordArray[], int sizeArray){
    string line;
    int index = 0;
    ifstream file(filename);
    if(!file.good()){//if the file isn't 'good' then it retirns -1;
        return -1;
    }
    while(getline(file, line) && index < sizeArray){
        if(line.length() > 0){
            wordArray[index] = line; 
            index++;
        }
        
        
    }
    return index;
}


/**Algorithm:
*/
//Problem5:
void saveData(string fileName, string data[], int n, int size) {
    double sum = 0; 
    for(int i = 0; i < n; i++){
            // myFile<</i
        sum += stod(data[i]); 
    }
    ofstream output(fileName); 
    if(n > 0) {
        output << "Name: " << data[n] << endl; 
        output << "Avg: " << sum / n << endl; 
    }
    output.close(); 
   
}

//main function:
int main(){
    string filename;
    cout<<checkFile(file_name);
    
    string filel;
    cout<<fileLoadwrite(file_name);
    
    string filer;
    cout<<fileLoadRead(file_name);
    
    string filen;
    string wA[];
    int sA;
    cout<<getLinesFromFile(filename, wA[], 4);
    
    string fil;
    string data[];
    int n;
    int size;
    cout<<saveData(file_name, data[], 2, 5);
}
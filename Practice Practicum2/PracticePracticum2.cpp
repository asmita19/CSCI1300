#include <iostream>
#include <string>
#include <math.h>
using namespace std;


/**Algorithm:
 */
//1: DONE 
void printAsterisks(){
    for (int row =1; row <= 3; row++)   //this counts the rows which is 3
    {
        for (int column = 1; column <5; column ++)// and inside that row make 4 columns
        {
            cout << "*"; //print 4 asterisk in each row. so there are 3 rows and 4 columns 
        }
        cout << endl; //once that asterisk is made in first row go to second row do the same thing until there is three rows of four column of asterisk
    }
}

/**Algorithm:printPlus() that takes in no parameters nor returns any value, but prints 4 rows of 3 plus sign each. 
 * HINT: Use nested loops.  :)
 */
//2: DONE 
void printPlus(){
    for (int rows= 1; rows <=4; rows++)//count rows for outside loop
    {
        for (int column=1; column <=3; column++)//count column inside first row. so starts from first row, print columns one
        {
            cout <<"+"; //prints plus until it gets to three
        }
        cout <<endl;//ends line goes to next row and repeats until it gets all 4 rows
    }
}

/**Algorithm: printOddPattern() that takes in no parameters nor returns any value, and prints 3 rows and 5 columns as follows:
 *      asterisks('*') in even columns, dollar('$') in odd columns.
 * HINT: Use nested loops.  :)
 */
//3: DONE 
void printOddPattern(){
    for(int row = 1; row <= 3; row++){
        for(int col = 1; col <=5; col++){
            if(col % 2 == 0){
                cout<<"*";
            }
            else{
                cout<<"$";
            }
        }
        cout<<endl;
    }
}

/**Algorithm:MultiplicationTableFor. 
 * This function will print a multiplication table for 1, 2, 3, 4, and 5 using only for loops 
 * This function does not take any parameter and does not return anything.
 */
//4: DONE 
void MultiplicationTableFor(){
    for(int i = 1; i < 6; i++){
        for(int j = 1; j <= i; j++){
            cout<<i*j<<" ";
        }
        cout<<endl;
    }
}

/**Algorithm:MultiplicationTableWhile. 
 * This function will print a multiplication table for 1, 2, 3, 4, and 5 using only while loops . 
 * For loops have been disabled for this question.
 * This function does not take any parameter and does not return anything.
 */
//5: DONE 
void MultiplicationTableWhile(){
    int i = 0;
    while(i < 5){
        i++;
        int j = 0;
        while(j < i){
            j++;
            cout<<i*j<<" ";
        }
        cout<<endl;
    }
}

/**Algorithm:validateEmail that takes one parameter: 
 *      a string for an email. 
 * The function returns true if the email has exactly one '"@" and one ".com" and false otherwise.
 * You must use a for loop to traverse the string (while loops have been disabled for this question)
 */
//6: DONE 
bool validateEmail(string email) //data type is bool with string parameter
{
    int count = 0; //int count variable to count how many time @ occured
     int dotcom = 0; //setting dotcom to 0  
    for (int i=0; i<email.length(); i++) //goes through ith index of string
    {
        char a = email[i]; //set chat to a and make it equal to ith index of string
        if(a == '@')//if ith index of string is @
        {
        count ++;//start counting
        }
    }
    //to find .com i need to use substring.
    for(int j=0; j< email.length() - 3; j++)//for loop to go trough each index of the string-3. this is because you want it to stop before .com
    {
        if (email.substr(j, 4)== ".com")//if substring has .com
        {
            dotcom++; //count the substring
        }
    }
    if(count == 1 && dotcom == 1)//if @ and .com occurs only 1 times, return true else return false
    {
        return true;
    }
    return false;
}

/**Algorithm:
 */
//7: DONE 
bool validateEmail(string email)//setting up function with strin parameter
{
    int cCount = 0; //int charactercount;
    int dotcom = 0; //setting up variable that counts substrings;
    int i=0;
    while(i< email.length())//while ith index is less than string length
    {
        char a = email[i];//setitng character variable a to be the ith index of the string
        if (a == '@') //if ith index is @
        {
            cCount++;//start counting
        }
        i++;
    }
    //now we check substring
    int j=0; //setting variable called j to be 0
    while(j < email.length()-3)//if lengthofstring-3(go through each index put out 4 length,go to next index pulls out 4 chunk of character) until it finds .com
    {//count substring occurence
        if(email.substr(j,4)== ".com"){
                dotcom++;
            }
        j++;
    }
    if(cCount == 1 && dotcom == 1){
        return true;
    } 
}

/**Algorithm:countPrimes that takes in two parameters: an int array and the size of the array. The function returns the count of the number of prime elements in the array.
 * int countPrimes(int array[], int size)
 * Given array: {1, 2, 3, 4, 5, 7, 10, 12}
 *      Expected return: 4
 * Explanation: The primes are 2, 3, 5, and 7; consequently, the function returns a count of 4.
 * Hint: Create a function IsPrime to call from within your countPrimes function.
 */
//8: DONE 
//this:
int countPrimes(int array[], int size){
    int prime = 0;
    for(int i = 0; i < size; i++){
        int count = 0;
        for(int j = 2; j <= array[i]; j++){
            if(array[i] % j == 0){
                count++;
            }
        }
        if(count == 1){
            prime++;
        }
    }    
    return prime;
}

/**Algorithm:
 */
//or this:
bool IsPrime(int num){
    if(num == 1 || num <= 0){
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

int countPrimes(int array[], int size){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(IsPrime(array[i])){
            count++;
        }
    }
    return count;
}

/**Algorithm:printTotalMedals that takes an array for olympic sports and arrays for gold, silver, and bronze medals and prints the total number of medals by discipline.
 * Your function should take 5 parameters:
         * an array of strings disciplines
         * an array of ints representing the number of gold medals
         * an array of ints representing the number of silver medal
         * an array of ints representing the number of bronze medals 
         * an integer size for the size of the arrays 
 * Edge cases:
 *      If the size < 1, print "Invalid size. Size must be at least 1."
 */
//9: DONE 
void printTotalMedals(string discplines[], int gold[], int silver[], int bronze[], int size){
    if(size < 1){
        cout<<"Invalid size. Size must be at least 1.";
    }
    else{ //else the for loop traverses through the arrays and prints medals recieved by each discipline.
        for(int i = 0; i < size; i++){
            int totalMedals = gold[i] + silver[i] + bronze[i];//created an integer named totalMedals it stores the sum of these three medals.
            cout<<discplines[i]<<": "<<totalMedals<<endl;//disciplines and totalMedals values are printed, through iteration.
        }
    }
}

/**Algorithm:function that takes in a string array and its size and returns the number of times given character appeared in the whole array.
 * int countCharacter(string array[ ], int size, char ch)
 * Example:
 *      array = {"elephant", "english", "elegant", "america", "united", "apple"}
 *      ch = 'e'
 *      return value: 8
 */
//10: DONE 
int countCharacter(string array[ ], int size, char ch){
    int ccount = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < array[i].length(); j++){
            if(array[i][j] == ch){
                ccount++;
            }
        }
    }
    return ccount;
}

/**Algorithm: PrintStudents, which takes a string input filename and an integer minimum score value and a string output file name as a parameters.
 * The function will read the student scores and names from the file and output the names of the students with scores greater than or equal to the value given.
 * This function returns the integer number of entries read from the file.
 * If the input file cannot be opened, return -1 and do not print anything to the file.
 * Read each line from the given filename, parse the data, process the data, and write the required information to the file. 
 * Each line of the file contains 
 *      <FIRST-NAME LAST-NAME>, <SCORE>,  <SUBJECT> .  
 *      Read and parse the data, then write to the output file the names and classes for scores matching the criteria. 
 */
//11:DONE
int PrintStudents(string inputfile, int minscore, string outputfile){
    int count = 0;
    string s = "";
    int size = 3;
    string words[size];
    ifstream myfile(inputfile);
    if(!myfile.is_open()){
        return -1;
    }
    ofstream secfile;
    secfile.open(outputfile);
    while(getline(myfile, s)){
        split(s, ',', words, size);
        count++;//counts the lines read so far 
        if(stoi(words[1]) >= minscore){
            secfile<<words[0]<<','<<words[2]<<endl;
        }
    }
    return count;
}

/**Algorithm: an array of integers and the size of the array, 
 * a function findDuplicate which prints the duplicate element from the array.
 * The array consists of all distinct integers except one which is repeated. 
 * Finds and prints the repeated number.  
 * If no duplicate is found, the function prints -1.
 * void findDuplicate (int [ ], int)
 * Example 1: 
     Given array: {2,3,5,6,11,20,4,8,4,9} 
     Output: 4 
 * Example 2: 
     Given array: {1,3,5,6,7,8,2,9} 
     Output: -1
 */
//13:DONE
void findDuplicate(int array[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i+1; j< size; j++){
            if(array[i] == array[j]){
                cout<<array[j];
                return;
            }
        }
    }
    cout<< -1;
    return;
}

/**Algorithm:
 */
//12:
int writeCountryDensity(string inputfile, int maxdensity, string outputfile){
    ifstream myfile;
    myfile.open(inputfile);
    string line = "";
    int size = 3;
    int count = 0;
    string word[size];
    if(!myfile.is_open()){
        return -1;
    }
    ofstream secfile;
    secfile.open(outputfile);
    while(getline(myfile, line)){
        split(line, ',', word, size);
        if(stof(word[1])/stof(word[2]) <= maxdensity){
            count++;
            secfile<<word[0]<<", "<<stof(word[1])/stof(word[2])<<endl;
        }
    }
    return count;
}

/**Algorithm:
 */
 //main function to test:
int main(){
    int firsta[5] = {4, 2, 6, 0, 1};
    int s[5] = {4, 2, 1, 0, 3};
    for(int i = 4; i >= 0; i--){
        cout<<firsta[s[i]]
    }
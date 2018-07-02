//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Homework 3: Problem 1

#include <iostream>
#include <string>
using namespace std;


 
/**Algorithm:Function for the story one two and three
 * initializes the variables as strings, asks the user for inputs for noun, occupation, animal name, and place.
 * Outputs the story with the user inputs in each story. 
 */
//Part1:
void story1(){
    string noun;
        cout<<"Enter a plural noun: "<<endl;
        cin>>noun//noun would be the variable the user inputs used in the story outputed later.
    string occupation;
        cout<<"Enter an occupation: "<<endl;
        cin>>occupation;
    string animal;
        cout<<"Enter an animal name: "<<endl;
        cin>>animal;
    string place;
        cout<<"Enter a place: "<<endl;
        cin>>place;
    
    cout<<"In the book War of the "<<noun<<", the main character is an anonymous "<<occupation<<" who records the arrival of the "<<animal<<"s in "<<place<<"."<<endl;
}

void story2(){
    string name;
        cout<<"Enter a name: "<<endl;
        cin>>name;
    string state;
        cout<<"Enter a state/country: "<<endl;
        cin>>state;
    
    cout<<name<<", I've got a feeling we're not in "<<state<<" anymore."<<endl;
}

void story3(){
    string fname;
        cout<<"Enter a first name: "<<endl;
        cin>>fname;
    string relative;
        cout<<"Enter a relative: "<<endl;
        cin>>relative;
    string verb;
        cout<<"Enter a verb: "<<endl;
        cin>>verb;
    
    cout<<"Hello. My name is "<<fname<<". You killed my "<<relative<<". Prepare to "<<verb<<"."<<endl;
}

/**Algorithm: Menu function for the three stories. 
 * initializes the choice as string. Outputs to the user to choose which story to pick
 * -if user inputs: 1, 2, or 3, the function calls the story the user called. 
 * -if user inputs "q" the function outputs "goodbye" and the game is over. 
 * 
 */
//Part2:
void menu(){
    string choice;
    cout<<"Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: "<<endl;
    cin >> choice;
    while (choice!="q")//while the user doesn't input "q" the following conditions are ran.
    {
        if (choice == "1")
            {
                story1();
                cout<<"Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: "<<endl;
                cin >> choice;
            }
        else if (choice == "2")
            {
                story2();
                cout<<"Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: "<<endl;
                cin >> choice;
            }
        else if (choice == "3")
            {
                story3();
                cout<<"Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: "<<endl;
                cin >> choice;
            }
        else
            {
                cout<<"Valid choice not selected."<<endl;
                cout<<"Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: "<<endl;
                cin >> choice;
            }
    }
    cout<<"good bye";//after while loop, and the conditions have been met, computer outputs "goodbye."
}
/**Algorithm:Main function
 * Calls the meanu function to test the code. 
 */
int main(){
    menu();
return 0;
}
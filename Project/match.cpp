//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Project: match.cpp
//Refrence: Push_back: http://www.cplusplus.com/reference/vector/vector/push_back/
        // Vectors: https://www.youtube.com/watch?v=iPlW5tSUOUM
        // sstream: https://stackoverflow.com/questions/20594520/what-exactly-does-stringstream-do 
        // objects in class: https://www.geeksforgeeks.org/c-classes-and-objects/ 
        //ofstream: https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp10_IO.html
        //reading and writing to file: https://www.youtube.com/watch?v=Iho2EdJgusQ
        //debugging errors: stackoverflow
        

using namespace std;

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include "User.cpp"
#include "Split.cpp"
#include "Foundation.cpp"
#include "Concealer.cpp"


int main(){
        foundation myfoundation;
        Concealer myConcelaer;
        User myUser;
        
        myfoundation.loadOilyFoundationData();
        myfoundation.loadDryFoundationData();
        myfoundation.loadCombinationFoundationData();
        
        myConcelaer.loadOilyConcealerData();
        myConcelaer.loadDryConcealerData();
        myConcelaer.loadCombinationConcealerData();
        
        if(myfoundation.loadDryFoundationData()==-1 || myfoundation.loadOilyFoundationData()==-1 || myfoundation.loadCombinationFoundationData()==-1){
            cout<<"Was not able to open!"<<endl<<"Could not find the foundation files."<<endl;
        }
        if(myConcelaer.loadCombinationConcealerData()==-1 || myConcelaer.loadDryConcealerData()==-1 || myConcelaer.loadOilyConcealerData()==-1){
            cout<<"Was not able to open!"<<endl<<"Could not find the foundation files."<<endl;   
        }
        else{ //launch is sucessful
            int userIndex = 0;
            string choice;
            cout << "Data Loaded successfully!" << endl;  //print "Data Loaded successfully!"
            cout << "Welcome to the Match, What is your name?:" << endl; //print "Welcome to the Library, What is your name?:"
            string userName; //username
            getline(cin, userName); //get user entry
            while (userName=="") //blank entry
              {
                cout << "You provided an empty user name, Please provide a valid user name to login or register:" << endl; //print "You provided an empty user name, Please provide a valid user name to login or register:"
                cout << "Enter your name again:" << endl; //print "Enter your name again:"
                getline(cin, userName); //get username from user
              }
              
            if (myUser.searchForUser(userName)){ //search for the user in the list of users in the library
                userIndex=myUser.findUserIndex(userName); //find user index and set user index to variable
                cout << "Welcome back, " << userName << endl; //user is found, print "Welcome back, <username>"
            }
            else{//user not in list of users in library
                userIndex=myfoundation.addNewUser(userName); //create a new user and add it to the array of user for the library object, set new user index to variable
                cout << "Welcome to the Match, " << userName << endl; //print "Welcome to the Library, <username>"
            }
        
            cout<<"What would you say your skin type is, (o)ily, (d)ry or (c)ombination?"<<endl<<"You could also (q)uit to exit or (a)dd to the list of foundations and concelear.";
            getline(cin, choice);
            while(choice == ""){
                cout << "You didn't choose the correct choices, Please provide a valid choice:"<<endl; //print "You provided an empty user name, Please provide a valid user name to login or register:"
                cout << "What would you say your skin type is, (o)ily, (d)ry or (c)ombination?"<<endl<<"You could also (q)uit to exit or (a)dd to the list of foundations and concelear."<<endl; 
                getline(cin, choice); //get username from user
            }
            if(choice == "q" || choice =="Q"){
                myfoundation.saveFoundationData();
                myConcelaer.saveConcealerData();
                break;
            }
            while(choice != "q" || choice != "Q"){ //while user doesn't quit the program
                
                if(choice == "o" || choice == "O"){
                    cout<<"The foundations that would match you are "<<myUser.getoilyFoundationAt().oilyF[0]<<" and the price of it is $"<<myUser.getoilyFoundationAt().oilyF[1]<<endl;
                    cout<<"The concealers that would match you are "<<myUser.getoilyConcealerAt().oilyC[0]<<" and the price of it is $"<<myUser.getoilyConcealerAt().oilyC[1]<<endl;
                } 
                else if(choice == "d" || choice == "D"){
                    cout<<"The foundations that would match you are "<<myUser.getdryFoundationAt().dryF[0]<<" and the price of it is $"<<myUser.getdryFoundationAt().dryF[1]<<endl;
                    cout<<"The concealers that would match you are "<<myUser.getdryConcelaerAt().dryC[0]<<" and the price of it is $"<<myUser.getdryConcelaerAt().dryC[1]<<endl;

                }
                else if(choice == "c" || choice == "C"){
                    cout<<"The foundations that would match you are "<<myUser.getcombinationFoundationAt().comboF[0]<<" and the price of it is $"<<myUser.getcombinationFoundationAt().comboF[1]<<endl;
                    cout<<"The concealers that would match you are "<<myUser.getcombinationConcelaerAt().comboC[0]<<" and the price of it is $"<<myUser.getcombinationConcelaerAt().comboC[1]<<endl;
                }
                while(choice == "a" || choice == "A"){
                    ofstream myfoundation;
                    ofstream myConcealer;
                    cout<<"Would you like to add a oilyF, dryF, or combinationF, foundation, or add a oilyC, dryC, or combimationC, concealer?"<<endl;
                    getline(cin, choice);
                    if (choice == "oilyF"){
                        cout<<"Please enter the foundation name and price with a space in between!"<<endl;
                        getline(cin, choice);
                        myfoundation.open("oilyFoundation.txt");
                        myfoundation.push_back(choice);
                        myfoundation.close();
                    }
                    else if(choice == "dryF"){
                        cout<<"Please enter the foundation name and price with a space in between!"<<endl;
                        getline(cin, choice);
                        myfoundation.open("dryFoundation.txt");
                        myfoundation.push_back(choice);
                        myfoundation.close();
                    }
                    else if(choice == "combinationF"){
                        cout<<"Please enter the foundation name and price with a space in between!"<<endl;
                        getline(cin, choice);
                        myfoundation.open("combinationFoundation.txt");
                        myfoundation.push_back(choice);
                        myfoundation.close();
                    }
                    else if(choice == "oilyC"){
                        cout<<"Please enter the concealer name and price with a space in between!"<<endl;
                        getline(cin, choice);
                        myConcealer.open("oilyConcealer.txt");
                        myConcealer.push_back(choice);
                        myConcelaer.close();
                    }
                    else if(choice == "dryC"){
                        cout<<"Please enter the concealer name and price with a space in between!"<<endl;
                        getline(cin, choice);
                        myConcealer.open("dryConcealer.txt");
                        myConcealer.push_back(choice);
                        myConcelaer.close();
                    }
                    else if(choice == "comboC"){
                        cout<<"Please enter the concealer name and price with a space in between!"<<endl;
                        getline(cin, choice);
                        myConcealer.open("combinationConcealer.txt");
                        myConcealer.push_back(choice);
                        myConcelaer.close();
                    }
                    else{
                        cout<<"You didn't enter a correct response."<<endl<<"Would you like to add a oilyF, dryF, or combinationF, foundation, or add a oilyC, dryC, or combimationC, concealer?"<<endl;
                        getline(cin, choice);
                    }
                }
                if(choice != "A" || choice != "a" || choice != "O" || choice != "o" || choice != "D" || choice != "d"){
                    cout<<"You did not pick the correct choices. PLease input the correct choices."<<endl;
                    cout<<"What would you say your skin type is, (o)ily, (d)ry or (c)ombination? Or Q to quit"<<endl;
                    getline(cin, choice);
                }
            }
        }
}
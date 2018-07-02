//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Project: foundation.cpp

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class foundation{
    private:
        User username[1000];
        string oilyF[1000];
        string dryF[1000];
        string comboF[1000];
    public:
        foundation();
        foundation(string kind, int paisa);
        bool searchForUser(string Uname);//Should I put these three in user.cpp or on here?
        int findUserIndex(string pName);
        int addNewUser(string newUsername);
        
        int loadOilyFoundationData();
        int loadCombinationFoundationData();
        int loadDryFoundationData();
        void saveFoundationData();
};
foundation::foundation(){}

bool foundation::searchForUser(string Uname){//search for the user
    User myUser;
    bool userExist = false;//sets flag as false 
    for(int i = 0; i < Uname.length(); i++){
        if((Uname[i] < 91) && (Uname[i] > 64)){
            Uname[i] = Uname[i] + 32;
            }
         }
    for(int j = 0; j < 1000; j++){
        if(Uname == username[j].getName()){
            userExist = true;
        }
    }
    return userExist;
}
int foundation::findUserIndex(string pName){
    User myUser;
    int previousUser = 0;
    for(int i = 0; i < pName.length(); i++){
        if(pName == username[i].getName()){
            previousUser = i;
        }
    }
    return previousUser;
}
int foundation::addNewUser(string newUsername){//
    User myUser;
    int emptyUser[1000];
    int userSize = 1000;
    for(int i = 0; i < 1000; i++){
        emptyUser[i] = 0;
    }
    for(int j = 0; j < 1000; j++){
        if(username[j].getName() == "NONE"){
            username[j] = User(newUsername, emptyUser, userSize);
            return j;
        }
    }
}
 
int foundation::loadOilyFoundationData(){
    ifstream myfilestream;
    myfilestream.open("oilyFoundation.txt");
    if(myfilestream.is_open()){
        string line;
        int oFoundationCounter = 0;
         
        while(getline(myfilestream, line)){
            string lineIn[2];
             
            Split(line, ',', lineIn, 2);
            string ofound = lineIn[0];
             
            for(int i = 0; i < ofound.length(); i++){
                if((ofound[i] < 96) && (ofound[i] > 123)){
                     ofound[i] = ofound[i] - 32; //convert character to uppercase
                }
            }
            string price = lineIn[1];
            oilyF[oFoundationCounter] = User(ofound, price);
            oFoundationCounter++;
        }
    }
    else{//file didn't open
        return -1;// main interpurts as a fail
    }
    myfilestream.close();//close file
}


int foundation::loadDryFoundationData(){
         
    ifstream myfilestream;
    myfilestream.open("combinationFoundation.txt");
    if(myfilestream.is_open()){
        string line;
        int dFoundationCounter = 0;
         
        while(getline(myfilestream, line)){//while there is a line
             string lineIn[2];//array of size two to put the split lines into
             
             Split(line, ',', lineIn, 2);
             string dfound = lineIn[0];//foundation is the first element in the array
             
             for(int i = 0; i < dfound.length(); i++){//go through each character in dry foundation and convery to upper case
                 if((dfound[i] < 96) && (dfound[i] > 123)){//if lowercase
                     dfound[i] = dfound[i] - 32; //convert character to uppercase
                 }
             }
             string price = lineIn[1];
             dryF[dFoundationCounter] = User(dfound, price);
             dFoundationCounter++;
        }
    }
    else{//file didn't open
         return -1;// main interpurts as a fail
    }
     myfilestream.close();//close file
}


int foundation::loadCombinationFoundationData(){
    ifstream myfilestream;
    myfilestream.open("dryFoundation.txt");
    if(myfilestream.is_open()){
        string line;
        int cFoundationCounter = 0;
         
         while(getline(myfilestream, line)){
             string lineIn[2];
             
             Split(line, ',', lineIn, 2);
             string cfound = lineIn[0];
             
             for(int i = 0; i < cfound.length(); i++){
                 if((cfound[i] < 96) && (cfound[i] > 123)){
                     cfound[i] = cfound[i] - 32; //convert character to uppercase
                 }
             }
             string price = lineIn[1];
             comboF[cFoundationCounter] = User(cfound, price);
             cFoundationCounter++;
        }
    }
    else{//file didn't open
        return -1;// main interpurts as a fail
    }
     myfilestream.close();//close file
}

void foundation::saveFoundationData(){
    //for oily foundation
    ofstream myfilestream1;
    myfilestream1.open("oilyFoundation.txt");
    if(myfilestream1.is_open()){
        for(int i = 0; i < 1000; i++){
            if(username[i].getName() == "NONE"){
                break;
            }
            myfilestream1<<username[i].getName()<<",";
            for(int j = 0; j < 1000; j++){
                myfilestream1<<username[i].getoilyFoundationAt(j)<<",";
            }
            myfilestream1<<endl;
        }
        cout<<"Your Oily foundation that you suggested was put into file. Thankyou!"<<endl;
        else{
            cout<<"Error! Couldn't open the file to save youe data!"<<endl;
        }
        myfilestream1.close();
    }
    //for dry foundation 
    ofstream myfilestream2;
    myfilestream2.open("dryFoundation.txt");
    if(myfilestream2.is_open()){
        for(int i = 0; i < 1000; i++){
            if(username[i].getName() == "NONE"){
                break;
            }
            myfilestream2<<myUser[i].getName()<<",";
            for(int j = 0; j < 1000; j++){
                myfilestream2<<username[i].getdryFoundationAt(j)<<",";
            }
            myfilestream2<<endl;
        }
        cout<<"Your Dry foundation that you suggested was put into file. Thankyou!"<<endl;
        else{
            cout<<"Error! Couldn't open the file to save youe data!"<<endl;
        }
        myfilestream2.close();
    }
    //for combination foundation
    ofstream myfilestream3;
    myfilestream3.open("combinationFoundation.txt");
    if(myfilestream3.is_open()){
        for(int i = 0; i < 1000; i++){
            if(username[i].getName() == "NONE"){
                break;
            }
            myfilestream3<<myUser[i].getName()<<",";
            for(int j = 0; j < 1000; j++){
                myfilestream3<<myUser[i].getcombinationFoundationAt(j)<<",";
            }
            myfilestream3<<endl;
        }
        cout<<"Your Combination foundation that you suggested was put into file. Thankyou!"<<endl;
        else{
            cout<<"Error! Couldn't open the file to save your data!"<<endl;
        }
        myfilestream3.close();
    }
}
 

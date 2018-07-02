//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Project: Concealer.cpp

using namespace std;


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


class Concealer{
    private:
        
    public:
        Concealer();
        int loadOilyConcealerData();
        int loadCombinationConcealerData();
        int loadDryConcealerData();
        void saveConcealerData();
};

Concealer::Concealer(){}
 
 int Concealer::loadOilyConcealerData(){
     ifstream myfilestream;
     myfilestream.open("oilyConcealer.txt");
     if(myfilestream.is_open()){
         string line;
         int oConcealerCounter = 0;
         
         while(getline(myfilestream, line)){
             string lineIn[2];
             
             Split(line, ',', lineIn, 2);
             string oconceal = lineIn[0];
             
             for(int i = 0; i < oconceal.length(); i++){
                 if((oconceal[i] < 96) && (oconceal[i] > 123)){
                     oconceal[i] = oconceal[i] - 32; //convert character to uppercase
                 }
             }
             string price = lineIn[1];
             oilyC[oConcealerCounter] = Concealer(oconceal, price)
             oConcealerCounter++;
         }
     }
     else{//file didn't open
         return -1;// main interpurts as a fail
     }
     myfilestream.close();//close file
}


int Concealer::loadDryConcealerData(){
         
    ifstream myfilestream;
    myfilestream.open("combinationConcealer.txt");
    if(myfilestream.is_open()){
        string line;
        int dConcealerCounter = 0;
         
        while(getline(myfilestream, line)){//while there is a line
             string lineIn[2];//array of size two to put the split lines into
             
             Split(line, ',', lineIn, 2);
             string dconceal = lineIn[0];//foundating is the first element in the array
             
             for(int i = 0; i < dconceal.length(); i++){//go through each character in dry Concealer and convery to upper case
                 if((dconceal[i] < 96) && (dconceal[i] > 123)){//if lowercase
                     dconceal[i] = dconceal[i] - 32; //convert character to uppercase
                 }
             }
             string price = lineIn[1];
             dryC[dConcealerCounter] = Concealer(dconceal, price)
             dConcealerCounter++;
        }
    }
    else{//file didn't open
         return -1;// main interpurts as a fail
    }
     myfilestream.close();//close file
}


int Concealer::loadCombinationConcealerData(){
    ifstream myfilestream;
    myfilestream.open("dryConcealer.txt");
    if(myfilestream.is_open()){
        string line;
        int cConcealerCounter = 0;
         
         while(getline(myfilestream, line)){
             string lineIn[2];
             
             Split(line, ',', lineIn, 2);
             string fconceal = lineIn[0];
             
             for(int i = 0; i < fconceal.length(); i++){
                 if((fconceal[i] < 96) && (fconceal[i] > 123)){
                     fconceal[i] = fconceal[i] - 32; //convert character to uppercase
                 }
             }
             string price = lineIn[1];
             comboC[cConcealerCounter] = Concealer(fconceal, price)
             cConcealerCounter++;
        }
    }
    else{//file didn't open
        return -1;// main interpurts as a fail
    }
     myfilestream.close();//close file
}
     
void Concealer::saveConcealerData(){
    ofstream myfilestream1;
    myfilestream1.open("oilyConcealer.txt");
    if(myfilestream1.is_open()){
        for(int i = 0; i < 1000; i++){
            if(myUser[i].getName() == "NONE"){
                break;
            }
            myfilestream1<<myUser[i].getName()<<",";
            for(int j = 0; j < 1000; j++){
                myfilestream1<<myUser[i].getoilyConcealerAt(j)<<",";
            }
            myfilestream1<<endl;
        }
        cout<<"Your Oily Concealer that you suggested was put into file. Thankyou!"<<endl;
        else{
            cout<<"Error! Couldn't open the file to save youe data!"<<endl;
        }
        myfilestream1.close();
    }
    //for dry Concealer 
    ofstream myfilestream2;
    myfilestream2.open("dryConcealer.txt");
    if(myfilestream2.is_open()){
        for(int i = 0; i < 1000; i++){
            if(myUser[i].getName() == "NONE"){
                break;
            }
            myfilestream2<<myUser[i].getName()<<",";
            for(int j = 0; j < 1000; j++){
                myfilestream2<<myUser[i].getdryConcealerAt(j)<<",";
            }
            myfilestream2<<endl;
        }
        cout<<"Your Dry Concealer that you suggested was put into file. Thankyou!"<<endl;
        else{
            cout<<"Error! Couldn't open the file to save youe data!"<<endl;
        }
        myfilestream2.close();
    }
    //for combination Concealer
    ofstream myfilestream3;
    myfilestream3.open("combinationConcealer.txt");
    if(myfilestream3.is_open()){
        for(int i = 0; i < 1000; i++){
            if(myUser[i].getName() == "NONE"){
                break;
            }
            myfilestream3<<myUser[i].getName()<<",";
            for(int j = 0; j < 1000; j++){
                myfilestream3<<myUser[i].getcombinationConcealerAt(j)<<",";
            }
            myfilestream3<<endl;
        }
        cout<<"Your Combination Concealer that you suggested was put into file. Thankyou!"<<endl;
        else{
            cout<<"Error! Couldn't open the file to save youe data!"<<endl;
        }
        myfilestream3.close();
    }
}
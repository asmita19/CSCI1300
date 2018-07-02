//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Project: Users

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class User{
    public: //these are all method attributes
        User(); //default constructor: empty
        User(string p, string pp);//prodect parameter and price parameter
        void setProduct(string newProduct);
        void setPrice(string newPrice);
        string getProduct() const;
        string getPrice() const;
        
        User(string myName, int currentUsers[], int a);
        void setName(string newName);
        string getName() const;
        
        int getoilyFoundationAt(int myIndex1)const;
        int setoilyFoundationAt(int position1, int mypos1);
        int getdryFoundationAt(int myIndex2)const;
        int setdryFoundationAt(int position2, int mypos2);
        int getcombinationFoundationAt(int myIndex3)const;
        int setcombinationFoundationAt(int position3, int mypos3);
        
        int getoilyConcealerAt(int myIndex4)const;
        int setoilyConcelaerAt(int position4, int mypos4);
        int getdryConcelaerAt(int myIndex5)const;
        int setdryConcelaerAt(int position5, int mypos5);
        int getcombinationConcelaerAt(int myIndex6)const;
        int setcombinationConcelaerAt(int position6, int mypos6);
        
    private://these are all field attributes
        string product;
        string uPrice;
        string name;
        int amount;
        int user[1000];
        
        string oilyC[1000];
        string dryC[1000];
        string comboC[1000];
        
        string oilyF[1000];
        string dryF[1000];
        string comboF[1000];
        
};

User::User(){
    product = "";
    uPrice = "";
}
User::User(string p, string pp){//product parameter and price parameter
    product = p;
    uPrice = pp;
}
void User::setProduct(string newProduct){
    product = newProduct;
}
void User::setPrice(string newPrice){
    uPrice = newPrice;
}
string User::getProduct() const{
    return product;
}
string User::getPrice() const{
    return uPrice;
}

User::User(){
    name = "NONE";
    amount = 0;
    user[1000];
}
/*
User::User(string myName) {
    name = myName;
}
*/


User::User(string myName, int currentUsers[], int a){
    name = myName;
    amount = a;
    user[1000] = *currentUsers;
}


void User::setName(string newName){
   name = newName; 
}
string User::getName() const{
   return name; 
}

//Oily foundation
int User::setoilyFoundationAt(int position1, int mypos1){//oily foundation
    if(mypos1 >= amount){
        return -1000; 
    }
    else{
        oilyF[position1] = mypos1;
        cout<<"Success!"<<endl;
        return 0;
    }
}

int User::getoilyFoundationAt(int myIndex1) const{ 
    if(myIndex1 >= amount){
        return -1000;
    }else{
        return user[myIndex1];
    }
}
//Dry foundation
int User::setdryFoundationAt(int position2, int mypos2){//dry foundation
    if(mypos2 >= amount){
        return -1000;
    }
    else{
        dryF[position2] = mypos2;
        cout<<"Success!"<<endl;
        return 0;
    }
}
int User::getdryFoundationAt(int myIndex2)const{
    if(myIndex2 >= amount){
        return -1000;
    }else{
        return user[myIndex2];
    }
}
//combination foundation
int User::setcombinationFoundationAt(int position3, int mypos3){//combonation foundation
    if(mypos3 >= amount){
        return -1000;
    }
    else{
        comboF[position3] = mypos3;
        cout<<"Success!"<<endl;
        return 0;
    }
}
int User::getcombinationFoundationAt(int myIndex3)const{
    if(myIndex3 >= amount){
        return -1000;
    }else{
        return user[myIndex3];
    }
}

int User::setoilyConcelaerAt(int position4, int mypos4){//oily concealer
    if(mypos4 >= amount){
        return -1000;
    }
    else{
        oilyC[position4] = mypos4;
        cout<<"Success!"<<endl;
        return 0;
    }
}

int User::getoilyConcealerAt(int myIndex4)const{
    if(myIndex4 >= amount){
        return -1000;
    }else{
        return user[myIndex4];
    }
}

int User::setdryConcelaerAt(int position5, int mypos5){//dry concealer
    if(mypos5 >= amount){
        return -1000;
    }
    else{
        dryC[position5] = mypos5;
        cout<<"Success!"<<endl;
        return 0;
    }
}
int User::getdryConcelaerAt(int myIndex5)const{
    if(myIndex5 >= amount){
        return -1000;
    }else{
        return user[myIndex5];
    }
}


int User::setcombinationConcelaerAt(int position6, int mypos6){//combination concealer
    if(mypos6 >= amount){
        return -1000;
    }
    else{
        comboC[position6] = mypos6;
        cout<<"Success!"<<endl;
        return 0;
    }
}
int User::getcombinationConcelaerAt(int myIndex6)const{
    if(myIndex6 >= amount){
        return -1000;
    }else{
        return user[myIndex6];
    }
}
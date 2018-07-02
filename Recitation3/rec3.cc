//Asmita Dhakal
//CSCI 1300 
//Reciatation: Ashwin Sankaralingam 202
//Recitation 3

#include <iostream>
using namespace std;

//Problem 1:
float getHours(){
    float hours;
    cout<<"Please enter how many hours you worked this week: "<<endl;
    cin>>hours;
    return hours; 
}

//Problem2:
float calcPay(float hours_w, float pay_rate){
    float pay = pay_rate * hours_w;
    return pay;
}

//Problem 3:
int printPay(float value){
    cout<<"Your pay is $"<<value<<"."<<endl;
    return value;
}

//Main function: testing the codes
int main(){
    getHours();
    getHours();
    calcPay(12.46, 10.5);
    calcPay(13.66, 20);
    printPay(130.83);
    printPay(273.2);
}
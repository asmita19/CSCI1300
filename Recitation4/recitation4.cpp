//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Recitation 4

#include <iostream>
#include <cmath>
using namespace std;

//Problem1:
void calcPay(float h_worked, float p_rate){
    float pay;
    float over_time;
       if(p_rate < 0 || h_worked < 0){
        cout<<"Pay rate and hours worked cannot be negative values."<<endl;
        }
        
        else if(h_worked <= 40){
        pay = h_worked * p_rate;
        cout<<"Your pay is $"<<pay<<"."<<endl;
        }
        
        else{
        over_time = (h_worked - 40) * (1.5 * p_rate);
        pay = over_time + (40 * p_rate);
        cout<<"Your pay is $"<<pay<<"."<<endl;
        }
}

//Problem2:
int collatzStep(int n){
    int collatz;
    if(n % 2 == 0){
      collatz = n /2;
    }
    else if(n % 2 != 0){
        collatz = 3*n + 1;
    }
    else if(n < 0){
        return 0;
    }
    return collatz;
}

//Problem3:
int printEvenNums(int max){
    int i = 1;
        while(i < max)
        {
            i += 1;
            cout<<i<<endl;
            i++;
        }
}

//Problem4:
void printMultiples(int i, int max)
{
    int x = 2;
     int num = i;
    while(num <= max)
    {
        cout<<num<<endl;
        num = i * x;
        x++;
    }
}


int main(){
    calcPay(-10, 23.76);
    collatzStep(4);
    printEvenNums(10);
    printMultiples(3, 10);
}

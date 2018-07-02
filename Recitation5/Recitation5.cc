//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Recitation 5

#include <iostream>
#include <string>
using namespace std;

//Problem1:
int getWordCount(string sen){
    int index = 0;
    int o = 0;
    if(sen.length() == 0)
        return 0;
    while(index < sen.length()){
        if(sen[index] == ' '){
            o++;
        }
        index++;
    }
    return o + 1;
}

//Problem2:
int getDigitCount(string s){
    int digits = 0;
    for(int i = 0; i < s.length(); i++){
        char m = s[i];
        if(s[i] == '1' || s[i] =='2' || s[i] =='3' || s[i] =='4' || s[i] =='5'|| s[i] =='6'|| s[i] =='7'|| s[i] =='8'|| s[i] =='9'|| s[i] =='0'){
            digits++;
        }
    }
    return digits;
}

//Problem3:
int getMatchCount(string substr, string word){
    int count = 0;
    string z;
    if(word.length() == 0 || substr.length() == 0){
        return -1;
    }
    else if(substr.length() > word.length()){
        return -2;
    }
    else{
        for(int i = 0; i <= word.length()- substr.length(); i++){
            z = word.substr(i, substr.length());
            if(z == substr){
                count++;
            }
        }
    }
    return count;
}

//Problem4:
int getLastIndex(char cha, string word){
    int count = 0;
    int p;
    if(word.length() == 0){
        return -1;
    }
    bool x = false;
    for(int i = 0; i < word.length(); i++){
        if(word[i] == cha){
            p = i;
            x = true;
        }
    }
    if(x == true){
        return p;
    }
    else{
        return -2;
    }
}
    
int main(){
    
    //test for problem 1:
    string s = "cat hat bat";
    //test for problem 2:
    string i; 
    getline(cin, i);
    cout<<getDigitCount(i)<<endl;
    
    //test for problem 3:
    cout<<getMatchCount("he", "hellohello")<<endl;
    
    //test for problem 4:
    cout<<getLastIndex('h', "")<<endl;
}
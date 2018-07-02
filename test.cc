#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


void printVec(vector<string> b){
    cout<<"|";
    for(int i = 0; i < b.size(); i++){
        cout<<b[i]<<"|";
    }
}


int main(){
    
    string friendcum3s[] = {"Yadira", "Urja", "Sam"};
    vector<string>myfriends;
    myfriends.assign(friends, friends+3);
    printVec(myfriends);
    
    cout<<endl;
    
    
    
    vector <int> v(3);
    v[0] = 10; 
    v[1] = 22; 
    v[2] = 5;
    
     v.push_back(7);
     //cout<<v.front()<<endl;
     //cout<<v.back()<<endl;
     //cout<<v.at(2)<<endl;
     
     int firstitem = v.front(); // = v[0]
     //cout<<"First item: "<<firstitem<<endl;
     
     int removed = v.back(); // = v[v.size() - 1]
     //v.pop_back();
     
     //printVec(v);
     //cout<<"Removed item: "<<removed;
     
     return 0;
}

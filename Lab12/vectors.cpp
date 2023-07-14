//A big benefit of vectors is their ability to be returned from functions. For this task, program a function called vector<int> makeVector(int n) that returns a vector of n integers that range from 0 to n-1. Call your program vectors.cpp. Your function must be implemented outside the main function and must return a vector.

#include <iostream>
#include <vector>
using namespace std;


vector<int> makeVector(int n){
    vector<int> vec;
    for(int i = 0; i < n; i ++){
        vec.push_back(i);
    }
    return vec;
}

int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    
    vector<int> vec2 = makeVector(num);
    for(int i = 0; i < num; i ++){
        cout<<vec2[i]<<endl;
    }
    return 0;
}

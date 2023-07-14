//Make a program called fusion.cpp that implements the function void gogeta(vector<int> &goku, vector<int> &vegeta) that appends elements of the second vector into the first and empties the second vector. For example:
 
 // vector<int> v1{1,2,3};
 // vector<int> v2{4,5};

 // gogeta(v1, v2); // v1 is now [1,2,3,4,5] and v2 is empty.

#include <iostream>
#include <vector>
using namespace std;

void gogeta(vector<int>& goku, vector<int>& vegeta){
    for(int i = 0; i < vegeta.size(); i++){
        goku.push_back(vegeta[i]);
    }
    vegeta.clear();
}

int main(){
    vector<int> vec1;
    vector<int> vec2;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec2.push_back(4);
    vec2.push_back(5);
    gogeta(vec1,vec2);
    for(int i = 0; i < vec1.size(); i++){
        cout<<vec1[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < vec2.size(); i++){
        cout<<vec2[i]<<" ";
    }
}

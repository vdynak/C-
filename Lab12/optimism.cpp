//Make a program called optimism.cpp that implements the function vector<int> goodVibes(const vector<int>& v); that, given a vector of integers, returns a vector with only the positive integers in the same order.
 
 //vector<int> v{1,2,-1,3,4,-1,6};

 //goodVibes(v); // returns [1,2,3,4,6]

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(const vector<int> v){
    vector<int> positives;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > 0){
            positives.push_back(v[i]);
        }
    }
    return positives;
}

int main(){
    vector<int> mix {-1, 2, -4, -6, 5};
    vector<int> vec2;
    vec2 = goodVibes(mix);
    for(int i = 0; i < vec2.size(); i++){
        cout<<vec2[i]<<endl;
    }
    return 0;
}

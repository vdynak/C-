// Write a program called pairwise.cpp that implements the function vector<int> sumPairWise(const vector<int> &v1, const vector<int> &v2) that returns a vector of integers whose elements are the pairwise sum of the elements from the two vectors passed as arguments. If a vector has a smaller size than the other, consider extra entries from the shorter vectors as 0. Example:
 
//  vector<int> v1{1,2,3};
//  vector<int> v2{4,5};

//  sumPairWise(v1, v2); // returns [5, 7, 3]

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2){
    vector <int> v3;
    int i = 0;
    while(i < v1.size() || i < v2.size()){
        int pair = 0;
        if(i < v1.size()){
            pair = pair + v1[i];
        }
        if(i < v2.size()){
            pair = pair + v2[i];
        }
        v3.push_back(pair);
        i++;
    }
    return v3;
}

int main(){
    vector<int> v1;
    vector<int> v2;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    vector<int> final = sumPairWise(v1,v2);
    for(int i = 0; i < final.size(); i++){
        cout<<final[i]<<" ";
    }
    cout<<endl;
}

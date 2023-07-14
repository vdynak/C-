//This program creates arrays pertaining to Current_Reservoir_Levels as it does in the compare.cpp exercise. Afterwrds, it prompts the user to enter an earlier and later date. It then retrives the corresponding West Basin Elevation of that day. The data is printed in reverse-order, with the later dates (and corresponding westEl) printing first and the earlier dates printing last.

#include <iostream>
#include <fstream>
#include <string>
#include <climits>
using namespace std;
int main(){
    string junk;
    string earlier;
    string later;
    const string SPACE = " ";
    int temporary;
    int temporaryend;
    const int SIZE = 365;
    string dates[SIZE];
    double eastSt[SIZE];
    double eastEl[SIZE];
    double westSt[SIZE];
    double westEl[SIZE];

    ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.is_open())
    {
        getline(fin, junk);
        for(int i = 0; i < 365; i++){
            fin>> dates[i] >> eastSt[i] >> eastEl[i] >> westSt[i] >>westEl[i];
            fin.ignore(INT_MAX, '\n');
        }
    }
    else{
        cerr<<"Couldn't open the file"<<endl;
        exit(1);
    }
    cout<<"Enter earlier date: ";
    cin>>earlier;
    cout<<"Enter later date: ";
    cin>>later;
    for (int i = 0; i < 365; i++){
        if (dates[i] == earlier){
            temporary = i; //index place of the earliest date
        }
    }
    for (int i = 0; i < 365; i++){
        if (dates[i] == later){
            temporaryend = i; //index place of the latest index, greater than temporary
        }
    }
    while(temporaryend >= temporary){
        cout<<dates[temporaryend]<<SPACE<<westEl[temporaryend]<<endl;
        temporaryend = temporaryend - 1;
    }
    return 0;
}


//while(temporaryend > temporary){
//    for(int j = temporaryend; j < temporary; j--){
//        cout<<dates[j]<<SPACE<<westEl[j]<<endl;
//    }
//    temporary = temporary + 1;
//}

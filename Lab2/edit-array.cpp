//The program creates the array myData with a fixed number of cells, where each cell is filled with the value 1 and printed. Afterward, the user is asked to provide an index number and the value for the index, which, when in the bounds of the array, replaces the value of 1 in that index. The array only updates the value of the index if it is in range.

#include <iostream>
#include <string>
using namespace std;
int main(){
    const int SIZE = 10;
    const string newspace = " ";
    int i;
    int v;
    int myData[SIZE];
    for(int j = 0; j<SIZE; j++){
        myData[j]=1;
        cout<<myData[j]<<newspace;
    }
    do{
        cout<<endl<<"Input index: ";
        cin>>i;
        cout<<"Input value: ";
        cin>>v;
        if(i>=0 && i<10){
            for(int j = 0; j<SIZE; j++){
                myData[i]=v;
                cout<<myData[j]<<newspace;
            }
        }
        else{
            cout<<"Index out of range. Exit"<<endl;
        }
    }while(i>=0 && i<10);
    return 0;
}

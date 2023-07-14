/*
 Victoria Dynak
 Course: CSCI 136
 Instructor: Genady Maryash
 Assignment: edit-array.cpp
 The program creates the array myData with a fixed number of cells, where each cell is filled with the value 1 and printed. Afterwards, the user is asked to provide an index number and the value for the index, which, when in the bounds of the array, replaces the value of 1 in that index. The array only updates the value of the index if it is in range.
 */

//#include <iostream>
//#include <string>
//using namespace std;
//int main(){
//    const int SIZE = 10;
//    const string newspace = " ";
//    int i;
//    int v;
//    int myData[SIZE];
//    for(int j = 0; j<SIZE; j++){
//        myData[j]=1;
//        cout<<myData[j]<<newspace;
//    }
//    do{
//        cout<<endl<<"Input index: ";
//        cin>>i;
//        cout<<"Input value: ";
//        cin>>v;
//        if(i>=0 && i<10){
//            for(int j = 0; j<SIZE; j++){
//                myData[i]=v;
//                cout<<myData[j]<<newspace;
//            }
//        }
//        else{
//            cout<<"Index out of range. Exit"<<endl;
//        }
//    }while(i>=0 && i<10);
//    return 0;
//}
//

//#include <iostream>
//using namespace std;
//int main(){
//    const int SIZE = 10;
//    int myData[SIZE];
//    for(int i = 0; i < SIZE; i++){
//        myData[i] = 1;
//        cout<<myData[i];
//    }
//    int indexval;
//    int newval;
//    do{
//        cout<<"Enter an index: ";
//        cin>>indexval;
//        cout<<"Enter a value: ";
//        cin>>newval;
//        if(indexval >= 0 && indexval < 10){
//            myData[indexval] = newval;
//        }
//        for(int j  = 0; j < SIZE; j++){
//            cout<<myData[j];
//        }
//    }while(indexval >= 0 && indexval < 10);
//    return 0;
//}

//#include <iostream>
//using namespace std;
//int main(){
//    const int SIZE = 10;
//    int myData[SIZE];
//    for(int i = 0; i < SIZE; i++){
//        myData[i] = 1;
//        cout<<myData[i];
//    }
//    int index;
//    int newvalue;
//    do{
//        cout<<"Input index: ";
//        cin>>index;
//        cout<<"Input value: ";
//        cin>>newvalue;
//        if(index >= 0 && index < 10){
//            myData[index] = newvalue;
//        }
//        for(int j = 0; j < SIZE; j++){
//            cout<<myData[j];
//        }
//    }while(index >= 0 && index < 10);
//    return 0;
//}

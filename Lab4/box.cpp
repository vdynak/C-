//The program asks the user to enter a width and height, which is initiliazed to the width and height variable respectively. After the "Shape:" line, a box/rectangle of the user inputted width and height is printed in asterisks.

#include <iostream>
using namespace std;
int main(){
    int width;
    int height;
    cout<<"Input width: ";
    cin>>width;
    cout<<"Input height: ";
    cin>>height;
    cout<<endl<<"Shape:"<<endl;
    for(int j = 0; j < height; j++){
        for(int i = 0; i < width; i++){
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    return 0;
}

//Asks the user for the size of the width and height. Prints a rectangular checkerboard, where the first row borders the edge and has the same number of asterisks as the width and the second row has a space between the border and first asterisk with a length of width - 1.

#include <iostream>
using namespace std;
int main(){
    int width;
    int height;
    const string SPACE = " ";
    const string SYMBOL = "*";
    cout<<"Input width: ";
    cin>>width;
    cout<<"Input height: ";
    cin>>height;
    cout<<endl<<"Shape:"<<endl;
    for(int j = 1; j <= height; j++){
        if(j%2 == 0){
            for(int i = 1; i <= width; i++){
                if(i % 2 == 1){
                    cout<<SPACE;
                }
                else{
                    cout<<SYMBOL;
                }
            }
        }
//            for(int i = 1; i <= width/2 + 1; i++){
//                cout<<SPACE<<"*";
//            }
        else if (j%2 == 1){
            for(int i = 1; i <= width; i++){
                if(i % 2 == 1){
                    cout<<SYMBOL;
                }
                else{
                    cout<<SPACE;
                }
            }
            
//            for(int k = 1; k <= width/2 + 1; k++){
//                cout<<"*"<<SPACE;
//            }
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    return 0;
}

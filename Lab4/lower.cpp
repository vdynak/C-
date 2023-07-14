//Asks the user to input a length, which corresponds to the number of lines that will be printed. On the first line, one asterisk is printed and every line following the previous has an extra asterisk added to it. The final line has the same number aestricks as the user inputted length. The final result is a shape that prints the bottom-left half of a square.

#include <iostream>
using namespace std;
int main(){
    int length;
    const string SYMBOL = "*";
    cout<<"Input side length: ";
    cin>>length;
    cout<<"Shape: "<<endl;
    for(int i = 0; i < length; i++){
        for(int j = 0; j <= i; j++){
            cout<<SYMBOL;
        }
        cout<<endl;
    }
    return 0;
}

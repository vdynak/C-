//Asks the user for the size of the length of each section of the X shape. Nested for loops: Both for loops start at 1, are limited by being less than or equal to user-inputted size, and increment by 1 after each full repetition. In the first row, the second nsted loop is equal to the first row i onlt once; therefore, the symbol is printed and the remaining is filled with spaces until it meets the condition of being the last space in the line, during which it is filled with a symbol. This repeats with an incrementation at each new line. Result: Prints out asterisks in an X-shape to match the inputted size.

#include <iostream>
using namespace std;
int main(){
    int size;
    const string SPACE = " ";
    const string SYMBOL = "*";
    cout<<"Input size: ";
    cin>>size;
    cout<<endl<<"Shape:"<<endl;
    for(int i = 1; i <= size; i++){
        for(int j = 1; j <= size; j++){
            if(j == i || j == (size + 1 - i)){
                cout<<SYMBOL;
            }
            else{
                cout<<SPACE;
            }
        }
        cout<<endl;
    }
    return 0;
}

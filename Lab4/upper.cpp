//Asks the user to input a length, which corresponds to the number of lines that will be printed. On the first line, the number of asterisks printed is equivalent to the inputted length. Each following new line, has one less aesterisk and one additional space at the start of the line. The final result is a shape that prints the top right half of a square.

#include <iostream>
using namespace std;
int main(){
    int length;
    const string SYMBOL = "*";
    const string SPACE = " ";
    cout<<"Input side length: ";
    cin>>length;
    cout<<"Shape: "<<endl;
    for(int height = length; height >= 1; height--){
        for(int indent = length - height; indent > 0; indent--)
            cout<<SPACE;
        for(int stars = height; stars > 0; stars--)
            cout<<SYMBOL;
        cout<<endl;
    }
    return 0;
}

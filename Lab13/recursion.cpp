// Write a program recursion.cpp, defining a function
 
//  void printRange(int left, int right);
//  that prints all numbers in range left ≤   x   ≤ right, separated by spaces. (Don’t use loops, global or static variables.)

//  A usage example:

//  int main() {
//      printRange(-2, 10);
//  }
//  Will print:

//  -2 -1 0 1 2 3 4 5 6 7 8 9 10
//  When left > right, the range is empty and the program should not print any numbers.

#include <iostream>
using namespace std;

void printRange(int left, int right){
    if(left > right){
        return;
    }
    if(right > left){
        cout<<left<<" ";
        printRange(left + 1, right);
    }
    else{
        cout << left;
    }
}

int main(){
    printRange(-2, 10);
}

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
#include <ctype.h>
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

int sumRange(int left, int right){
    int sum;
    if(left > right){
        return 0;
    }
    else{
        sum = left + sumRange(left + 1, right);
    }
    return sum;
}

int sumArrayInRange(int *arr, int left, int right){
    int sum = 0;
    if(left > right){
        return 0;
    }
    else{
        sum = arr[left] + sumArrayInRange(arr, left + 1, right); //similar to sumRange
    }
    return sum;
}

int sumArray(int *arr, int size){
    return sumArrayInRange(arr, 0, size - 1); //0, size - 1 are parameters for a size
}


//int sumArrayInRange(int *arr, int left, int right){
//    int sum = 0;
//    for(int i = left; i <= right; i++){ //limits on each side, alternative to for loop
//        sum = sum + arr[i]; //adds the value at that index
//    }
//    return sum; //returns the sum of the whole array
//}
//attempt without a helper function
//int sumArray(int *arr, int size){
//    int sum = 0;
//    for (int i = 0; i < size; i++){
//        sum = sum + *(arr + i);
//    }
//    return sum;
//}

//pointer arithmetic, dereferencing a pointer to the given element of the array
    
bool isAlphanumeric(string s){
    if(s.empty()){
        return true; //conditional given
    }
    char first = s[0];
    if(isalpha(first) || isdigit(first)){
        return isAlphanumeric(s.substr(1)); //iterates
    }
    return false;
}

int main(){
    printRange(-2, 10);
    cout<<endl;
    int x = sumRange(1, 3);
        cout << "This is " << x << endl;   // 6
        
        int y = sumRange(7, 3);
        cout << "That is " << y << endl;   // 52
    
    int size = 10;
        int *arr = new int[size]; // allocate array dynamically
        arr[0] = 12;
        arr[1] = 17;
        arr[2] = -5;
        arr[3] = 3;
        arr[4] = 7;
        arr[5] = -15;
        arr[6] = 27;
        arr[7] = 5;
        arr[8] = 13;
        arr[9] = -21;

        int sum1 = sumArray(arr, size); // Add all elements
        cout << "Sum is " << sum1 << endl;  // Sum is 43

        int sum2 = sumArray(arr, 5); // Add up first five elements
        cout << "Sum is " << sum2 << endl;  // Sum is 34

        delete[] arr;         // deallocate it
}

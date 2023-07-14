/*
Victoria Dynak
Course: CSCI 136
Instructor: Genady Maryash
Assignment: fibonacci.cpp
The program has an array fib, with a fixed set of 60 cells. The first two cells are initialized to fib[0] = 0 and fib[1] = 1, which allows to compute the value of higher indices given fibonacci numbers are calculated by F(n) = F(n−1) + F(n−2).
*/

//#include <iostream>
//using namespace std;
//int main(){
//    const int SIZE = 60;
//    int fib[SIZE]; //could also be declared as double
//    fib[0] = 0;
//    fib[1] = 1;
//    cout<<fib[0]<<endl;
//    cout<<fib[0]+fib[1]<<endl;
//    for(int i = 2; i < 60; i++){
//        fib[i] = fib[i-1] + fib[i-2];
//        cout<<fib[i]<<endl;
//    }
//    return 0;
//}

//Once the fibonacci numbers start to reach the two billion range, the numbers are too big to be stored with the int declaration as int holds 4 bytes. Therefore, you can declare the array as a double type or a long type, where a double and long hold values up to 8 bytes.



//#include <iostream>
//using namespace std;
//int main(){
//    const int SIZE = 60;
//    int fib[SIZE];
//    fib[0] = 0;
//    fib[1] = 1;
//    cout<<fib[0]<<endl;
//    cout<<fib[1]<<endl;
//    for(int i = 2; i < SIZE; i++){
//        fib[i] = fib[i-1] + fib[i-2];
//        cout<<fib[i]<<endl;
//    }
//    return 0;
//}

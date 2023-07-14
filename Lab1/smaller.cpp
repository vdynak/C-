//Find the smaller of two numbers and return that number.

#include <iostream>
using namespace std;
int main(){
   int one, two;
   cout<<"Enter the first number: ";
   cin>>one;
   cout<<"Enter the second number: ";
   cin>>two;
   if(one>two){
       cout<<"The smaller of the two is "<<two<<endl;
   }
   else{
       cout<<"The smaller of the two is "<<one<<endl;
   }
   return 0;
}

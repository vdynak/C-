//Prompts the user for three numbers and returns the smallest of the three values.

#include <iostream>
using namespace std;
int main(){
   int x,y,z;
   cout<<"Enter the first number: ";
   cin>>x;
   cout<<"Enter the second number: ";
   cin>>y;
   cout<<"Enter the third number: ";
   cin>>z;
   int min;
   if(x>y){
       min=y;
   }
   else{
       min=x;
   }
   if(min>z){
       cout<<"The smaller of the three is "<<z<<endl;
   }
   else{
       cout<<"The smaller of the three is "<<min<<endl;
   }
   return 0;
}

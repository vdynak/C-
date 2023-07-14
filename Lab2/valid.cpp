// Ask the user for a number between 0 and 100, non-inclusive. The program then squares the input and returns it with cout<<.

#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    int nsquared;
    const int EXPONENT = 2;
    cout<<"Please enter an integer: ";
    cin>>n;
    while(n<=0 || n>=100){
        cout<<"Please re-enter: ";
        cin>>n;
    }
    nsquared = pow(n,EXPONENT);
    cout<<"Number squared is "<<nsquared<<endl;
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int num;
    int squared;
    cout<<"Enter an integer: ";
    cin>>num;
    while(num <= 0 || num >= 100){
            cout<<"Please re-enter: ";
            cin>>num;
        }
    squared = pow(num,2);
    cout<<squared<<endl;
    return 0;
}

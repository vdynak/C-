//Transforms a user-inputted string into lines of corresponding letter to ascii values.

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){
    string encrypt;
    cout<<"Enter a string to encrypt: ";
    getline(cin, encrypt);
    for(int i = 0; i < encrypt.length(); i++){
        cout<<encrypt[i]<<" "<<(int)encrypt[i]<<endl;
    }
    return 0;
}

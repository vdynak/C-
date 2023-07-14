//Prompts plain text from user and encrypts it by a right shift of a user-inputted amount. Tested with az! for wrap.

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char shiftChar(char, int);
string encryptCaesar(string, int);

int main(){
    string encrypt;
    int shift;
    cout<<"Enter plaintext: ";
    getline(cin, encrypt);
    cout<<"Enter shift: ";
    cin>>shift;
    string evaluate = encryptCaesar(encrypt, shift);
    cout<<"Ciphertext: "<<evaluate<<endl;
}

char shiftChar(char c, int rshift){
    if(c >= 'A' && c <= 'Z'){
        c = 'A' + (c - 'A' + rshift + 26) % 26;
    }
    if(c >= 'a' && c <= 'z'){
        c = 'a' + (c - 'a' + rshift + 26) % 26;
    }
    return c;
}

string encryptCaesar(string plaintext, int rshift){
    string encrypted;
    for(int i = 0; i < plaintext.length(); i++){
        encrypted = encrypted + shiftChar(plaintext[i], rshift);
    }
    return encrypted;
}

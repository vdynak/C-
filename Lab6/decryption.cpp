//Functions that decrypt the Caesar and Vigenere Encryption methods.

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string encryptVigenere(string, string);
char shiftChar(char, int);
string encryptCaesar(string, int);
char unshiftChar(char, int);
string decryptCaesar(string, int);
string decryptVigenere(string,string);

int main(){
    string plaintext;
    string cypher;
    int shift;
    cout<<"Enter plaintext: ";
    getline(cin,plaintext);
    cout<<"= Caesar = "<<endl<<"Enter shfit: ";
    cin>>shift;
    string evaluate_c = encryptCaesar(plaintext, shift);
    string evaluate_cd = decryptCaesar(plaintext,shift);
    cout<<"Ciphertext: "<<evaluate_c<<endl;
    cout<<"Decrypted: "<<evaluate_cd<<endl;
    cout<<"= Vigenere = "<<endl<<"Enter keyword: ";
    cin>>cypher;
    string evaluate_v = encryptVigenere(plaintext, cypher);
    string evaluate_vd = decryptVigenere(plaintext, cypher);
    cout<<"Ciphertext: "<<evaluate_v<<endl;
    cout<<"Decrypted: "<<evaluate_cd<<endl;
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

string encryptVigenere(string plaintext, string keyword){ //meow, abcd
    string plaintext_new;
    char character;
    int index = 0;
    int distance;
    for(int i = 0; i < plaintext.length(); i++){
        character = plaintext[i]; //example: MEOW, M
        if(character >= 'a' && character <= 'z'){ //plaintext, can have both, caps or lower
            distance = keyword[index] - 'a'; // a - a = 0, provides a shift
            index = (index + 1) % keyword.length(); //static?
            character = 'a' + (character - 'a'+ distance + 26) % 26;
        }
        if(character >= 'A' && character <= 'Z'){
            distance = keyword[index] - 'a'; // A - A = 0
            index = (index + 1) % keyword.length();
            character = 'A' + (character - 'A'+ distance + 26) % 26;
        }
        plaintext_new += character;
    }
    return plaintext_new;
}

char unshiftChar(char c, int rshift){
    if(c >= 'A' && c <= 'Z'){
        c = 'A' + (c - 'A' - rshift + 26) % 26;
    }
    if(c >= 'a' && c <= 'z'){
        c = 'a' + (c - 'a' - rshift + 26) % 26;
    }
    return c;
}

string decryptCaesar(string ciphertext, int rshift){
    string decrypted;
    for(int i = 0; i < ciphertext.length(); i++){
        decrypted = decrypted + unshiftChar(ciphertext[i], rshift);
    }
    return decrypted;
}

string decryptVigenere(string ciphertext, string keyword){
    string plaintext_new;
    char character;
    int index = 0;
    int distance;
    for(int i = 0; i < ciphertext.length(); i++){
        character = ciphertext[i]; //example: MEOW, M
        if(character >= 'a' && character <= 'z'){ //plaintext, can have both, caps or lower
            distance = keyword[index] - 'a'; // a - a = 0, provides a shift
            index = (index + 1) % keyword.length(); //static?
            character = 'a' + (character - 'a'- distance + 26) % 26;
        }
        if(character >= 'A' && character <= 'Z'){
            distance = keyword[index] - 'a'; // A - A = 0
            index = (index + 1) % keyword.length();
            character = 'A' + (character - 'A'- distance + 26) % 26;
        }
        plaintext_new += character;
    }
    return plaintext_new;
}

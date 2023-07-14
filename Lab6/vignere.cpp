//Asks user for a plaintext string and a keyword, keyword --> number value = 97 - ascii of letter value in keyword - 1. Answer = that many ascii letters forward in plaintext letter.

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string encryptVigenere(string, string);

int main(){
    string plaintext;
    string cypher;
    cout<<"Enter plaintext: ";
    getline(cin,plaintext);
    cout<<"Enter keyword: ";
    cin>>cypher;
    string evaluate = encryptVigenere(plaintext, cypher);
    cout<<"Ciphertext: "<<evaluate<<endl;
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
            index = (index + 1) % keyword.length(); //can a static variable be used here, how?
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

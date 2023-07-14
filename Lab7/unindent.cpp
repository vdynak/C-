//A program useful for input redirection, in which a file with bad indentation can be passed to in order to remove all bad intention. This program does not apply the proper indentation style; instead, it shifts all lines to the left-side.

#include <iostream>
#include <string>
#include <climits>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string);

int main(){
    string line;
    string evaluate = "";
    while(getline(cin,line)){
        cout<<removeLeadingSpaces(line)<<endl; //to keep the right indents
    }
    return 0;
}

string removeLeadingSpaces(string line){
    string withoutspaces = "";
    bool charbychar = true;
    for(int i = 0; i < line.length(); i++){
        if(!(charbychar && isspace(line[i]))){ //deMorgans law, if not false or not a space, then add line[i] to the new string; otherwise, set charbychar to false, meaning the next index will be compared.
            charbychar = false;
            withoutspaces = withoutspaces + line[i];
        }
    }
    return withoutspaces;
}

#include <iostream>
#include <cctype>
using namespace std;

int countChar(string line, char c){
    int count = 0;
    for(int i = 0; i < line.size(); i++){
        if(line[i] == c){
            count ++; //static variable? or implement in while loop of main function
        }
        else{
            count = count + 0;
        }
    }
    return count;
}

string removeLeadingSpaces(string line){
    string withoutspaces;
    bool charbychar = false;
    for(int i = 0; i < line.length(); i++){
        if(!isspace(line[i])){
            charbychar = true;
        }
        if(charbychar){
            withoutspaces = withoutspaces + line[i];
        }
    }
    return withoutspaces;
}

int main(){
    string line; //original line
    string finalLine; //produced line
    int count = 0; //count of tabs
    while (getline(cin, line, '\n')){
        finalLine = removeLeadingSpaces(line);// produced line, clean line
        string indents; //importance of initializing inside this loop
        for (int i = 0; i < (finalLine[0] != '}' ? count : count - 1 ); i++){
            indents = indents + '\t';
        }
        cout << indents << finalLine << endl;
        count = count + countChar(line,'{') - countChar(line,'}'); //able to end program
    }
    return 0;
}

/*
 Example:
 int main(){
 line: 39 - orients the line
 41 - if the first value of this line is not a bracket, then count remains otherwise increment
 47- for index i = 0; i < count; i++, in this case i = 0, therefore, no indents added to indent var
 50 - print indents followed by the orientated line.
 51 - count will be set to 0 + (1 - 0) = - 1
 next line, //Hi, Im a program!
 */

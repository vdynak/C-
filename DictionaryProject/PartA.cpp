// @param: The string with the `filename`
// @post: Reads the words, definitions, and POS into the global arrays, and sets the value of `WORD_COUNT' to the number of words read.

#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

void readWords(string);
const int g_MAX_WORDS = 1000;
int g_word_count = 0;
string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];
string g_clean[g_MAX_WORDS];


//int main(){
//    readWords("dtest.txt");
//    cout<<"g_MAX_WORDS: "<<g_MAX_WORDS<<endl;
//    cout<<"g_word_count: "<<g_word_count<<endl;
//
//    cout<<g_words[0]<<g_words[1]<<g_words[2]<<g_words[3]<<g_words[4]<<endl;
//    cout<<g_pos[0]<<g_pos[1]<<g_pos[2]<<g_pos[3]<<g_pos[4]<<endl; //printing semis, get to end of string before changing line.
//    cout<<g_definitions[0]<<g_definitions[1]<<g_definitions[2]<<g_definitions[3]<<g_definitions[4]<<endl;
//
//}

void readWords(string filename){
    ifstream fin(filename);
    if(fin.is_open()){
        int i = 0;
        while(fin >> g_words[i] >> g_pos[i] >> g_clean[i]){
            fin.ignore(INT_MAX, ' ');
            getline(fin, g_definitions[i]);
            g_word_count = g_word_count + 1;
            i++;
        }
    }
}

/*
 if(fin.is_open())
 {
     getline(fin, junk);
     for(int i = 0; i < 365; i++){
         fin>> dates[i] >> eastSt[i] >> eastEl[i] >> westSt[i] >>westEl[i];
         fin.ignore(INT_MAX, '\n');
     }
 }
 else{
     cerr<<"Couldn't open the file"<<endl;
     exit(1);
 }

 */

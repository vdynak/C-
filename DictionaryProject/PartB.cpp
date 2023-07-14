// @param: The string with the `filename`
// @post: Reads the words, definitions, and POS into the global arrays, and sets the value of `WORD_COUNT' to the number of words read.

//getdef, getpos

#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

void readWords(string);
int getIndex(string word);
string getDefinition(string word);
string getPOS(string word);
int countPrefix(string prefix);
const int g_MAX_WORDS = 1000;
int g_word_count = 0;
string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];
string g_clean[g_MAX_WORDS];


//int main(){
//    readWords("dtest.txt");
//    string query;
//    cout<<"Enter a query word: ";
//    cin>>query;
//    int evaluate = getIndex(query);
//    cout<<"The word is at index " << evaluate<<endl;
//    string evaluate = getPOS(query);
//    cout<<"The part of speech of "<<query<< " is "<< evaluate<<endl;
//    string prefix;
//    cout<<"Enter a prefix: ";
//    cin>>prefix;
//    int evaluate = countPrefix(prefix);
//    cout<<"The number of words with the prefix "<<prefix<< " is "<<evaluate<<endl;


//    cout<<"g_MAX_WORDS: "<<g_MAX_WORDS<<endl;
//    cout<<"g_word_count: "<<g_word_count<<endl;
//    cout<<g_words[0]<<g_words[1]<<g_words[2]<<g_words[3]<<g_words[4]<<endl;
//    cout<<g_pos[0]<<g_pos[1]<<g_pos[2]<<g_pos[3]<<g_pos[4]<<endl; //printing semis, get to end of string before changing line.
//    cout<<g_definitions[0]<<g_definitions[1]<<g_definitions[2]<<g_definitions[3]<<g_definitions[4]<<endl;

//}
/*
   @param            :   The string with a query word
   @return           :   Integer index of the word in
                         `g_words` global-array. Returns
                         -1 if the word is not found
   @post             :   Find the index of given `word`
                         in the `g_words` array. Return -1
                         if word is not in the array
*/


int getIndex(string word){
    for(int position = 0; position < g_MAX_WORDS; position++){
        if(g_words[position] == word){
            return position;
        }
    }
    return -1;
}

/*
    @param            :   The string with a query word
    @return           :   Return the string definition of
                          the word from  `g_definitions`
                          global-array. Return "NOT_FOUND" if
                          word doesn't exist in the dictionary
    @post             :   Find the definition of the given `word`
                          Return "NOT_FOUND" otherwise
*/
string getDefinition(string word){
    int q_index = getIndex(word);
    for(int position = 0; position < g_MAX_WORDS; position ++){
        if(position == q_index){
            return g_definitions[position];
        }
    }
    return "NOT_FOUND";
}

/*
    @param            :   The string with a query word
    @return           :   Return the string part-of-speech(pos)
                          from the `g_pos` global-array. Return
                          "NOT_FOUND" if the word doesn't exist
                          in the dictionary.
    @post             :   Find the pos of the given `word`
                          Return "NOT_FOUND" otherwise
*/
string getPOS(string word){
    int q_index = getIndex(word);
    for(int position = 0; position < g_MAX_WORDS; position ++){
        if(position == q_index){
            return g_pos[position];
        }
    }
    return "NOT_FOUND";
}

/*
    @param            :   The string prefix of a word (the prefix
                          can be of any length)
    @return           :   Integer number of words found that starts
                          with the given `prefix`
    @post             :   Count the words that start with the given
                          `prefix`
*/

int countPrefix(string prefix){
    int p_size = prefix.size();
    int match = 0;
    for(int position = 0; position < g_MAX_WORDS; position ++){
        string testcase = g_words[position].substr(0, p_size);
        if(testcase == prefix){
            match ++;
        }
    }
    return match;
}

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

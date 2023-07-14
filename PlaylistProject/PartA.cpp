//Functions allocateNew(), readSongs() with the application of dynamic arrays/properties of pointers, arrays, and string functions.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//global
int g_curr_size = 2;
int g_number_of_songs = 0;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];
string *g_genres = new string[g_curr_size];

/*
    @post             :   Replace the old global
                          dynamically allocated arrays
                          with new dynamically allocated
                          arrays of twice the size
                          ('g_curr_size' * 2). Update
                          'g_curr_size' accordingly.
                          Make sure you copy the contents
                          of the older arrays. Do this
                          for the following global-arrays:
                          'g_song_names', 'g_artist_names',
                          'g_song_durations', 'g_genres'
*/
void allocateNew(){
    g_curr_size = g_curr_size * 2;
    string *updated_song_names = new string[g_curr_size];
    string *updated_artist_names = new string[g_curr_size];
    int *updated_song_durations = new int[g_curr_size];
    string *updated_genres = new string[g_curr_size];

    for(int i = 0; i < g_number_of_songs; i++){
        updated_song_names[i] = g_song_names[i];
        updated_artist_names[i] = g_artist_names[i];
        updated_song_durations[i] = g_song_durations[i];
        updated_genres[i] = g_genres[i];
    }
    //if the memory for the dynamic arrays was deleted after assigning the new dynamic arrays to the old memory, the first eight songs or the original size of the dynamic arrays would have been overwritten with null values, important to prevent "dangling pointers"
    delete[] g_song_names;
    delete[] g_artist_names;
    delete[] g_song_durations;
    delete[] g_genres;
    g_song_names = updated_song_names;
    g_artist_names = updated_artist_names;
    g_song_durations = updated_song_durations;
    g_genres = updated_genres;
}

/*
    @param            :   The string with the 'filename'
    @post             :   Reads the song, artists,
                          song durations and genres into
                          the global-arrays and set the
                          value of 'g_number_of_songs'
                          to the number of songs read.
                          Call 'allocateNew()' to allocate
                          an array of larger size if the
                          dynamic arrays reach full
                          capacity.
*/
void readSongs(string filename){
    ifstream playlist(filename);
    if(playlist.is_open()){
        string line;
        //typically would include a string junk variable to account for headers
        while(getline(playlist, line)){ //creates a cont. input
            //.find(sequence, position, count) where position refers to the index to start the search from
            //.susbtr(start position, length)
            int semicolon = line.find(":"); //3
            string songs = line.substr(0,semicolon); //Song Name
            
            int dash = line.find("-"); //7
            string artists = line.substr(semicolon + 1, dash - semicolon - 1); //4, length of 7-4-1 = 2, Arist Name
            
            int secondDash = line.find("-", dash + 1); //9
            string genres = line.substr(dash + 1, secondDash - dash - 1); //8, 9-8-1 = 0, @8 = GENRE
            
            int minutes = line.find("mins"); //12
            int duration = stoi(line.substr(secondDash + 1, minutes - secondDash - 1)); //10, 12-10-1
            //stoi() learned from geeksforgeeks.com/substring-in-cpp/
            
            if(g_number_of_songs == g_curr_size){
                allocateNew();
            }
            
            g_song_names[g_number_of_songs] = songs;
            g_artist_names[g_number_of_songs] = artists;
            g_genres[g_number_of_songs] = genres;
            g_song_durations[g_number_of_songs] = duration;
            g_number_of_songs++;
        }
    }
    else{
        cerr<<"Couldn't open the file"<<endl;
        exit(1);
    }
    playlist.close();
}

int main(){
    readSongs("playlist.txt");
    cout << "g_curr_size: " << g_curr_size << endl << endl;
    cout << "g_number_of_songs: " << g_number_of_songs << endl << endl;
    cout << "g_song_names: [";
    for (int i = 0; i < g_number_of_songs; i++) {
        cout << g_song_names[i];
        if(i < g_number_of_songs - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl<<"g_artist_names: [";
    for (int i = 0; i < g_number_of_songs; i++) {
        cout << g_artist_names[i];
        if(i < g_number_of_songs - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl<<"g_song_durations: [";
    for (int i = 0; i < g_number_of_songs; i++) {
        cout << g_song_durations[i];
        if(i < g_number_of_songs - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl<<"g_genres: [";
    for (int i = 0; i < g_number_of_songs; i++) {
        cout << g_genres[i];
        if(i < g_number_of_songs - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

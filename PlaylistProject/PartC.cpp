//Functions allocateNew(), readSongs() with the application of dynamic arrays/properties of pointers, arrays, and string functions. Includes the Song class.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Song{
public:
    string name;
    string artist;
    int duration;
    string genre;
};

int g_capacity = 2;
int g_size = 0;
Song *g_songs = new Song[g_capacity];

//changes to void allocateNew, class Song
void allocateNew(){
    g_capacity = g_capacity * 2;
    Song *updatedSongs = new Song[g_capacity];

    for(int i = 0; i < g_size; i++){
        updatedSongs[i] = g_songs[i];
    }
    delete[] g_songs;
    g_songs = updatedSongs;
}

void readSongs(string filename){
    ifstream playlist(filename);
    if(playlist.is_open()){
        string line;
        while(getline(playlist, line)){
            string songS;
            string artistS;
            string genreS;
            string durationS;
            
            int semicolon = line.find(":");
            songS = line.substr(0,semicolon);

            int dash = line.find("-"); //7
            artistS = line.substr(semicolon + 1, dash - semicolon - 1);

            int secondDash = line.find("-", dash + 1);
            genreS = line.substr(dash + 1, secondDash - dash - 1);

            int minutes = line.find("mins");
            durationS = line.substr(secondDash + 1, minutes - secondDash - 1); //remove stoi here.
            //stoi() learned from geeksforgeeks.com/substring-in-cpp/

            if(g_size == g_capacity){
                allocateNew();
            }

            g_songs[g_size] = (Song)
            {songS,
            artistS,
            stoi(durationS),
            genreS};
            
            g_size = g_size + 1;
        }
    }
    else{
        cerr<<"Couldn't open the file"<<endl;
        exit(1);
    }
    playlist.close();
}

Song *getSongsFromDuration(int duration, int &durationsCount, int filter){
    Song *criteria = new Song[g_size];
    durationsCount = 0;
    for(int i = 0; i <g_size; i++){
        if(filter == 0 && g_songs[i].duration > duration){
            criteria[durationsCount] = g_songs[i];
            durationsCount++;
        }
        else if(filter == 1 && g_songs[i].duration < duration){
            criteria[durationsCount] = g_songs[i];
            durationsCount++;
        }
        else if(filter == 2 && g_songs[i].duration == duration){
            criteria[durationsCount] = g_songs[i]; //g_songs[i].name?
            durationsCount++;
        }
    }
    return criteria;
}

Song *getGenreSongs(string genre, int &genreCount){
    Song *gSongs = new Song[g_size];
    int num = 0;
    genreCount = 0;
    for(int i = 0; i < g_size; i++){
        if(g_songs[i].genre == genre){
            genreCount++;
            gSongs[num] = g_songs[i]; //g_songs[i].name?
            num++;
        }
    }
    return gSongs;
}

string *getUniqueArtists(int &uniqueCount){
    bool fact;
    uniqueCount = 0;
    string *unique = new string[g_size];
    for(int i = 0; i < g_size; i++){
        fact = true;
        for(int j = 0; j <uniqueCount; j++){
            if(g_songs[i].artist == unique[j]){
                fact = false;
            }
        }
        if(fact == true){
            unique[uniqueCount] = g_songs[i].artist;
            uniqueCount++;
        }
    }
    return unique;
}

string getFavoriteArtist(){
    int index;
    int frequent = 0;
    string null = "NONE";
    if(g_size == 0){
        return null;
    }
    for(int i = 0; i < g_size; i++){
        int count = 1;
        for(int j = i + 1; j < g_size; j++){
            if(g_songs[i].artist == g_songs[j].artist){
                count++;
            }
        }
        if(count >= frequent){
            frequent = count;
            index = i;
        }
    }
    return g_songs[index].artist;
}

int main(){
    string filename = "eplay.txt";
    readSongs(filename);
    cout << "g_capacity: " << g_capacity << endl << endl;
    cout << "g_size: " << g_size << endl << endl;
    cout << "g_song_names: [";
    for (int i = 0; i < g_size; i++) {
        cout << g_songs[i].name;
        if(i < g_size - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl<<"g_artist_names: [";
    for (int i = 0; i < g_size; i++) {
        cout << g_songs[i].artist;
        if(i < g_size - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl<<"g_song_durations: [";
    for (int i = 0; i < g_size; i++) {
        cout << g_songs[i].duration;
        if(i < g_size - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl<<"g_genres: [";
    for (int i = 0; i < g_size; i++) {
        cout << g_songs[i].genre;
        if(i < g_size - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
    
    int genreCount = 0;
    Song *gSongs = getGenreSongs("HipHop", genreCount);
    cout<<"[";
    for (int i = 0; i < genreCount; i++) {
        cout << gSongs[i].genre;
        if(i < genreCount - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl;

    int greater = 0;
    int less = 0;
    int equal = 0;
    Song *longSongs = getSongsFromDuration(3, greater, 0);
    Song *shortSongs = getSongsFromDuration(3, less, 1);
    Song *mediumSongs = getSongsFromDuration(3, equal, 2);

    cout<<"[";
    for (int i = 0; i < greater; i++) {
        cout << longSongs[i].name;
        if(i < greater - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl;

    cout<<"[";
    for (int i = 0; i < less; i++) {
        cout << shortSongs[i].name;
        if(i < less - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl;

    cout<<"[";
    for (int i = 0; i < equal; i++) {
        cout << mediumSongs[i].name;
        if(i < equal - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl;

    int newcount = 0;
    string *unique = getUniqueArtists(newcount);
    cout<<"[";
    for (int i = 0; i < newcount; i++) {
        cout << unique[i];
        if(i < newcount - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl;
    cout<<newcount<<endl;

    string favorite = getFavoriteArtist();
    cout<<endl<<favorite<<endl;

    return 0;
}

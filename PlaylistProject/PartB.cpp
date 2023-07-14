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
/*
    @param genre              :   A string representing a genre
    @param(&) genreCount      :   An integer that will keep track of the number of songs
    @return                   :   A pointer to a dynamically allocated array of strings
    @post                     :   Return a pointer to a dynamically allocated array of strings
                                  containing the names of the songs of given 'genre' and
                                  update 'genreCount' to be the number of songs found.
                                  Return a pointer to an empty dynamically allocated array
                                  if no songs are found of the given 'genre'
    
    For example : Let's say we have the following 'g_song_names':
                  ["Killshot", "Takeover", "Spectre", "Ether", "No Title"]
                  
                  Let's say we have the following 'g_genres':
                  ["HipHop", "HipHop", "EDM", "HipHop", "JPop"]
                  
                  We try the following code with the above global-arrays:
                  int main(){
                    int count = 0;
                    string * genreSongs = getGenreSongs("HipHop", count);
                  }

                  In this case, 'genreSongs' will be pointing to the following:
                  ["Killshot", "Takeover", "Ether"]
                  The value of 'count' will be updated to 3 because there
                  are three "HipHop" songs on the playlist
*/
string *getGenreSongs(string genre, int &genreCount){
    string *gSongs = new string[g_number_of_songs];
    int num = 0;
    genreCount = 0;
    for(int i = 0; i < g_number_of_songs; i++){
        if(g_genres[i] == genre){
            genreCount ++;
            gSongs[num] = g_song_names[i];
            num++;
        }
    }
    return gSongs;
}

/*
    @param duration             :   The integer duration of the songs
    @param(&) durationsCount    :   An integer that will keep track of the number of songs
    @param filter               :   An integer(0, 1 or 2) representing the comparision filter
                                    0 = greater-than, 1 = less-than, 2 = equal-to
    @return                     :   A pointer to a dynamically allocated array of strings
    @post                       :   Return a pointer to a dynamically allocated array of strings
                                    of songs that are either greater-than, less-than or equal-to
                                    the given 'duration' based on given 'filter'. Update parameter
                                    'durationsCount' with the number of songs found. Return a
                                    pointer to an empty dynamically allocated array if no songs
                                    are found with the given parameters

    For example : Let's say we have the following 'g_song_names':
                  ["Major Crimes", "Never Fade Away", "Circus Minimus", "4aem", "Reaktion"]

                  Let's say we have the following 'g_song_durations':
                  [3, 4, 3, 5, 2]

                  We try the following code with the above global-arrays:
                  int main(){
                    int greater = 0;
                    int less = 0;
                    int equal = 0;
                    string * longSongs = getSongsFromDuration(3, greater, 0);
                    string * shortSongs = getSongsFromDuration(3, less, 1);
                    string * mediumSongs = getSongsFromDuration(3, equal, 2);
                  }

                  After running the above code, 'longSongs' will be:
                  ["Never Fade Away", "4aem"]
                  The value of 'greater' will be 2 because there are two songs
                  greater than 3 mins duration

                  Similarly, 'shortSongs' will be:
                  ["Reaktion"]
                  The value of 'less' will be 1 because there is only one song
                  less than 3 mins duration

                  Finally, 'mediumSongs' will be:
                  ["Major Crimes", "Circus Minimus"]
                  The value of 'equal' will be 2 because there are 2 songs
                  equal to 3 mins duration
*/
string *getSongsFromDuration(int duration, int &durationsCount, int filter){
    string *criteria = new string[g_number_of_songs];
    durationsCount = 0;
    for(int i = 0; i < g_number_of_songs; i++){
        if(filter == 0 && g_song_durations[i] > duration){
            criteria[durationsCount] = g_song_names[i];
            durationsCount ++;
        }
        else if(filter == 1 && g_song_durations[i] < duration){
            criteria[durationsCount] = g_song_names[i];
            durationsCount ++;
        }
        else if(filter == 2 && g_song_durations[i] == duration){
            criteria[durationsCount] = g_song_names[i];
            durationsCount ++;
        }
    }
    return criteria;
}

/*
    @param      :   An integer that will keep track of unique artists
    @return     :   A pointer to a dynamically allocated array of strings
    @post       :   Return a pointer to a dynamically allocated array of strings
                    containing the names of unique artists in 'g_artist_names'
                    and update 'uniqueCount' parameter to be the number of
                    unique artists found
    
    For example : Let's say we have the following 'g_artist_names':
                  ["Eminem", "Eminem", "Jay Z", "Jay Z", "Nas"]
                  
                  We try the following code with this 'g_artist_names':
                  int main(){
                    int count = 0;
                    string * uniques = getUniqueArtists(count);
                  }

                  In this case, 'uniques' will be pointing to the following:
                  ["Eminem", "Jay Z", "Nas"]
                  The value of 'count' will be updated to 3 because there
                  are three unique artists on the playlist
*/
    
string *getUniqueArtists(int &uniqueCount){
    //implement boolean
    uniqueCount = 0;
    bool fact;
    string *unique = new string[g_number_of_songs];
    for(int i = 0; i < g_number_of_songs; i++){
        fact = true;
        for(int j = 0; j < uniqueCount; j++){
            if(g_artist_names[i] == unique[j]){
                fact = false;
            }
        }
        if(fact == true){
            unique[uniqueCount] = g_artist_names[i];
            uniqueCount++;
        }
    }
    return unique;
}

/*
 string * getUniqueArtists(int &uniqueCount){
     bool isUnique;
     uniqueCount = 0;
     string * result = new string[g_number_of_songs];
     for(int i = 0; i < g_number_of_songs; i++){
     isUnique = true ;
         for(int j = 0; j < uniqueCount; j++){
             if(g_artist_names[i] == result[j]){
                 isUnique = false;
             }
         }
         if(isUnique == false){
             result[uniqueCount] = g_artist_names[i];
             uniqueCount++;
         }
     }
     return result;
 }
 */

/*
    @return     :   A string with the artist with most songs in playlist
    @post       :   Find the artist with the most songs in the playlist
                    If there are multiple such artists, return any one of them.
                    Return "NONE" if the playlist is empty

    For example : Let's say we have the following 'g_artist_names':
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Kendrick"]
                  The favorite artist here is "Kendrick" because he has 3 songs
                  However, consider the following 'g_artist_names':
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Drake"]
                  In this case, the favorite artist is either "J.Cole" or "Kendrick"
                  because both artists have 2 songs which is greater than any
                  other artists in the playlist
*/
string getFavoriteArtist(){
    int index;
    int frequent = 0;
    string null = "NONE";
    if(g_number_of_songs == 0){
        return null;
    }
    for(int i = 0; i < g_number_of_songs; i++){
        int count = 1;
        for(int j = i + 1; j < g_number_of_songs; j++){
            if(g_artist_names[i] == g_artist_names[j]){
                count++;
            }
        }
        if(count >= frequent){
            frequent = count;
            index = i;
        }
    }
    return g_artist_names[index];
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
    
    int genreCount = 0;
    string *gSongs = getGenreSongs("HipHop", genreCount);
    cout<<"[";
    for (int i = 0; i < genreCount; i++) {
        cout << gSongs[i];
        if(i < genreCount - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl;
    
    int greater = 0;
    int less = 0;
    int equal = 0;
    string * longSongs = getSongsFromDuration(3, greater, 0);
    string * shortSongs = getSongsFromDuration(3, less, 1);
    string * mediumSongs = getSongsFromDuration(3, equal, 2);
    
    cout<<"[";
    for (int i = 0; i < greater; i++) {
        cout << longSongs[i];
        if(i < greater - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl;
    
    cout<<"[";
    for (int i = 0; i < less; i++) {
        cout << shortSongs[i];
        if(i < less - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl;
    
    cout<<"[";
    for (int i = 0; i < equal; i++) {
        cout << mediumSongs[i];
        if(i < equal - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl<<endl;
    
    int newcount = 0;
    string * unique = getUniqueArtists(newcount);
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
    cout<<endl<<favorite;
    
    return 0;
}

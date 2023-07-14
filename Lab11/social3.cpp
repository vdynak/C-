#include <iostream>
#include <string>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    Profile(string usrn, string dspn);
    Profile();
    string getUsername();
    string getFullName();
    void setDisplayName(string dspn);
};

struct Post{
  string username;
  string message;
};

class Network{
private:
  static const int MAX_USERS = 20;
  int numUsers;
  Profile profiles[MAX_USERS];
  bool following[MAX_USERS][MAX_USERS];
  int findID (string usrn);
  static const int MAX_POSTS = 100;
  int numPosts;
  Post posts[MAX_POSTS];
public:
  Network();
  bool addUser(string usrn, string dspn);
  bool follow(string usrn1, string usrn2);
  bool writePost(string usrn, string msg);
  bool printTimeline(string usrn);
  void printDot();
};

int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}

Profile::Profile(string usrn, string dspn){
    username = usrn;
    displayname = dspn;
}

Profile::Profile() : username(""), displayname("") {}

string Profile::getUsername(){
    return username;
}

string Profile::getFullName(){
    string full = displayname + "(@" + username + ")";
    return full;
}

void Profile::setDisplayName(string dspn){
    displayname = dspn;
}

//Network::Network() : numUsers(0) {}
Network::Network(){
    numUsers = 0;
    for(int i = 0; i < MAX_USERS; i++){ //initializing every row and column of the 2D array, false
        for(int j = 0; j < MAX_USERS; j++){
            following[i][j] = false;
        }
    }
}

int Network::findID(string usrn){
    for(int i = 0; i < numUsers; i++){
        if(profiles[i].getUsername() == usrn){
            return i;
        }
    }
    return -1;
}

bool Network::addUser(string usrn, string dspn){
    if(findID(usrn) == -1 && numUsers < MAX_USERS){
        for(int i = 0; i < usrn.length(); i++){
            if(!isalpha(usrn[i]) && (!isdigit(usrn[i]))){
                return false;
            }
        }
        Profile n_user(usrn, dspn);
        profiles[numUsers] = n_user;
        numUsers++;
        return true;
    }
    return false;
}
/*
 Make 'usrn1' follow 'usrn2' (if both usernames are in the network). Return true if success (if both usernames exist), otherwise return false.

 Essentially, determine if both usernames are found in the array.
 */
bool Network::follow(string usrn1, string usrn2){
    int usrn1index = findID(usrn1);
    int usrn2index = findID(usrn2);
    if(usrn1index != -1 && usrn2index != -1){
        following[usrn1index][usrn2index] = true;
        return true;
    }
    return false;
}

/*
 digraph {
   "@mario"
   "@luigi"
   "@yoshi"

   "@mario" -> "@luigi"
   "@luigi" -> "@mario"
   "@luigi" -> "@yoshi"
   "@yoshi" -> "@mario"
 }
 */
void Network::printDot(){
    cout<<"digraph {"<<endl;
    for(int i = 0; i < numUsers; i++){
        cout<<"\"@"<<profiles[i].getUsername()<<"\""<<endl;
    }
    cout<<endl;
    for(int i = 0; i < numUsers; i++){
        for(int j = 0; j <numUsers; j++){
            if(following[i][j] == true){
                cout<<"\"@"<<profiles[i].getUsername()<<"\""<<" -> "<<"\"@"<<profiles[j].getUsername()<<endl; // \ to print "
            }
        }
    }
    cout<<"}"<<endl;
}

bool Network::writePost(string usrn, string msg){
    int userindex = findID(usrn);
    if(userindex != -1 && numPosts != MAX_POSTS){
        posts[numPosts].username = usrn;
        posts[numPosts].message = msg;
        numPosts++;
        return true;
    }
    return false;
}

bool Network::printTimeline(string usrn){
    int userindex = findID(usrn);
    if(userindex != -1){
        for(int i = numPosts - 1; i >= 0; i--){
            Post example = posts[i];
            int exampleusrn = findID(example.username);
            if(example.username == usrn){
                cout<<profiles[userindex].getFullName()<<": "<<example.message<<endl;
            }
            else if(following[userindex][exampleusrn]){
                cout<<profiles[exampleusrn].getFullName()<<": "<<example.message<<endl;
            }
        }
        return true;
    }
    return false;
}

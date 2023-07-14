//Adds the Network class which allows new users to be added to the network. Users are added if the username is composed of letters and numbers, does not already exist, or if the new user number is below MAX_USERS.

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

class Network{
private:
  static const int MAX_USERS = 20;
  int numUsers;
  Profile profiles[MAX_USERS];
  int findID (string usrn);
public:
  Network();
  bool addUser(string usrn, string dspn);
};

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i),
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
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

Network::Network() : numUsers(0) {}

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

// Attempts to sign up a new user with specified username and displayname
// return true if the operation was successful, otherwise return false
/*
 addUser(usrn, dspn) is the central function for the class. It allows adding new users. This function receives the username and display name of a new user, the new user can be signed up only if the following conditions are met:
 the new username usrn must be a non-empty alphanumeric string,
 there is no other users in the network with the same username,
 the array profiles is not full.
 If the above conditions are met, the new user should be added to the array profiles and the function should return true, otherwise don’t add the user and return false, thus indicating that the operation failed.
 */

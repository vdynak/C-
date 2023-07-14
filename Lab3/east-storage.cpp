 //The program reads in the Current_Reservoir_Levels data file and prompts the user for a date. While the program reads compares if the dates from the tsv file match the user-inputted date, it returns the value of the East Basin storage.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;
int main(){
    
    string date;
    double eastSt;
    string userdate;
    
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    
    string junk;
    getline(fin, junk);
    
    cout<<"Enter date: ";
    cin>>userdate;
    
    while(fin >> date >> eastSt){
        fin.ignore(INT_MAX, '\n');
        if(date == userdate){
            cout<<"East basin storage: "<<eastSt<< " billion gallons"<<endl;
        }
    }
    fin.close();
    return 0;
}

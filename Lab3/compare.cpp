//This program reads in the Current_Reservoir_Levels file (made possible with the fstream library). An aray of a fixed size is initialized for the first five columns, which are filled with a foor loop and fin>>. The user is then prompted to enter a starting and ending date in 2018, in which the index of the value of the start date is assigned to temporary and the index of the end value is assigned to temporary end. Lastly, while the dates in the file are in between the start/end indexes, the temporary variable accesses that index of the East/West basin to compare the elevations. If west has a higher elevation, WEST is printed; otherwise, EAST is printed. Temporary is incremented to finish the loop.

#include <iostream>
#include <fstream>
#include <string>
#include <climits>
using namespace std;
int main(){
    string junk;
    string start;
    string end;
    int temporary;
    int temporaryend;
    const string SPACE = " ";
    const int SIZE = 365;
    string dates[SIZE];
    double eastSt[SIZE];
    double eastEl[SIZE];
    double westSt[SIZE];
    double westEl[SIZE];

    ifstream fin("Current_Reservoir_Levels.tsv");
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
    cout<<"Enter starting date: ";
    cin>>start;
    cout<<"Enter ending date: ";
    cin>>end;
    for (int i = 0; i < 365; i++){
        if (dates[i] == start){
            temporary = i;
        }
    }
    for(int i = 0; i < 365; i++){
        if(dates[i] == end){
            temporaryend = i;
        }
    }
    while(dates[temporary] <= dates[temporaryend]){
        if(eastEl[temporary] > westEl[temporary]){
            cout<<dates[temporary]<<SPACE<<"East"<<endl;
        }
        else if(eastEl[temporary] < westEl[temporary]){
            cout<<dates[temporary]<<SPACE<<"West"<<endl;
        }
        else if(eastEl[temporary] == westEl[temporary]){
            cout<<dates[temporary]<<SPACE<<"Equal"<<endl;
        }
        temporary = temporary + 1;
    }
    return 0;
}


//Testing array creation by row
//#include  <iostream>
//#include  <fstream>
//#include  <string>
//using namespace std;
//int main()
//{
//    string line;
//    string junk;
//    string start;
//    string end;
//    int i = 0;
//    const int SIZE = 100000;
//    string arr[SIZE];
//    cout<<"Enter starting date: ";
//    cin>>start;
//    cout<<"Enter ending date: ";
//    cin>>end;
//    ifstream fin("Current_Reservoir_Levels.tsv");
//    if(fin.is_open())
//    {
//        getline(fin, junk);
//        while(!fin.eof())
//        {
//            getline(fin, line);
//            arr[i]=line;
//            i++;
//        }
//        //fin.close();
//    }
//    else{
//        cerr<<"Couldn't open the file"<<endl;
//        exit(1);
//    }
//    for(int j=0;j<i;j++)
//    {
//        cout<<arr[j]<<endl;
//    }
//    return 0;
//}

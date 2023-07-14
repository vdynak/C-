//The program asks to find the minimum and maximum values of the East Basin storage. Therefore, min is assigned to the highest value limit and max is assigned to the lowest value limit, part of the climits library. The program will read the file line by line for the East Basin storage. Starting with the first line, if the storage is greater than the maximum (which is initialized at a large negative value), it will assign the first value in this category to max. Additionally, since the first eastSt value is less than the initialized min, it will also take on the first value in this category. Afterwards, each following data value will pass through the if conditionals, in which case if the eastSt is greater than max --> it is the new max, if the eastSt is less than the min --> it is the new min.

#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
int main(){
    ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        cerr<<"File cannot be opened for reading. "<<endl;
        exit(1);
    }
    string junk;
    getline(fin,junk);

    string date;
    double eastSt;
//    double eastEl;
//    double westSt;
//    double westEl;
    double min = INT_MAX; //2147483647
    double max = INT_MIN; //-2147483648
    while(fin >> date >> eastSt){
        fin.ignore(INT_MAX, '\n');
        if(eastSt > max){
            max = eastSt;
        }
        else if(eastSt < min){
            min = eastSt;
        }
//        else if(min > max){ //not necessary with the given data values
//            max = min;
        }
        cout<<"minimum storage in East Basin: "<<min<<" billion gallons"<<endl;
        cout<<"MAXimum storage in East Basin: "<<max<<" billion gallons"<<endl;
        fin.close();
        return 0;
    }

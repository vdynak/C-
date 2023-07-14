// Prompts the user for a month and year. Returns the number of days in that month while considering leap years.

#include <iostream>
using namespace std;
int main(){
    int year,month;
    cout<<"Enter year: ";
    cin>>year;
    cout<<"Enter month: ";
    cin>>month;
    if((year%4==0) and (not(year%100==0)or(year%400==0))){
        if(month == 2){
            cout<<"29 days"<<endl;
        }
        else if((month == 1)||(month == 3)||(month == 5) || (month == 7) || (month == 8)||(month == 10)|| (month == 12)){
            cout<<"31 days"<<endl;
        }
        else if((month == 4)||(month == 6)||(month == 9)||(month == 11)){
            cout<<"30 days"<<endl;
        }
    }
    else if((month == 1)||(month == 3)||(month == 5) || (month == 7) || (month == 8)||(month == 10)|| (month == 12)){
        cout<<"31 days"<<endl;
    }
    else if(month == 2){
        cout<<"28 days"<<endl;
    }
    else if((month == 4)||(month == 6)||(month == 9)||(month == 11)){
        cout<<"30 days"<<endl;
    }
    return 0;
}

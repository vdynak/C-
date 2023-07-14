//The minutesSinceMidnight calculates the time that has elapsed from midnight by multiplying the hours component of the Time object by 60 and adding it to the number of minutes of that object.
//The minutesUntil function takes two parameters of class Time, earlier and later, which determines how far apart the times are from each other. The minutesSinceMidnight funcrion is used to determine how far each time is from midnight. If the earlier time happens to be later than the later time (as specified in the paramter) and either the hours and minutes, just hours, or just minutes are greater, then the difference is multiplied by -1. Otherwise the difference is returned.


#include <iostream>
using namespace std;

class Time {
public:
    int h;
    int m;
};

//The first function should return the number of minutes from 0:00AM until time.
int minutesSinceMidnight(Time time){
    int hournum = time.h * 60;
    return hournum + time.m;
}
//The second function should receive two Time arguments earlier and later and report how many minutes separate the two moments. For example, when passing 10:30AM and 1:40PM:
int minutesUntil(Time earlier, Time later){
    int onemid = minutesSinceMidnight(earlier);
    int twomid = minutesSinceMidnight(later);
    if(onemid < twomid){
        return (onemid - twomid) * -1;
    }
    return (onemid - twomid) * -1;
}

int main(){
    Time one;
    Time two;
    cout<<"Enter first time: "<<endl;
    cin>>one.h>>one.m;
    cout<<"Enter second time: "<<endl;
    cin>>two.h>>two.m;
    cout<<"Thee moments of time are "<<minutesSinceMidnight(one)<<" and "<<minutesSinceMidnight(two)<<" after midnight."<<endl;
    cout<<"The interval between them is "<<minutesUntil(one, two)<<" minutes."<<endl;
}

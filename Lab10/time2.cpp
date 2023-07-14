//The minutesSinceMidnight calculates the time that has elapsed from midnight by multiplying the hours component of the Time object by 60 and adding it to the number of minutes of that object.
 //The minutesUntil function takes two parameters of class Time, earlier and later, which determines how far apart the times are from each other. The minutesSinceMidnight funcrion is used to determine how far each time is from midnight. If the earlier time happens to be later than the later time (as specified in the paramter) and either the hours and minutes, just hours, or just minutes are greater, then the difference is multiplied by -1. Otherwise the difference is returned.
 //The Time addMinutes function returns an object of class Time that provides an updated time of the original parameter Time time0 incremented by the second parameter value (the number of minutes). The function turns the original Time parameter in the form time0.h and time0.m to minutes. Then, it adds the incrementing minutes to this value. The new value is divided by 60 and assigned to time0.h and the new value undergoes the modulus operator to have an updated minute value assigned to time0.m. The updated time0 is returned.

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

Time addMinutes(Time time0, int min){
    int minutesonly = time0.h * 60 + time0.m;
    int minutes = minutesonly + min;
    time0.h = minutes / 60;
    time0.m = minutes % 60;
    return time0;
}

/*
 addMinutes({8, 10}, 75)
 should return {9, 25}
 */

int main(){
    Time one;
    Time two;
    Time sample = {8,10};
    cout<<"Enter first time: "<<endl;
    cin>>one.h>>one.m;
    cout<<"Enter second time: "<<endl;
    cin>>two.h>>two.m;
    cout<<"Thee moments of time are "<<minutesSinceMidnight(one)<<" and "<<minutesSinceMidnight(two)<<" after midnight."<<endl;
    cout<<"The interval between them is "<<minutesUntil(one, two)<<" minutes."<<endl;
    Time solution = addMinutes(sample,75);
    cout<<"New time: "<<solution.h<<":"<<solution.m<<endl;
}

//The minutesSinceMidnight calculates the time that has elapsed from midnight by multiplying the hours component of the Time object by 60 and adding it to the number of minutes of that object.
 //The minutesUntil function takes two parameters of class Time, earlier and later, which determines how far apart the times are from each other. The minutesSinceMidnight funcrion is used to determine how far each time is from midnight. If the earlier time happens to be later than the later time (as specified in the paramter) and either the hours and minutes, just hours, or just minutes are greater, then the difference is multiplied by -1. Otherwise the difference is returned.
 //The Time addMinutes function returns an object of class Time that provides an updated time of the original parameter Time time0 incremented by the second parameter value (the number of minutes). The function turns the original Time parameter in the form time0.h and time0.m to minutes. Then, it adds the incrementing minutes to this value. The new value is divided by 60 and assigned to time0.h and the new value undergoes the modulus operator to have an updated minute value assigned to time0.m. The updated time0 is returned.
 //The void printTimeSlot(TimeSlot ts), parameters: object ts of TimeSlot class, which includes movie and startTime (respective Movie and Time class), calculates endtime by calling the addMinutes function (parameters are filled with the members of the object of each class), function prints in the format "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]"
 //The TimeSlot scheduleAfter function has parameters that are objects belonging to the TimeSlot and Movie class respectively. To create a new time for an expected return value of a TimeSlot object a new variable of class Time is created and assigned to the return of the function addMinutes accessing members of the oiginal actual parameters. Then, newTime is initialized with the actual paramter of nextMovie, followed by the new anticipated time.

#include <iostream>
using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Time {
public:
    int h;
    int m;
};

class Movie {
public:
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot {
public:
    Movie movie;     // what movie
    Time startTime;  // when it starts
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

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}
/*
 addMinutes({8, 10}, 75)
 should return {9, 25}
 */

void printTimeSlot(TimeSlot ts){
    Time endtime = addMinutes(ts.startTime, ts.movie.duration);
    //can't do ts.startTime + ts.movie.duration;
    printMovie(ts.movie);
    cout<<"[starts at "<<ts.startTime.h<<":"<<ts.startTime.m<<", ends by "<<endtime.h<<":"<<endtime.m<<"]"<<endl;
}

/*
 Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]
 The ending time is the starting time + movie duration.
 */

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    Time time1 = addMinutes(ts.startTime, ts.movie.duration);
    TimeSlot newTime = {nextMovie, time1};
    return newTime;
}

int main(){
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot daytime = {movie2, {12, 15}};
    TimeSlot evening = {movie2, {16, 45}};
    TimeSlot favorite = {movie1, {17,10}};
    TimeSlot leastfavorite = {movie2, {6, 45}};
    
    printTimeSlot(morning);
    printTimeSlot(daytime);
    printTimeSlot(evening);
    printTimeSlot(favorite);
    printTimeSlot(leastfavorite);
}

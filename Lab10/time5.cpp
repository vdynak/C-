//The minutesSinceMidnight calculates the time that has elapsed from midnight by multiplying the hours component of the Time object by 60 and adding it to the number of minutes of that object.
 // The minutesUntil function takes two parameters of class Time, earlier and later, which determines how far apart the times are from each other. The minutesSinceMidnight funcrion is used to determine how far each time is from midnight. If the earlier time happens to be later than the later time (as specified in the paramter) and either the hours and minutes, just hours, or just minutes are greater, then the difference is multiplied by -1. Otherwise the difference is returned.
 // The Time addMinutes function returns an object of class Time that provides an updated time of the original parameter Time time0 incremented by the second parameter value (the number of minutes). The function turns the original Time parameter in the form time0.h and time0.m to minutes. Then, it adds the incrementing minutes to this value. The new value is divided by 60 and assigned to time0.h and the new value undergoes the modulus operator to have an updated minute value assigned to time0.m. The updated time0 is returned.
 // The void printTimeSlot(TimeSlot ts), parameters: object ts of TimeSlot class, which includes movie and startTime (respective Movie and Time class), calculates endtime by calling the addMinutes function (parameters are filled with the members of the object of each class), function prints in the format "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]"
 // The TimeSlot scheduleAfter function has parameters that are objects belonging to the TimeSlot and Movie class respectively. To create a new time for an expected return value of a TimeSlot object a new variable of class Time is created and assigned to the return of the function addMinutes accessing members of the oiginal actual parameters. Then, newTime is initialized with the actual paramter of nextMovie, followed by the new anticipated time.

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

/*
 The function should produce and return a new TimeSlot for the movie nextMovie, scheduled immediately after the time slot ts.

 For example, if the movie scheduled in ts starts at 14:10 and lasts 120 minutes, then the time slot for the next movie should start at exactly 16:10.
 */

/*
 TimeSlot custom = {movie3, {10,30}};
 TimeSlot custom2 = {movie4, {11,30}};
 Movie movie3 = {"The Wolf of Wall Street", COMEDY, 180};
 Movie movie4 = {"5 Centimeters Per Second", DRAMA, 63};
 TimeSlot morning = {movie1, {9, 15}};
 TimeSlot daytime = {movie2, {12, 15}};
 Movie movie1 = {"Back to the Future", COMEDY, 116};
 Movie movie2 = {"Black Panther", ACTION, 134};
 The function should return true if the two time slots overlap, otherwise return false. (Take into account the starting times of the time slots and the duration of the scheduled movies.)

 Hint: You may use minutesUntil to check which time slot is earlier, then find the how long is the interval between their starting times. They overlap if the movie duration is greater than the interval between the time slots’ starting times. Alternatively, converting times into minutes since midnight can be a good idea as well.
 */

//Function determines whether the first parameter value comes before the second.
bool firstSecond(Time one, Time two){
    if(one.h == two.h){
        if(one.m < two.m){
            return true;
        }
    }
    if(one.h < two.h){
        return true;
    }
    return false;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    if(firstSecond(ts1.startTime,ts2.startTime)){ //if ts1 startTime comes first, then
        Time determine = addMinutes(ts1.startTime, ts1.movie.duration); //addMinutes creates an object of Time that reveals what the time would be when the first movie would end.
        if(firstSecond(ts2.startTime, determine)){ //if ts2 startTime is before the determined time of the end of the first movie, then the movies overlap.
            return true;
        }
    }
    else{
        Time determine = addMinutes(ts2.startTime, ts2.movie.duration); //if ts2 startTime comes first, then the new determined time is ts2.startTime plus the duration of the movie
        if(firstSecond(ts1.startTime, determine)){ //if the determined time comes after ts1 startTime movies overlap.
            return true;
        }
    }
    return false;
}

int main(){
    bool evaluate;
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"The Wolf of Wall Street", COMEDY, 180};
    Movie movie4 = {"5 Centimeters Per Second", DRAMA, 63};

    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot daytime = {movie2, {12, 15}};
    TimeSlot evening = {movie2, {16, 45}};
    TimeSlot favorite = {movie1, {17,10}};
    TimeSlot leastfavorite = {movie2, {6, 45}};
    TimeSlot custom = {movie3, {10,30}};
    TimeSlot custom2 = {movie4, {11,30}};
    
    
    printTimeSlot(morning);
    printTimeSlot(daytime);
    printTimeSlot(evening);
    printTimeSlot(favorite);
    printTimeSlot(leastfavorite);
    evaluate = timeOverlap(custom, custom2);
    if(evaluate == 1){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    //TimeSlot update = scheduleAfter(morning, movie1);
    
}

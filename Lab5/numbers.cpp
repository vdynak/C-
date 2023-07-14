//numbers.cpp, added isPrime() function, added nextPrime(), added countPrimes(), added isTwinPrime(), added nextTwinPrime(), added largestTwinPrime()

#include <iostream>
using namespace std;

bool isDivisibleBy(int, int);
bool isPrime(int);
int nextPrime(int);
int countPrimes(int,int);
bool isTwinPrime(int);
int nextTwinPrime(int);
int largestTwinPrime(int, int);

int main(){
        int start;
        int end;
        cout<<"Enter the start of the range: ";
        cin>>start;
        cout<<"Enter the end of the range: ";
        cin>>end;
        int evaluate = largestTwinPrime(start,end);
        cout<<evaluate<< " is the largest twin prime in the range."<<endl;
}


bool isDivisibleBy(int n, int d){
    if (d != 0 && n % d == 0){
        return true;
    }
    else{
        return false;
    }
}

bool isPrime(int n){
    int factors = 0;
    if(n <= 1){
        return false;
    }
    for(int i = 2; i <= n; i++){
        if((n % i == 0) && (i != n)){
            factors ++;
        }
    }
    if(factors >= 1){
        return false;
    }
    return true;
}

int nextPrime(int n){ //determine what to do when number is 1, function requires two returns to prevent void check
    if(n <= 1){ // 2 is the first prime number
        return 2;
    }
    int checkcase = n; //ex: 5,
    bool end = false;
    while(!end){
        checkcase ++; // 6, 7
        if(isPrime(checkcase)){ //false, while continues, true, end = true, return 7 --> next prime number of 5
            end = true;
        }
    }
    return checkcase;
}

int countPrimes(int a, int b){ //count the number of primes in range, inclusive
    int count = 0;
    for(int start = a; start <= b; start++){
        if(isPrime(start)){
            count++;
        }
    }
    return count;
}

bool isTwinPrime(int n){
    int previous = n - 2;
    int next = n + 2;
    if(n == 2){
        return false;
    }
    if(isPrime(n)){
        if((isPrime(previous)) || (isPrime(next))){
            return true;
        }
        else if((isPrime(previous)) && (isPrime(next))){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}

int nextTwinPrime(int n){ //lab does not specify is n must be a prime number
    int checkcase = n;
    bool end = false;
    while(!end){
        checkcase ++;
        if((isPrime(checkcase) && isPrime(checkcase - 2)) || (isPrime(checkcase) && isPrime(checkcase + 2))){
            end = true;
        }
    }
    return checkcase;
}
int largestTwinPrime(int a, int b){
    for (int max = b; max >= a; max--){ //starting backwards, less steps, since looking for greater number
        if(isPrime(max)){
            if(isTwinPrime(max)){
                return max;
            }
        }
    }
    return -1;
}

//this code worked except for when it came to larger numbers, so start from back?
//int largestTwinPrime(int a, int b){
//    int max = a;
//    for(int i = a; i <= b; i++){
//        if(isTwinPrime(i) && i > max){
//            max = i;
//        }
//    }
//    if(max == a && !(isTwinPrime(max))){
//        return -1;
//    }
//    return max;
//}

/*
 for(int checkcase = a; checkcase <= b; checkcase ++){
    int twincheck = checkcase + 2; twincheck = will be used to determine if 2 ahead of the current integer is prime --> if prime, it is the twin prime of the int
    if(isPrime(checkcase) && (isPrime(twincheck))){only incremeneting, twin prime is true when n + 2 or n - 2 is prime.
        if(twincheck <= b){
            max = twincheck;
        }
        else if(max == a){ DETERMINE THIS PART?
            return -1;
        }
        else{
            max = checkcase;
        }
    }
}
return max;

 (5,13)
 max = 5
 5 and 7 are prime and 7 is less than 13, max = 7
 6 and 8 are not prime, no conditional executed
 7 and 9 are prime, 9 is less than 13, max = 9
 8 and 10 are not prime, no conditional executed
 9 and 11 are prime, 11 is less than 13, max = 11
 10 and 12 are not prime --
 11 and 13 are prime, 13 is less than or EQUAL to 13, max = 13

 */

//Based on the Coord3D class, a length function is created to determine the length of a vector in a 3D plane. The length function has a pointer to the instance of a Coord3D object; therefore, the length function must dereference this parameter for each class member to take the square root of the sum of all three values individually squared and then added together.
//Pt2: Holds a function fartherfromOrigin which has a return turn type of the Coord3D object, the two parameters are pointers to the first Point and second Point passed. Within the function, a double variable for the first and second distance are created and hold the length of p1 and p2, by calling the length function. The parameter of the length call is the Point itself as the length function "transforms" it into the pointer of that Point. Lastly, if the first Point has a greater distance, the first Point is returned; otherwise, the opposite applies.

#include <iostream>
#include <cmath> //square root
using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
}; //classes end in semicolons

//Write a program 3d-space.cpp, in which you define a function length() that receives the coordinates of a point P passed as a pointer, and computes the distance from the origin to the point P:
//length of the vector = square root of x^2 + y^2 + z^2
double length(Coord3D *p){
    double sum = pow(p->x, 2) + pow(p->y, 2) + pow(p->z, 2); //-> notation used instead of (*p).x, same meaning
    return sqrt(sum);
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    double firstdistance = length(p1); //pass p1 as the parameter for length is a pointer for this value, dereferenced in length function
    double seconddistance = length(p2);
    if(firstdistance > seconddistance){
        return p1;
    }
    else{
        return p2;
    }
}
//the return has to be the value itself, not the distance; therefore, it would have to return p1 or p2.

int main(){
        Coord3D pointP = {10, 20, 30};
        Coord3D pointQ = {-20, 21, -22};

        cout << "Address of P: " << &pointP << endl;
        cout << "Address of Q: " << &pointQ << endl << endl;
        //cout<< "P" << length(&pointP) << endl << "Q" << length(&pointQ)<< endl;

        Coord3D * ans = fartherFromOrigin(&pointP, &pointQ); //ans is initialized as a pointer of the result from fartherFromOrigin; it will either be the address of the object holding p1 or p2, respectively pointP, point Q
       
        cout << "ans = " << ans << endl; // So which point is farther?, P is furthest
}

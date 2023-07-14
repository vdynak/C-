//Based on the Coord3D class, a length function is created to determine the length of a vector in a 3D plane. The length function has a pointer to the instance of a Coord3D object; therefore, the length function must dereference this parameter for each class member to take the square root of the sum of all three values individually squared and then added together.

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

int main(){
    Coord3D pointP = {10, 20, 30};
    cout << length(&pointP) << endl; // would print 37.4166
}

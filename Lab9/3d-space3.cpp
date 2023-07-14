//Based on the Coord3D class, a length function is created to determine the length of a vector in a 3D plane. The length function has a pointer to the instance of a Coord3D object; therefore, the length function must dereference this parameter for each class member to take the square root of the sum of all three values individually squared and then added together.
//Pt2: Holds a function fartherfromOrigin which has a return turn type of the Coord3D object, the two parameters are pointers to the first Point and second Point passed. Within the function, a double variable for the first and second distance are created and hold the length of p1 and p2, by calling the length function. The parameter of the length call is the Point itself as the length function "transforms" it into the pointer of that Point. Lastly, if the first Point has a greater distance, the first Point is returned; otherwise, the opposite applies.
//Pt3: void Move function has two pointer parameters and one value parameter; the pointer parameters are part of Coord#D, ppos points to the position value, pvel points to the velocity value. Dereference the x, y, and z member of the position pointer to update it to the value of x added to the value of x velocity multipled by the change in time. Does not return a value; instead it updates the actual values of x, y, and z of each Point.

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

void move(Coord3D *ppos, Coord3D *pvel, double dt){
    ppos->x = ppos->x + pvel->x * dt; //To calculate the object's new position, after elapsed time
    ppos->y = ppos->y + pvel->y * dt;
    ppos->z = ppos->z + pvel->z * dt;
}

int main(){
        Coord3D pos = {0, 0, 100.0};
        Coord3D vel = {1, -5, 0.2};

        move(&pos, &vel, 2.0); // object pos gets changed
        cout << pos.x << " " << pos.y << " " << pos.z << endl;
        // prints: 2 -10 100.4
}

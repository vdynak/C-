//The program prompts the user to enter an integer value for width and height. To create a 3 by 3 checkerboard, a constant POSSIBLE is created with a value of 6, because there are 2 options that can be printed (either spaces or stars) and each of them are to be printed in a series of 3. Additionally, the checkerboard is intended to start with 3 x 3 stars; so, two nested loops, outter rows and inner columns are created, each starting at 0, row being less than height and col being less than width, incremented by 1 each iteration. Inzide the nested loop, is an if conditional: if the row remainder after being divided by 6 is less than 3 AND the col meets the same condition, a star is printed. If this condition isn't satisfied, stars can still be printed if the row and col when divided by 6 have a remainder greater than or equal to 3. By including this second conditional, the pattern of rows starting with stars or spaces is created because for each iteration, the row is incremented only when the col loop has reached width - 1. For example, in the first full interation, row = 0; therefore, the second condition will never be true, causing the spaces to be printed in the horizontal plane instead. Lastly, each row does not necessarily have to end in a series of three printed characters because it is bounded by the <height and <width parameters in the nested loops.

#include <iostream>
using namespace std;
int main(){
    int width;
    int height;
    const int POSSIBLE = 6; //6 is used because there are two options of patterns, each with 3 "characters" printed in them; therefore, 2 x 3 = 6
    const string SYMBOL = "*";
    const string SPACE = " ";
    cout<<"Input width: ";
    cin>>width;
    cout<<"Input height: ";
    cin>>height;
    cout<<"Shape: "<<endl;
    for (int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            if((row % POSSIBLE < 3 && col % POSSIBLE < 3) || (row % POSSIBLE >= 3 && col % POSSIBLE >=3)){ //by including the row % possible in the second condition, you allow for the spaces to be printed between each section of three stars. In the first full interation, row = 0; therefore, the second condition will never be true, causing the spaces to be printed in the horizontal plane instead.
                cout<<SYMBOL;
            }
            else{
                cout<<SPACE;
            }
        }
        cout<<endl;
    }
    return 0;
}

//example to work from
/*
 ***   ***   ***   ***   ***
 ***   ***   ***   ***   ***
 ***   ***   ***   ***   ***
    ***   ***   ***   ***
    ***   ***   ***   ***
    ***   ***   ***   ***
 ***   ***   ***   ***   ***
 ***   ***   ***   ***   ***
 ***   ***   ***   ***   ***
 */

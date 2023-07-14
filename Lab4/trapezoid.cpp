//The program begins with the declaration of width, height variables (which are initialized to user input) and SYMBOL, SPACE constants. For efficiency, the program first checks if the user parameters could create a trapezoid, meaning that when the width is even, the height must be greater than half the width and when the width is odd the height must be greater than one more than half the width. Afterwards, a for loop that repeats for the inputted value of height is responsible for creating three seperate triangles. The first nested loop starts at line 1 and by the end of the first loop, an increasing triangle shape is created with the SPACE value. The second nested loop creates a decreasing triangle of stars. The third nested loop also creates a decreasing triangle of stars; therefore, the parameter for length is divided to be repeated for the width/2 and with each line, the number of stars printed decreasing by 1. In this case, the order of where the nested loops are placed is extremely important as the first shape's orientation builds the beginning foundation for the next shape printed.

#include <iostream>
#include <string>
using namespace std;
int main(){
    int width;
    int height;
    const string SYMBOL = "*";
    const string SPACE = " ";
    cout<<"Input width: ";
    cin>>width;
    cout<<"Input height: ";
    cin>>height;
    //First determine what makes it an impossible shape
    if((width % 2 == 0 && height > width/2) || (width % 2 == 1 && height > width/2 + 1)){
        cout<<"Impossible shape!"<<endl;
    }
    else{
        cout<<"Shape: "<<endl;
        //code creates an increasing triangle with spaces, followed by a decreasing triangle, and another decreasing triangle --> decreasing triangles are next to each other; therefore, it takes on the right shape without any other changes.
        if(height != 1){
            for(int rows = 0; rows < height; rows++){ //row 2
                for(int col = 1; col <= rows; col++){ //2 spaces
                    cout<<SPACE;
                }
                if(width % 2 == 0){
                    for(int stars = rows; stars < width/2; stars ++){ // stars = 2, continues until 6, prints 4 stars
                        cout<<SYMBOL;
                    }
                    for(int stars = rows; stars < width/2; stars++){ // stars = 2, continues until 6, prints 4 stars
                        cout<<SYMBOL;
                    }
                }
                else if(width % 2 == 1){
                    for(int stars = rows; stars <= width/2; stars ++){ // stars = 2, continues until 6, prints 4 stars
                        cout<<SYMBOL;
                    }
                    for(int stars = rows; stars < width/2; stars++){ // stars = 2, continues until 6, prints 4 stars
                        cout<<SYMBOL;
                    }
                }
                cout<<endl; //new line
            }
        }
        else if(height = 1){
            for(int i = 0; i < width; i++){
                cout<<SYMBOL;
            }
            cout<<endl;
        }
    }
    return 0;
}

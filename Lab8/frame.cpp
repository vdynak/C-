//Creates a white, non-filled box frame by fillign the area equal to the wfourth and hfourths value but remaining within the constraints established in the previous lab.

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
    char c;
    int x;
    ifstream instr;
    instr.open("inImage.pgm");

    // read the header P2
    instr >> c;
    assert(c == 'P');
    instr >> c;
    assert(c == '2');

    // skip the comments (if any)
    while ((instr>>ws).peek() == '#') {
        instr.ignore(4096, '\n');
    }

    instr >> width;
    instr >> height;

    assert(width <= MAX_W);
    assert(height <= MAX_H);
    int max;
    instr >> max;
    assert(max == 255);

    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            instr >> image[row][col];
    instr.close();
    return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
    ofstream ostr;
    ostr.open("outImage.pgm");
    if (ostr.fail()) {
        cout << "Unable to write file\n";
        exit(1);
    };

    // print the header
    ostr << "P2" << endl;
    // width, height
    ostr << width << ' ';
    ostr << height << endl;
    ostr << 255 << endl;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            assert(image[row][col] < 256);
            assert(image[row][col] >= 0);
            ostr << image[row][col] << ' ';
            ostr << endl;
        }
    }
    ostr.close();
    return;
}

int main() {

    int img[MAX_H][MAX_W];
    int h, w;

    readImage(img, h, w); // read it from the file "inImage.pgm"
    // h and w were passed by reference and
    // now contain the dimensions of the picture
    // and the 2-dimesional array img contains the image data

    // Now we can manipulate the image the way we like
    // for example we copy its contents into a new array
    int out[MAX_H][MAX_W];

    double wfourths = w/4;
    double hfourths = h/4;

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            if(((row == hfourths || row == hfourths * 3) && (col >= wfourths && col <= wfourths * 3))){
                out[row][col] = 255;
            }
            else if(((col == wfourths || col == wfourths * 3) && (row >= hfourths && row <= hfourths * 3))){
                out[row][col] = 255;
            }
            else{
                out[row][col] = img[row][col];
            }
        }
    }
    // and save this new image to file "outImage.pgm"
    writeImage(out, h, w);

}

//create a matrix 4 by 4, label height respectively to row, and width with column. If your row is equal to hfourths or hfourths * 3, respective place on matrix, and the column is situated between column >= wfourths and <= wfourths * 3, create a line by replacing RGB values at this index with 255. If column is equal to wfourths or wfourths * 3, and the row is greater than or euqal to hfourths but less than hfourths * 3, replace the RGB values once again with an index of 255.

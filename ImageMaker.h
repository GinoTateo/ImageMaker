//
// Assignment Created by Varick Erickson
//

#ifndef IMAGEMAKER_H
#define IMAGEMAKER_H

#include <string>
#include <cmath>
#include <fstream>

const int MAX_WIDTH = 800;
const int MAX_HEIGHT = 800;
const int MAX_COLOR = 255;
enum COLOR { RED, GREEN, BLUE };

using namespace std;

//  Please put your pre and post comments in this file. See page 139 in the textbook.

class ImageMaker
{
public:


    ImageMaker();
    ImageMaker(string filename);

    // Opens image with filename and stores information into
    void LoadImage(string filename);
       /*
        * Function: LoadImage
        * Loads a ppm file into image matrix.
        *
        * Precondition:
        * Image object must be initialized.
        *
        * Postcondition:
        * Image is in matrix.
        */
    void SaveImage(string filename);
        /*
         * Function: SaveImage
         * Saves image matrix into ppm file.
         *
         * Precondition:
         * Image object must be initialized.
         *
         * Postcondition:
         * Image is in file.
         */

    // Size functions
    int GetWidth();
       /*
        * Function: GetWidth
        * Gets Width.
        *
        * Precondition:
        * Image object must be initialized.
        *
        * Postcondition:
        * returns width.
        */
    int GetHeight();
       /*
        * Function: GetHeight
        * Gets Height.
        *
        * Precondition:
        * Image object must be initialized.
        *
        * Postcondition:
        * returns Height.
        */
    void SetWidth(int width);
        /*
         * Function: SetWidth
         * Sets Width.
         *
         * Precondition:
         * Image object must be initialized.
         *
         * Postcondition:
         * width set.
         */
    void SetHeight(int height);
        /*
         * Function: GetWidth
         * sets Height.
         *
         * Precondition:
         * Image object must be initialized.
         *
         * Postcondition:
         * Height is set.
         */

    // Color functions
    int GetPenRed();
    int GetPenGreen();
    int GetPenBlue();
    void SetPenRed(int newR);
    void SetPenGreen(int newG);
    void SetPenBlue(int newB);
        /*
         * Function: Get/Set pen colors
         * Get/Set pen colors
         *
         * Precondition:
         * Image object must be initialized.
         * In rgb range(0-255).
         *
         * Postcondition:
         * Sets rgb value to pen.
         */

    // Drawing methods
    // These methods will use the current red, green, blue values of the pen
    void DrawPixel(int x, int y);
        /*
         * Function: DrawPixel
         * Draws on x,y Coordinates
         *
         * Precondition:
         * Image object must be initialized.
         *
         *
         * Postcondition:
         * Observable point drawn on image.
         */
    void DrawRectangle(int x1, int y1, int x2, int y2);
        /*
         * Function: DrawRectangle
         * Draws a rectangle
         *
         * Precondition:
         * Image object must be initialized.
         * Drawline must function
         *
         * Postcondition:
         * Observable rectangle drawn on image.
         */
    void DrawLine(int x1, int y1, int x2, int y2);
        /*
         * Function: DrawLine
         * Draws a line.
         *
         * Precondition:
         * Image object must be initialized.
         * DrawPixel must function.
         *
         * Postcondition:
         * Observable line drawn on image.
         */

private:
    string magic;
    int width;
    int height;
    int pen_red;    // Used by draw functions
    int pen_green;  // Used by draw functions
    int pen_blue;   // Used by draw functions
    bool PointInBounds(int x, int y);  // Not a bad idea to implement

               //   x          y
    short image[MAX_WIDTH][MAX_HEIGHT][3];
};

#endif //IMAGEMAKER_H

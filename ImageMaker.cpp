#include "ImageMaker.h"
#include "iostream"

// Your code goes here...
ImageMaker::ImageMaker() {

    //Default dimensions
    width = 0;
    height = 0;

    //Pen color black
    pen_red = 0;
    pen_green = 0;
    pen_blue = 0;

    //ppm type
    magic = "P3";

    //Sets image to white
    for(int i = 0; i<MAX_WIDTH;i++) {
        for (int j = 0; j < MAX_HEIGHT; j++) {
                image[i][j][RED] = 255;
                image[i][j][GREEN] = 255;
                image[i][j][BLUE] = 255;

        }
    }
}

ImageMaker::ImageMaker(string filename) {

    //Sets image to white
    for(int i = 0; i<MAX_WIDTH;i++) {
        for (int j = 0; j < MAX_HEIGHT; j++) {
                image[i][j][RED] = 255;
                image[i][j][GREEN] = 255;
                image[i][j][BLUE] = 255;

        }
    }

    LoadImage(filename);
}

void ImageMaker::LoadImage(string filename) {

    //Load file
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        int maxColor;

        file >> magic >> width >> height >> maxColor;

        // Error Checking
        if(magic != "P3")throw "Bad magic number";
        if(width < 0 || width > MAX_WIDTH)throw "Width out of bounds";
        if(height < 0 || height > MAX_HEIGHT)throw "Height out of bounds";
        if(maxColor != 255)throw "Max color range not 255";

        //Load image
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                for (int k = 0; k < 3; k++) {
                        //Write to image matrix
                        file >> image[i][j][k];
                        //Check for out of range value
                        if (image[i][j][k] > 255 || image[i][j][k] < 0 )throw "Color value invalid";
                }
            }
        }
    }
    else{
        throw "File failed to open";
    }
}

void ImageMaker::SaveImage(string filename) {

    ofstream file;
    file.open(filename);
    if(file.is_open()){
        // Error checking
        if(width == 0)throw "Image must have non-zero dimensions";
        if(height == 0)throw "Image must have non-zero dimensions";

        //Header info
        file << "P3" << endl << width << " " << height << endl << 255 << endl;

        // Image info matrix
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {

                    file << image[i][j][RED] << " ";
                    file << image[i][j][GREEN] << " ";
                    file << image[i][j][BLUE] << " ";

            }
        }
        file.close();
    }
    else{
        throw "File failed to open";
    }
}

int ImageMaker::GetWidth() {
    return width;
}

int ImageMaker::GetHeight() {
    return height;
}

void ImageMaker::SetWidth(int width) {
    if (width < 0 || width > MAX_WIDTH) {
        throw "Width out of bounds";
    }
    this->width = width;
}

void ImageMaker::SetHeight(int height) {
if(height < 0 || height > MAX_HEIGHT){
    throw "Height out of bounds";
}
    this->height = height;
}

int ImageMaker::GetPenRed() {
    return pen_red;
}

int ImageMaker::GetPenGreen() {
    return pen_green;
}

int ImageMaker::GetPenBlue() {
    return pen_blue;
}

void ImageMaker::SetPenRed(int newR) {
    if (newR < 0 || newR > MAX_COLOR) {
        throw "Color value invalid";
    }
    this->pen_red = newR;
}

void ImageMaker::SetPenGreen(int newG) {
    if (newG < 0 || newG > MAX_COLOR) {
        throw "Color value invalid";
    }
    this->pen_green = newG;
}

void ImageMaker::SetPenBlue(int newB) {
    if (newB < 0 || newB > MAX_COLOR) {
        throw "Color value invalid";
    }
    this->pen_blue = newB;
}

void ImageMaker::DrawPixel(int x, int y) {

    // Error Checking
    if (x > width || y > height) throw "Point out of bounds";
    if (x < 0 || y < 0) throw "Point out of bounds";
    if ((width == 0) && (height == 0)) throw "Point out of bounds";

    // Draws pixel
    image[y][x][RED] = pen_red;
    image[y][x][GREEN] = pen_green;
    image[y][x][BLUE] = pen_blue;
}

void ImageMaker::DrawRectangle(int x1, int y1, int x2, int y2) {
    // Error Checking
    if (x1 > width || y1 > height) throw "Point out of bounds";
    if (x1 < 0 || y1 < 0) throw "Point out of bounds";
    if (x2 < 0 || y2 < 0) throw "Point out of bounds";
    if(x1 == x2 && y1 == y2){
        DrawPixel(x1,y1);
    }
    // Calculates rectangle draw
    DrawLine(x1,y1,x1,y2);
    DrawLine(x2,y1,x2,y2);
    DrawLine(x1,y2,x2,y2);
    DrawLine(x1,y1,x2,y1);
}

void ImageMaker::DrawLine(int x1, int y1, int x2, int y2) {

    // Error Checking
    if (x1 > width || y1 > height) throw "Point out of bounds";
    if (x1 < 0 || y1 < 0) throw "Point out of bounds";
    if (x2 < 0 || y2 < 0) throw "Point out of bounds";
    if(x1 == x2 && y1 == y2){
        DrawPixel(x1,y1);
    }

    int dx = x2 - x1;
    int dy = y2 - y1;

    float Steps;

    if (abs(dx) > abs(dy)) {
        Steps = abs(dx);
    }
    else {
        Steps = abs(dy);
    }

    float Xincrease;
    float Yincrease;


    if(Steps!=0) {
        Xincrease = dx / (float) Steps;
        Yincrease = dy / (float) Steps;
    }else{
        Xincrease = 0;
        Yincrease = 0;
    }

    // Put pixel for each step
    float X = x1;
    float Y = y1;
    for (int i = 0; i <= Steps; i++)
    {
        // Draw Pixel at x, y
        DrawPixel(round(X),round(Y));
        X += Xincrease;
        Y += Yincrease;
    }
}

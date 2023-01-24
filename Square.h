#ifndef SQUARE_H
#define SQUARE_H

#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
#include "ShapeTwoD.h"
#include <array>

class Square: public ShapeTwoD
{
    double area;
    int smallestX; 
    int smallestY; //taking the first element as smallest as the base
    int biggestX;
    int biggestY;

public:

    //initialize the super class
   Square(string name, bool containsWrapSpace);

    //take input for the Square
    void input();

    // area of the circle
    void computeArea();
 
    //toString()
    string toString();

    void displayVertices();

    void displayVerticesInShape();

    void displayVerticesOnShape();

    bool isPointInShape(int, int);

    bool isPointOnShape(int, int);

};

#endif // SQUARE_H
#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
#include "ShapeTwoD.h"
#include <array>

class Circle: public ShapeTwoD
{
    float radius;

public:

    //initialize the super class
   Circle(string name, bool containsWrapSpace);

    //take input for the Square
    void input();

    void setRadius(int);

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

#endif // CIRCLE_H
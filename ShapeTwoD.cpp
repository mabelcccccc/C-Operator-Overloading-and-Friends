

/**
Method definations for ShapeTwoD.h
**/


#include "ShapeTwoD.h"

//initialize the two members with member initializer list
ShapeTwoD::ShapeTwoD(string name, bool containsWarpSpace):
    name(name), containsWarpSpace(containsWarpSpace) {
        area = 0.0;
    }

string ShapeTwoD::toString()
{
    string s= "Name : " + name + "\n" + "Special Type : " + (containsWarpSpace ? "WS\n" : "NS\n");
    return s;
}

void ShapeTwoD::computeArea(){
}


//getters and setters methods for the two member variables
string ShapeTwoD::getName()
{
    return this->name;
}

//
double ShapeTwoD::getArea()
{
    return round(this->area);
}

void ShapeTwoD::setArea(int area)
{
    this->area=area;
}

void ShapeTwoD::setName(string name){
	this->name = name;
}

void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace){
	this->containsWarpSpace = containsWarpSpace;
}


void ShapeTwoD::displayVerticesInShape(){
}

bool ShapeTwoD::getContainsWarpSpace(){
	return containsWarpSpace;
}






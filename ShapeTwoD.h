#ifndef SHAPE_TWO_D_H
#define SHAPE_TWO_D_H

#include <string>
#include <vector>
#include <cmath>
#include <array>
#include <algorithm>
#include <iostream>
using namespace std;

/**
Super class for all 2D shapes.
contains the building blocks for other Shapes.
**/
class ShapeTwoD{

protected:
	string name;
	bool containsWarpSpace;
   
public:

   double area;
   /*
   bool operator< (ShapeTwoD* &other) const {
         cout << "<area: " << area << " other->area" << other->getArea() << endl;
        return area < other->getArea();
   }*/
   vector<array<int, 2> > PointsInShape;
   vector<array<int, 2> > PointsOnShape;
   vector<array<int, 2> > crossPoints;

   //initialize the two members with member initializer list
   ShapeTwoD(string name,bool containsWarpSpace);

   //takes input for the corresponding shapes
   virtual void input()=0;
   virtual string toString();
   virtual void computeArea()=0;
   virtual string getName();
   virtual double getArea();
   virtual bool getContainsWarpSpace();
   virtual void setArea(int);
   virtual void setName(string);
   virtual void setContainsWarpSpace(bool);
   virtual void displayVertices()=0;
   virtual bool isPointInShape(int, int)=0;
   virtual bool isPointOnShape(int, int)=0;
   virtual void displayVerticesInShape()=0;
   virtual void displayVerticesOnShape()=0;
   
};


#endif
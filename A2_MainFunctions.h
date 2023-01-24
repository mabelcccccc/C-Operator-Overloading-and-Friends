#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include "Cross.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"

using namespace std;
void displayMenuOptions ();
void displaySortOptions ();
void InputSensorData();
void displayAllShapesInVector();
void computeAllArea();
void deletionOfPointers();
void sortAreaAsc();
void sortAreaDesc();
void sortWarpSpace();
bool aComp(ShapeTwoD*,ShapeTwoD*);
bool dComp(ShapeTwoD*,ShapeTwoD*);
bool wsComp(ShapeTwoD*,ShapeTwoD*);


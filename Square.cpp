#include "Square.h"

//initialize the super class
Square::Square(string name, bool containsWrapSpace)
    : ShapeTwoD(name, containsWrapSpace) {
    } 


void Square::input()
{
    int x;
    int y;
    for (int i=0;i<4;i++){
		cout << "Please enter x-ordinate of pt." << (i+1) << ":" <<endl;
        
        // check if x input is an integer
		while (true)
 		{
    		cin >> x;
    		if (!cin){
      			cout << "Please enter a valid integer " << endl;
      			cin.clear();
      			cin.ignore(numeric_limits<streamsize>::max(), '\n');
      			continue;
    		}
    		else break;
  		}
		cout << "Please enter y-ordinate of pt." << (i+1) << ":" <<endl;

        // check if y input is an integer
		while (true)
 		{
    		cin >> y;
    		if (!cin){
      			cout << "Please enter a valid integer " << endl;
      			cin.clear();
      			cin.ignore(numeric_limits<streamsize>::max(), '\n');
      			continue;
    		}
    		else break;
  		}
        crossPoints.push_back({ x, y });
    }
    sort(crossPoints.begin(), crossPoints.end());
    smallestX = crossPoints.at(0).at(0); 
    smallestY =  crossPoints.at(0).at(1); //taking the first element as smallest as the base
    biggestX = crossPoints.at(3).at(0);
    biggestY = crossPoints.at(3).at(1);
}

void Square::computeArea(){
    int length = biggestX - smallestX ;
    int height = biggestY - smallestY;
    int calArea = length* height;

    //cout << "--------------------------"<< endl;
    //cout << "smallestX: " << smallestX << endl;
    //cout << "smallestY: "<< smallestY << endl;
    //cout << "biggestX: " << biggestX << endl;
    //cout << "biggestY: "<< biggestY << endl;
    //cout << "length: "<< length << endl;
    //cout << "height: "<< height << endl;
    //cout << "Calculate Square area"<< endl;
    this->setArea(calArea);
    //cout << "Total Area: "<< to_string(this->getArea()) << endl;

}

string Square::toString()
{
    int stringArea = round(this->getArea());
    string s= "Square toString(), Name : " + name + "\n" + "Special Type : " + (this->getContainsWarpSpace() ? "WS\n" : "NS\n") + "Area : " + to_string(stringArea) + " units square";
    return s;
}

void Square::displayVertices(){
    int VertCounter=0;
    vector<int> coordinateVector;
    for (array<int, 2> i : crossPoints) {
        for (auto x : i){
            coordinateVector.push_back(x);
        }
        cout << "Point [" << to_string(VertCounter) << "]: (" << coordinateVector.at(0) << ","<< coordinateVector.at(1) << ")" << endl; 
        coordinateVector.clear();
        VertCounter ++;
    }
    coordinateVector.clear();
}

bool Square::isPointInShape(int x, int y){ //exclude the ones that are already Point and add those points in the PointsInShape vector
    //check if already included in the vertices of points
    bool check = true;
    vector<int> pairCoordinate;
    for (array<int, 2> i : crossPoints) { // iterate through the coordinateVector
        for (auto x : i){
            pairCoordinate.push_back(x); //get the x and y cordinates of that point
        }
        
        if( (pairCoordinate.at(0)==x) && (pairCoordinate.at(1)==y)){  //check if that point matches, set to false
            check = false;
        }
        pairCoordinate.clear();
    }
    return check;

}


void Square::displayVerticesInShape(){ //determine the points that are in shape, and display those points
    int xP;
    int yP;
    bool check;
    //length is from point 7 which is .at(6) to point 3 which is .at(2)of x coordinate 
    //height is from point 8 which is .at(7)to point 7 which is .at(6)of y coordinate
    xP = biggestX - smallestX;
    yP = biggestY - smallestY;

    if((xP > 1)|| (yP >1)){ ///not a 1 unit square area 
    //cout << "xP: " << xP << endl;
    //cout << "yP: " << yP << endl;
    //cout << "crossPoints.at(2).at(0): " << (crossPoints.at(2).at(0)) << endl;
    //cout << "crossPoints.at(0).at(0): " << (crossPoints.at(0).at(0)) << endl;
    //cout << "crossPoints.at(3).at(1): " << (crossPoints.at(3).at(1)) << endl;
        for (int x = (crossPoints.at(0).at(0)+1); x <  (crossPoints.at(2).at(0)); x++){     //iterate within this range for x-coordinates +1 because I want to start from the next +1 x-coordinate because I don't want to include perimeter points
            //cout << "x: " << x;
            for (int y = (crossPoints.at(2).at(1)+1); y <  (crossPoints.at(3).at(1)); y++){     //iterate within this range for x-coordinates // +1 because I want to start from the next +1 ycoordinate above
                //cout << "y: " << y << endl;

                
                check =  isPointInShape(x,y);
                //cout << "check: " << to_string(check) << endl;
                if(check == true){  // if it is not matching to the 
                    //cout << "check: " << to_string(check) <<" push_back: "<< x << "," << y<<endl;
                    PointsInShape.push_back({ x, y });
                }
                
            }
        }   
    }

    //display points in PointsInShape vector
    vector<int> pair;
    cout << "Points within Shape: ";
    for (array<int, 2> i : PointsInShape) {
        for (auto j : i){
            pair.push_back(j);
        }
        cout << "(" << pair.at(0) << ","<< pair.at(1) << ")"; 
        pair.clear();
    }
    cout << endl;
    PointsInShape.clear();

}

bool Square::isPointOnShape(int x, int y){
    bool check = false;

    //horizontal ranges
    //1) in between from point 1 which is .at(0) to point 3 which is .at(2)
    if((y == crossPoints.at(0).at(1)) && (x > crossPoints.at(0).at(0)) && ( x < crossPoints.at(2).at(0))){ 
        //cout <<"case1" << endl;
        check = true;
    }

    //2) in between from point 2 which is .at(1) to point 4 which is .at(3) 
    else if((y == crossPoints.at(1).at(1)) && (x > crossPoints.at(1).at(0)) && ( x < crossPoints.at(3).at(0))){
        //cout <<"case2" << endl;
        check = true;
    }

    //vertical
    //3) in between from point 1 which is .at(0) to point 2 which is .at(1) 
    else if((x == crossPoints.at(0).at(0)) && (y > crossPoints.at(0).at(1)) && ( y < crossPoints.at(1).at(1))){
        //cout <<"case3" << endl;
        check = true;
    }

    //4) in between from point 3 which is .at(2) to point 4 which is .at(3) 
    else if((x == crossPoints.at(2).at(0)) && (y > crossPoints.at(2).at(1)) && ( y < crossPoints.at(3).at(1))){
        //cout <<"case4" << endl;
        check = true;
    }

    return check;
}

void Square::displayVerticesOnShape(){ 
    bool check;
    //cout << "smallestX: " << smallestX << endl;
    //cout << "smallestY: "<< smallestY << endl;
    //cout << "biggestX: " << biggestX << endl;
    //cout << "biggestY: "<< biggestY << endl;

    for (int x = smallestX; x <= biggestX; x++){     //iterate within the range of x-coordinates of the vectors
        //cout << "x: " << x;
            for (int y = smallestY; y <=  biggestY; y++){     //iterate within this range of y-coordinates of the vectors
                //cout << "y: " << y << endl;
                
                check =  isPointOnShape(x,y);
                //cout << "check: " << to_string(check) << endl;
                
                if(check == true){  // if it is not matching to the 
                    //cout << "check: " << to_string(check) <<" push_back: "<< x << "," << y<<endl;
                    PointsOnShape.push_back({ x, y });
                }
            }
    }
    //display points in PointsOnShape vector
    vector<int> pair;
    cout << "Points on Shape: ";
    for (array<int, 2> i : PointsOnShape) {
        for (auto j : i){
            pair.push_back(j);
        }
        cout << "(" << pair.at(0) << ","<< pair.at(1) << ")"; 
        pair.clear();
    }
    cout << endl;   
    PointsOnShape.clear();
}


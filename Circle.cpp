#include "Circle.h"

//initialize the super class
Circle::Circle(string name, bool containsWrapSpace)
    : ShapeTwoD(name, containsWrapSpace) {
    } 


void Circle::input()
{
    int x;
    int y;
    int r;
	cout << "Please enter x-ordinate of center: " <<endl;
        
    // check if x input is an integer
	while (true){
    	cin >> x;
    	if (!cin){
      		cout << "Please enter a valid integer " << endl;
      		cin.clear();
      		cin.ignore(numeric_limits<streamsize>::max(), '\n');
      		continue;
    	}
    		else break;
  	}
	cout << "Please enter y-ordinate of center: " <<endl;
    // check if y input is an integer
	while (true){
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

    cout << "Please enter radius: " <<endl;
    // check if y input is an integer
	while (true){
    	cin >> r;
    	if (!cin){
      		cout << "Please enter a valid integer " << endl;
      		cin.clear();
      		cin.ignore(numeric_limits<streamsize>::max(), '\n');
      		continue;
    	}
    	else break;
  	}
    radius = r;  
}

void Circle::computeArea(){
    int calArea = 3.14159 * radius * radius;
    this->setArea(calArea);
    //cout << "Total Area: "<< to_string(this->getArea()) << endl;
}

string Circle::toString()
{
    int stringArea = round(this->getArea());

    string s= "Name : " + name + "\n" + "Special Type : " + (this->getContainsWarpSpace() ? "WS\n" : "NS\n") + "Area : " + to_string(stringArea) + " units square";
    return s;
}

void Circle::displayVertices(){
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

bool Circle::isPointInShape(int x, int y){ //exclude the ones that are already Point and add those points in the PointsInShape vector
    //check if already included in the vertices of points
    bool check = false;
    if(abs(x-crossPoints.at(0).at(0))==radius && abs(y-crossPoints.at(0).at(1))==radius){
        check = true;
    }
    return check;

}


void Circle::displayVerticesInShape(){ //determine the points that are in shape, and display those points
    bool check;

        for (int x = (crossPoints.at(0).at(0)-radius); x <  (crossPoints.at(0).at(0)+radius); x++){     //iterate within this range for x-coordinates +1 because I want to start from the next +1 x-coordinate because I don't want to include perimeter points
            //cout << "x: " << x;
            for (int y = (crossPoints.at(0).at(1)-radius); y <  (crossPoints.at(0).at(1)+radius); y++){     //iterate within this range for x-coordinates // +1 because I want to start from the next +1 ycoordinate above
                //cout << "y: " << y << endl;
                check =  isPointInShape(x,y);
                //cout << "check: " << to_string(check) << endl;
                if(check == true){  // if it is not matching to the 
                    //cout << "check: " << to_string(check) <<" push_back: "<< x << "," << y<<endl;
                    PointsInShape.push_back({ x, y });
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

bool Circle::isPointOnShape(int x, int y){
    bool check = false;

    //1) north of centre
    if(x==crossPoints.at(0).at(0) && y==(crossPoints.at(0).at(1)+radius)){
        //cout << "case1" << endl;
        check = true;
    }

    //2) south of centre
    else if(x==crossPoints.at(0).at(0) && y==(crossPoints.at(0).at(1)-radius)){
        //cout << "case2" << endl;
        check = true;
    }

    //3) west of centre
    else if(x==(crossPoints.at(0).at(0)-radius) && y==crossPoints.at(0).at(1)){
        //cout << "case3" << endl;
        check = true;
    }

    //4) east of centre
    else if(x==(crossPoints.at(0).at(0)+radius) && y==crossPoints.at(0).at(1)){
        //cout << "case4" << endl;
        check = true;
    }
    return check;
}


void Circle::displayVerticesOnShape(){ 
    bool check;

    for (int x = (crossPoints.at(0).at(0)-radius); x <=  (crossPoints.at(0).at(0)+radius); x++){     //iterate within this range for x-coordinates 
            //cout << "x: " << x;
            for (int y = (crossPoints.at(0).at(1)-radius); y <=  (crossPoints.at(0).at(1)+radius); y++){     //iterate within this range for x-coordinates 
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


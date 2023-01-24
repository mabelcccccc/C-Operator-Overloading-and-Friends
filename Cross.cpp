#include "Cross.h"

//initialize the super class
Cross::Cross(string name, bool containsWrapSpace)
    : ShapeTwoD(name, containsWrapSpace) {
    } 


void Cross::input()
{
    int x;
    int y;
    for (int i=0;i<12;i++){
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
    biggestX = crossPoints.at(11).at(0);
    biggestY =  0;
    
   
   //find smallest and biggest y-coordinate
    for (int i=0;i<12;i++){

        if(smallestY > crossPoints.at(i).at(1)){       //find smallest y-coordinate
            //cout <<"current smallestY: " << smallestY << " ,crossPoints.at("<< i <<").at(1): " <<crossPoints.at(i).at(1)<< endl;
            smallestY = crossPoints.at(i).at(1);
        }

        if(biggestY < crossPoints.at(i).at(1)){       //find biggest y-coordinate
           // cout <<"current biggestY: " << biggestY << " ,crossPoints.at("<< i <<").at(1): " <<crossPoints.at(i).at(1)<< endl;
           biggestY = crossPoints.at(i).at(1);
        }
    } 
    
    /*cout << "Vector of crossPoints arrays" << " after sorting: \n";
    for (array<int, 2> i : crossPoints) {
        for (auto x : i)
            cout << x << " ";
        cout << endl;
    }*/
}

void Cross::computeArea(){

    int length = biggestX - smallestX ;
    int height = biggestY - smallestY;
    int areaBigRectangle = length* height;

    //cout << "--------------------------"<< endl;
    //cout << "Calculate Rectangle 1 bottom left"<< endl;
    //Points 1 which is .at(0), 3 which is .at(2) and 4 which is .at(3) 
    
    //length is from point 4 to 1 of x coordinate
    int rect1Length =  crossPoints.at(3).at(0) - crossPoints.at(0).at(0);
    //cout << "crossPoints.at(3).at(0)"<< crossPoints.at(3).at(0)<< " ,crossPoints.at(0).at(0)"<< crossPoints.at(0).at(0)<< endl;
    //height is from point 4 to 3 of y coordinate
    int rect1Height =  crossPoints.at(3).at(1) - crossPoints.at(2).at(1);
    // cout <<"crossPoints.at(3).at(1)" << crossPoints.at(3).at(1)<< " ,crossPoints.at(2).at(1)"<< crossPoints.at(2).at(1)<< endl;
    int rect1Area = rect1Length * rect1Height;
    //cout << "rect1Area : "<< rect1Area << endl;

    //cout << "--------------------------"<< endl;
    //cout << "Calculate Rectangle 2 bottom right"<< endl;
    //Points 7 which is .at(6), 8 which is .at(7) and 11 which is .at(10)
   
    //length is from point 11 to 8 of x coordinate
    int rect2Length =  crossPoints.at(10).at(0) - crossPoints.at(7).at(0);
    
    //height is from point 8 to 7 of y coordinate
    int rect2Height =  crossPoints.at(7).at(1) - crossPoints.at(6).at(1);

    int rect2Area = rect2Length * rect2Height;
    //cout << "rect2Area : "<< rect2Area << endl;

    //cout << "--------------------------"<< endl;
    //cout << "Calculate Rectangle 3 upper left"<< endl;
    //Points 2 which is .at(1), 5 which is .at(4) and 6 which is .at(7)
   
    //length is from point 5 to 2 of x coordinate
    int rect3Length =  crossPoints.at(4).at(0) - crossPoints.at(1).at(0);
    
    //height is from point 6 to 5 of y coordinate
    int rect3Height =  crossPoints.at(5).at(1) - crossPoints.at(4).at(1);

    int rect3Area = rect3Length * rect3Height;
    //cout << "rect3Area : "<< rect3Area << endl;

    //cout << "--------------------------"<< endl;
    //cout << "Calculate Rectangle 4 upper right"<< endl;
    //Points 9 which is .at(8), 10 which is .at(9) and 12 which is .at(11)
   
    //length is from point 12 to 9 of x coordinate
    int rect4Length =  crossPoints.at(11).at(0) - crossPoints.at(8).at(0);
    
    //height is from point 10 to 9 of y coordinate
    int rect4Height =  crossPoints.at(9).at(1) - crossPoints.at(8).at(1);

    int rect4Area = rect4Length * rect4Height;
    //cout << "rect4Area : "<< rect4Area << endl;

    //cout << "--------------------------"<< endl;
    int calArea = areaBigRectangle - rect1Area - rect2Area  - rect3Area - rect4Area ;
    this->setArea(calArea);
    //cout << "Total Area: "<< to_string(this->getArea()) << endl;

}

string Cross::toString()
{
    int stringArea = round(this->getArea());
    string s= "Cross toString(), Name : " + name + "\n" + "Special Type : " + (this->getContainsWarpSpace() ? "WS\n" : "NS\n") + "Area : " + to_string(stringArea) + " units square";
    return s;
}

void Cross::displayVertices(){
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

bool Cross::isPointInShape(int x, int y){ //exclude the ones that are already Point and add those points in the PointsInShape vector
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


void Cross::displayVerticesInShape(){ //determine the points that are in shape, and display those points
    int xP;
    int yP;
    bool check;
    //In bottom rectangle
    //length is from point 7 which is .at(6) to point 3 which is .at(2)of x coordinate 
    //height is from point 8 which is .at(7)to point 7 which is .at(6)of y coordinate
    xP = crossPoints.at(6).at(0) - crossPoints.at(2).at(0);
    yP = crossPoints.at(7).at(1) - crossPoints.at(6).at(1);

    if((xP > 1)|| (yP >1)){ ///not a 1 unit square area      
        for (int x = (crossPoints.at(2).at(0)+1); x <  (crossPoints.at(6).at(0)); x++){     //iterate within this range for x-coordinates +1 because I want to start from the next +1 x-coordinate because I don't want to include perimeter points
            //cout << "x: " << x;
            for (int y = (crossPoints.at(6).at(1)+1); y <  (crossPoints.at(7).at(1)); y++){     //iterate within this range for x-coordinates // +1 because I want to start from the next +1 ycoordinate above
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

    //In right rectangle
    //length is from point 11 which is .at(10) to point 8 which is .at(7) of x coordinate 
    //height is from point 12 which is .at(11)to point 11 which is .at(10)of y coordinate
    xP = crossPoints.at(10).at(0) - crossPoints.at(7).at(0);
    yP = crossPoints.at(11).at(1) - crossPoints.at(10).at(1);
    if((xP > 1)|| (yP >1)){ ///not a 1 unit square area 
        for (int x = (crossPoints.at(7).at(0)+1); x <  (crossPoints.at(10).at(0)); x++){     //iterate within this range for x-coordinates +1 because I want to start from the next +1 x-coordinate because I don't want to include perimeter points
            //cout << "x: " << x;
            for (int y = (crossPoints.at(10).at(1)+1); y <  (crossPoints.at(11).at(1)); y++){     //iterate within this range for x-coordinates // +1 because I want to start from the next +1 ycoordinate above
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
    
    //In top rectangle
    //length is from point 9 which is .at(8) to point 5 which is .at(4) of x coordinate 
    //height is from point 10 which is .at(9)to point 9 which is .at(8) of y coordinate
    xP = crossPoints.at(8).at(0) - crossPoints.at(4).at(0);
    yP = crossPoints.at(9).at(1) - crossPoints.at(8).at(1);
    if((xP > 1)|| (yP >1)){ ///not a 1 unit square area 
        for (int x = (crossPoints.at(4).at(0)+1); x <  (crossPoints.at(8).at(0)); x++){     //iterate within this range for x-coordinates +1 because I want to start from the next +1 x-coordinate because I don't want to include perimeter points
            //cout << "x: " << x;
            for (int y = (crossPoints.at(8).at(1)+1); y <  (crossPoints.at(9).at(1)); y++){     //iterate within this range for x-coordinates // +1 because I want to start from the next +1 ycoordinate above
                //cout << "y: " << y << endl;

                
                check =  isPointInShape(x,y);
                //cout << "check: " << to_string(check) << endl;
                if(check == true){  // if it is not matching to the 
                    //cout << "check: " << to_string(check) <<" push_back: "<< x << "," << y<< " " <<endl;
                    PointsInShape.push_back({ x, y });
                }
                
            }
        }
    }

    //In centre rectangle
    //length is from point 8 which is .at(7) to point 4 which is .at(3) of x coordinate 
    //height is from point 9 which is .at(8)to point 8 which is .at(7) of y coordinate
    xP = crossPoints.at(7).at(0) - crossPoints.at(3).at(0);
    yP = crossPoints.at(8).at(1) - crossPoints.at(7).at(1);
    if((xP > 1)|| (yP >1)){ ///not a 1 unit square area 
        for (int x = (crossPoints.at(3).at(0)+1); x <  (crossPoints.at(7).at(0)+1); x++){     //iterate within this range for x-coordinates //-1 because I want to end till the perimeter because it is still internal
            //cout << "x: " << x;
            for (int y = (crossPoints.at(7).at(1)); y <  (crossPoints.at(8).at(1)+1); y++){     //iterate within this range for x-coordinates // +2 because I want to till parameter above from the next +1 because it is still internal
                //cout << "y: " << y << endl; 
                check =  isPointInShape(x,y);
                //cout << "check: " << to_string(check) << endl;
                if(check == true){  // if it is not matching to the 
                    //cout << "check: " << to_string(check) <<" push_back: "<< x << "," << y<< " " <<endl;
                    PointsInShape.push_back({ x, y });
                }
                
            }
        }
    }

    //In left rectangle
    //length is from point 4 which is .at(3) to point 1 which is .at(0) of x coordinate 
    //height is from point 5 which is .at(4)to point 4 which is .at(3) of y coordinate
    xP = crossPoints.at(3).at(0) - crossPoints.at(0).at(0);
    yP = crossPoints.at(4).at(1) - crossPoints.at(3).at(1);
    if((xP > 1)|| (yP >1)){ ///not a 1 unit square area 
        for (int x = (crossPoints.at(0).at(0)+1); x <  (crossPoints.at(3).at(0)+1); x++){     //iterate within this range for x-coordinates +1 because I want to start from the next +1 x-coordinate because I don't want to include perimeter points
            //cout << "x: " << x;
            for (int y = (crossPoints.at(3).at(1)+1); y <  (crossPoints.at(4).at(1)+1); y++){     //iterate within this range for x-coordinates 
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

bool Cross::isPointOnShape(int x, int y){
    bool check = false;

    //horizontal ranges
    //1) in between from point 1 which is .at(0) to point 4 which is .at(3)
    if((y == crossPoints.at(0).at(1)) && (x > crossPoints.at(0).at(0)) && ( x < crossPoints.at(3).at(0))){ 
        //cout << "isPointOnShape Case1 x:" << x << " y:" << y << endl;
        check = true;
    }

    //2) in between from point 2 which is .at(1) to point 5 which is .at(4) 
    else if((y == crossPoints.at(1).at(1)) && (x > crossPoints.at(1).at(0)) && ( x < crossPoints.at(4).at(0))){
        //cout << "isPointOnShape Case2 x:" << x << " y:" << y << endl;
        check = true;
    }

    //3) in between from point 3 which is .at(2) to point 7 which is .at(6) 
    else if((y == crossPoints.at(2).at(1)) && (x > crossPoints.at(2).at(0)) && ( x < crossPoints.at(6).at(0))){
        //cout << "isPointOnShape Case3 x:" << x << " y:" << y << endl;
        check = true;
    }

    //4) in between from point 6 which is .at(5) to point 10 which is .at(9) 
    else if((y == crossPoints.at(5).at(1)) && (x > crossPoints.at(5).at(0)) && ( x < crossPoints.at(9).at(0))){
        //cout << "isPointOnShape Case4 x:" << x << " y:" << y << endl;
        check = true;
    }

    //5) in between from point 8 which is .at(7) to point 11 which is .at(10) 
    else if((y == crossPoints.at(7).at(1)) && (x > crossPoints.at(7).at(0)) && ( x < crossPoints.at(10).at(0))){
        //cout << "isPointOnShape Case5 x:" << x << " y:" << y << endl;
        check = true;
    }

    //6) in between from point 9 which is .at(8) to point 12 which is .at(11) 
    else if((y == crossPoints.at(8).at(1)) && (x > crossPoints.at(8).at(0)) && ( x < crossPoints.at(11).at(0))){
        //cout << "isPointOnShape Case6 x:" << x << " y:" << y << endl;
        check = true;
    }

    //vertical ranges
    //7) in between from point 1 which is .at(0) to point 2 which is .at(1) 
    else if((x == crossPoints.at(0).at(0)) && (y > crossPoints.at(0).at(1)) && ( y < crossPoints.at(1).at(1))){
        //cout << "isPointOnShape Case7 x:" << x << " y:" << y << endl;
        check = true;
    }

    //8) in between from point 3 which is .at(2) to point 4 which is .at(3) 
    else if((x == crossPoints.at(2).at(0)) && (y > crossPoints.at(2).at(1)) && ( y < crossPoints.at(3).at(1))){
        //cout << "isPointOnShape Case8 x:" << x << " y:" << y << endl;
        check = true;
    }

    //9) in between from point 5 which is .at(4) to point 6 which is .at(5) 
    else if((x == crossPoints.at(4).at(0)) && (y > crossPoints.at(4).at(1)) && ( y < crossPoints.at(5).at(1))){
        //cout << "isPointOnShape Case9 x:" << x << " y:" << y << endl;
        check = true;
    }

    //10) in between from point 7 which is .at(6) to point 8 which is .at(7) 
    else if((x == crossPoints.at(6).at(0)) && (y > crossPoints.at(6).at(1)) && ( y < crossPoints.at(7).at(1))){
        //cout << "isPointOnShape Case10 x:" << x << " y:" << y << endl;
        check = true;
    }

    //11) in between from point 9 which is .at(8) to point 10 which is .at(9) 
    else if((x == crossPoints.at(8).at(0)) && (y > crossPoints.at(8).at(1)) && ( y < crossPoints.at(9).at(1))){
        //cout << "isPointOnShape Case11 x:" << x << " y:" << y << endl;
        check = true;
    }

    //12) in between from point 11 which is .at(10) to point 12 which is .at(11) 
    else if((x == crossPoints.at(10).at(0)) && (y > crossPoints.at(10).at(1)) && ( y < crossPoints.at(11).at(1))){
        //cout << "isPointOnShape Case12 x:" << x << " y:" << y << endl;
        check = true;
    }

    return check;
}

void Cross::displayVerticesOnShape(){ 
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


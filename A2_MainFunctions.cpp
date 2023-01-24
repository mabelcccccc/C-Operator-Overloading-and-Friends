#include "A2_MainFunctions.h"
vector<ShapeTwoD*> vectorsOfShapeTwoD;

void displayMenuOptions ()
{
	cout << "1)    Input sensor data" << endl;
    cout << "2)    Compute area (for all records)" << endl;
    cout << "3)    Print shapes report" << endl;
    cout << "4)    Sort Shape data" << endl;
	cout << "8)	   Quit" << endl;
    cout << "Please enter your choice : ";
}

void displaySortOptions ()
{
	cout << "\ta)   Sort by area (ascending)"<< endl;
    cout << "\tb)   Sort by area (descending)"<< endl;
    cout << "\tc)   Sort by special type and area"<< endl;
    cout << "\tPlease select a option (\'q\' to go to the main menu ) : ";
}

void InputSensorData(){
	string choiceShape;
	string choiceSpecialType;
	ShapeTwoD *shape;
	cout << "Please enter name of shape : ";
	cin >> choiceShape;
	cout << "Please enter special type : "; 
	cin >> choiceSpecialType;

	bool isWrap = choiceSpecialType == "WS" ? true : false;
	if (choiceShape.compare("Cross") == 0){
		shape = new Cross(choiceShape, isWrap);
		shape->input();
		vectorsOfShapeTwoD.push_back(shape);
		cout << "Record successfully stored. Going back to main menu " << endl; 

	}

	if (choiceShape.compare("Rectangle") == 0){
		shape = new Rectangle(choiceShape, isWrap);
		shape->input();
		vectorsOfShapeTwoD.push_back(shape);
		cout << "Record successfully stored. Going back to main menu " << endl; 

	}

	if (choiceShape.compare("Square") == 0){
		shape = new Square(choiceShape, isWrap);
		shape->input();
		vectorsOfShapeTwoD.push_back(shape);
		cout << "Record successfully stored. Going back to main menu " << endl; 

	}

	if (choiceShape.compare("Circle") == 0){
		shape = new Circle(choiceShape, isWrap);
		shape->input();
		vectorsOfShapeTwoD.push_back(shape);
		cout << "Record successfully stored. Going back to main menu " << endl; 

	}
	
}

void computeAllArea(){
	for(int i = 0; i < vectorsOfShapeTwoD.size(); i++)
    	vectorsOfShapeTwoD[i]->computeArea();
}

void displayAllShapesInVector(){
	for(int i = 0; i < vectorsOfShapeTwoD.size(); i++){
		cout << "---------------------------------" << endl;
		cout << "Shape [" << i << "]" << endl; //display the shape2d Name (so getname) and display i
		cout << vectorsOfShapeTwoD[i]->toString() << endl;
		cout << "Vertices: " << endl;
		vectorsOfShapeTwoD[i]->displayVertices();
		vectorsOfShapeTwoD[i]->displayVerticesInShape();
		vectorsOfShapeTwoD[i]->displayVerticesOnShape();
		cout << endl;
	}
    
} 

bool aComp(ShapeTwoD* a, ShapeTwoD* b)
 { //cout << "a->getArea()" << a->getArea() << " b->getArea()" << b->getArea() << endl;
 	return a->getArea() < b->getArea(); }

void sortAreaAsc(){
	sort(vectorsOfShapeTwoD.begin(),vectorsOfShapeTwoD.end(), aComp);
    cout << "Sort by area (smallest to largest)...\n\n";
    displayAllShapesInVector();
    cout << "----------------------------------------\n\n";	
}

bool dComp(ShapeTwoD* a, ShapeTwoD* b)
 { //cout << "a->getArea()" << a->getArea() << " b->getArea()" << b->getArea() << endl;
 	return a->getArea() > b->getArea(); }

void sortAreaDesc(){
	sort(vectorsOfShapeTwoD.begin(),vectorsOfShapeTwoD.end(), dComp);
    cout << "Sort by area (largest to smallest)...\n\n";
    displayAllShapesInVector();
    cout << "----------------------------------------\n\n";
}

bool wsComp(ShapeTwoD* a, ShapeTwoD* b){ 
	if(a->getContainsWarpSpace() != b->getContainsWarpSpace()){
		return a-> getContainsWarpSpace() == true;
	}
	else
		return a->getArea() < b-> getArea();
}

void sortWarpSpace(){
	sort(vectorsOfShapeTwoD.begin(),vectorsOfShapeTwoD.end(), wsComp);
    cout << "Sort by special type and area ...\n\n";
    displayAllShapesInVector();
    cout << "----------------------------------------\n\n";
}

void deletionOfPointers()
{
	for (ShapeTwoD* p : vectorsOfShapeTwoD){
    	delete p;
   } 
   vectorsOfShapeTwoD.clear();
}

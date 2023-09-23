// C16-GeometricObjects-TEMPLATE-App.cpp 
// Goal
// Demonstrate the use of TEMPLATE CLASSES and FUNCTIONS using 
// a hierarchy of abstract geometric objects that instantiates
// as circles and rectangles.

#include "GeometricObject.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

//Prototypes----------------------------------------------------
void experiment01();
void experiment02();
void experiment03();
void experiment04();
void experiment05();

int main()
{
	//experiment01();			//create a few geometric objects
	//experiment02();			//make a list of 'concrete' static geometric objects
	//experiment03();			//MISC. create a timestamp - may be needed by the GeometricObject class
	//experiment04();		    //create a list of 'dynamic' geometric objects
	experiment05();			//template subclass (Rectangle <- Square)
	cout << "\nAll done!\n";
}

//-----------------------------------------------------------------
void experiment01() {
	//-------------------------------------------------------------
	//CAUTION. If you add 'pure virtual' method(s) to the 
	//GeomtericObject class, this fragment will fail!
	//-------------------------------------------------------------
	//GeometricObject<double> g1;
	//cout << "g1 " << g1.toString() << endl;

	//GeometricObject<double> g2("red", true);
	//cout << "g2 " << g2.toString() << endl;
}
//----------------------------------------------------------------------------


void experiment02()
{
	Circle<double> c1;
	Circle<double> c2("RED", true, 1);
	Rectangle<double> r1("BLUE", true, 10, 20);

	//Make a list of various types of geometric objects
	vector<GeometricObject<double>*> v;
	v.push_back((GeometricObject<double>*) (&c1));
	v.push_back((GeometricObject<double>*) (&c2));
	v.push_back((GeometricObject<double>*) (&r1));

	cout << "Circle<double> list-----------------------------------\n";
	for (GeometricObject<double>* g : v) {

		if (typeid(*g) == typeid(Circle<double>))
			cout << "\n I'm a Circle<double> >>> " << g->toString();

		//can g be cast as a Circle<double>?
		if (dynamic_cast<Circle<double>*>(g) != nullptr) {
			Circle<double>* c = dynamic_cast<Circle<double>*>(g);
			cout << " I'm a Circle<double> >>> " << c->toString() << endl;
		}

		//can g be cast as a Rectangle?
		if (dynamic_cast<Rectangle<double>*>(g) != nullptr) {
			Rectangle<double>* r = dynamic_cast<Rectangle<double>*>(g);
			cout << " I'm a Rectangle >>> " << r->toString() << endl;
		}
	}

	//Nothing to delete. 
	//Objects c1, c2, and r1 are handled by the OS/compiler.
	//Observe that v.push_back() makes a copy of the object
	//and stores the copy in the vector. When the vector is
	//destroyed, the copies are destroyed, but the original
	//objects are retained (vector is NOT the owner).


}//experiment02


void experiment03()
{
	/***************************************************************************************************
	1. Open your project in Visual Studio.
	2. Go to "Project" > "Properties" to open the project properties.
	3. In the properties window, navigate to "Configuration Properties" > "C/C++" > "Preprocessor."
	4. In the "Preprocessor Definitions" field, add _CRT_SECURE_NO_WARNINGS.
	5. Save your project settings.

	************************************************************************************************** */
	time_t currentTime = time(nullptr);
	cout << "(Epoch) Current time: " << currentTime << endl;
	// Convert the time to a string and print it
	cout << "(Local) Current time: " << asctime(localtime(&currentTime));

}


//-----------------------------------------------------------------
void experiment04()
{

	Circle<double>* c1 = new Circle<double>();
	Circle<double>* c2 = new Circle<double>("RED", true, 1);
	Rectangle<double>* r1 = new Rectangle<double>("BLUE", true, 10, 20);

	//Make a list of various types of geometric objects
	vector<GeometricObject<double>*> v;
	v.push_back(c1);
	v.push_back(c2);
	v.push_back(r1);

	cout << "Circle<double> list-----------------------------------\n";
	for (GeometricObject<double>* g : v) {

		if (typeid(*g) == typeid(Circle<double>))
			cout << " I'm a Circle<double> >>> " << g->toString() << endl;
		if (typeid(*g) == typeid(Rectangle<double>))
			cout << " I'm a Rectangle >>> " << g->toString() << endl;

	}

	//Housekeeping
	// Objects pointed by c1, c2, and r1 are in the heap. 
	// The vector v contains pointers to these objects, 
	// but does not own them. We are the 'owners' and 
	// must explicitly delete them. 

	delete c1;
	delete c2;
	delete r1;

}//experiment04

//-----------------------------------------------------------------
void experiment05()
{
	//Testing Square class, a subclass of Rectangle
	Rectangle<double>* r1 = new Rectangle<double>("BLUE", true, 10, 20);
	Square<int>* s1 = new Square<int>("RED", true, 10);

	cout << "Rectangle: " << r1->toString() << endl;
	cout << "Square: " << s1->toString() << endl;
}
#include <iostream>
using namespace std;

class Body {
	string type;
public:
	Body() :type{ "No type" } {}
	Body(string t) :type{ t } {}
	string getType()const {
		return type;
	}
};

class Wheel {
	string type;
	int radius;
public:
	Wheel() :type{ "No type" }, radius{ 0 } {}
	Wheel(string t, int r) :type{ t }, radius{ r } {}
	string getType()const {
		return type;
	}
	int getRadius()const {
		return radius;
	}
};

class Engine {
	string type;
	float power;
public:
	Engine() :type{ "No type" }, power{ 0.0 } {}
	Engine(string t, float p) :type{ t }, power{ p } {}
	string getType() const {
		return type;
	}
	float getPower() const {
		return power;
	}
};

enum Location { FrontL, FrontR, BackL, BackR };
class Door {
private:
	Location loc;
	string type;
public:
	Door() :type{ "No type" }, loc{ FrontL } {}
	Door(string t, Location l) :type{ t }, loc{ l } {}
	string getType()const {
		return type;
	}
	Location getLocation()const {
		return loc;
	}
};

class Headlight {
	string type;
	float range;
public:
	Headlight() :type{ "No type" }, range{ 0.0 } {}
	Headlight(string t, float r) :type{ t }, range{ r } {}
	string getType()const {
		return type;
	}
	float getRange() const {
		return range;
	}
};

class Driver {
	string fullName;
	int age;
	int experience;
public:
	Driver() :fullName{ "No Name" }, age{ 18 }, experience{0} {}
	Driver(string fN,int a,int e):fullName{ fN }, age{ a }, experience{ e } {}
	void Print()const {
		cout << "--- "<<fullName<<" ---" << endl;
		cout << "Age: " << age << endl;
		cout << "Experience: " << experience << endl;
	}
};

class Car {
private:
	string name;
	Headlight* lights;
	Door* doors;
	Engine engine;
	Wheel* wheels;
	Body body;
	Driver* driver;
public:
	Car() :name{ "no name" }, lights{ nullptr }, doors{ nullptr }, wheels{ nullptr }, driver{ nullptr } {}
	Car(string n, Headlight* l, Door* d, Engine en, Wheel* wh, string b) :name{ n }, engine{ en }, body{ b }, driver{ nullptr } {
		lights = new Headlight[2]{ l[0],l[1] };
		doors = new Door[4]{ d[0],d[1],d[2],d[3] };
		wheels = new Wheel[4]{ wh[0],wh[1],wh[2],wh[3] };
	}

	Car(string n, Headlight* l, Door* d, Engine en, Wheel* wh, string b, Driver* dr) :name{ n }, engine{ en }, body{ b }, driver{ dr }
	{
		lights = new Headlight[2]{ l[0],l[1] };
		doors = new Door[4]{ d[0],d[1],d[2],d[3] };
		wheels = new Wheel[4]{ wh[0],wh[1],wh[2],wh[3] };

	}

	void Print()const
	{
		cout << "==== " << name << " ====" << endl;
		cout << "Lights: " << lights[0].getType() << " \tRange: " << lights[0].getRange() << endl;
		cout << "Doors: " << doors[0].getType() << endl;
		cout << "Engine: " << engine.getType() << " \t\tPower: " << engine.getPower() << endl;
		cout << "Wheels: " << wheels[0].getType() << " \tRadius: " << wheels[0].getRadius() << endl;
		cout << "Body: " << body.getType() << endl;
		if (driver == nullptr) {
			cout << "No driver" << endl;
		}
		else {
			cout << endl;
			driver->Print();
		}
	}
	void AddDriver(Driver* dr) {
		driver = dr;
	}
	void RemoveDriver() {
		driver = nullptr;
	}
	~Car()
	{
		if (lights != nullptr) {
			delete[]lights;
		}
		if (doors != nullptr) {
			delete[]doors;
		}
		if (wheels != nullptr) {
			delete[]wheels;
		}
	}
};

int main()
{
	Headlight l1{ "Front light", 20.5 };
	Headlight l2{ "Front light", 20.5 };
	Door d1{ "doorType", FrontL };
	Door d2{ "doorType", FrontR };
	Door d3{ "doorType", BackL };
	Door d4{ "doorType", BackR };
	Wheel wh{ "city wheel",35 };
	Headlight* ls=new Headlight[2]{ l1,l2 };
	Door* ds = new Door[4]{ d1,d2,d3,d4 };
	Engine eng{ "Eng",7.5 };
	Wheel* whs = new Wheel[4]{ wh,wh,wh,wh };
	Car car{ "Mercedes",ls,ds,eng,whs, "bodyType" };
	Driver driver{ "Name Lastname", 31,9};
	car.AddDriver(&driver);
	car.Print();
}

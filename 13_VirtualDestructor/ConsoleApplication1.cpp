#include <iostream>
using namespace std;

class Pizza {
public:
	//virtual void Show()const = 0;
	virtual void Cook()const = 0;
};

class MilanPizza :public Pizza {
//private:
	//string name;
public:
	//void Show() const override {}
	void Cook()const override {
		cout << "Milan pizza is cooking" << endl;
	}
};

class GreekPizza :public Pizza {

public:
	void Cook()const override {
		cout << "Greek pizza is cooking" << endl;
	}
};

class Souce {
public:
	virtual void Cook()const = 0;
};

class MilanSouce :public Souce {
public:
	void Cook()const override {
		cout << "Milan souce is cooking" << endl;
	}
};

class GreekSouce :public Souce {
public:
	void Cook()const override {
		cout << "Greek souce is cooking" << endl;
	}
};

class Fabric {
public:
	virtual Pizza* CookPizza()const = 0;
	virtual Souce* CookSouce()const = 0;
};

class MilanFabric :public Fabric {
public:
	Pizza* CookPizza() const override {
		return new MilanPizza();
	}
	Souce* CookSouce() const override {
		return new MilanSouce();
	}
};

class GreekFabric :public Fabric {
public:
	Pizza* CookPizza() const override {
		return new GreekPizza();
	}
	Souce* CookSouce() const override {
		return new GreekSouce();
	}
};

int main()
{
	MilanFabric mf;
	GreekFabric gf;
	cout << "To order Milan pizza enter [1]" << endl;
	cout << "To order Greek pizza enter [2]" << endl;
	cout << "Enter your choise: ";
	int choise;
	cin >> choise;
	Pizza* pizza = nullptr;
	switch (choise) {
	case 1:
		pizza = mf.CookPizza();
		break;
	case 2:
		pizza = gf.CookPizza();
		break;
	}

	cout << "To order pizza with Milan souce enter [1]" << endl;
	cout << "To order pizza with Greek souce enter [2]" << endl;
	cout << "Enter your choise: ";
	cin >> choise;
	Souce* souce = nullptr;
	switch (choise) {
	case 1:
		souce = mf.CookSouce();
		break;
	case 2:
		souce = gf.CookSouce();
		break;
	}
	pizza->Cook();
	souce->Cook();
	delete pizza;
	delete souce;
}
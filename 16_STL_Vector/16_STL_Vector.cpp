#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Time {
	int h;
	int m;
	int s;
	Time() : h(0), m(0), s(0) {}
	Time(int h, int m, int s) : h(h), m(m), s(s) {}
	void Print()const {
		cout << h << ":" << m << ":0" << s << endl;
	}
	friend ostream& operator<<(ostream& os, const Time& time) {
		os << time.h << " " << time.m << " " << time.s;
		return os;
	}
	friend istream& operator>>(istream& is, Time& time) {
		is >> time.h >> time.m >> time.s;
		return is;
	}
};

class Train {
private:
	string number;
	Time DepTime;
	string station;
public:
	Train() :number{ "no number" }, station{ "no station" } {}
	Train(string num, Time time, string st) : number(num), DepTime(time), station(st) {}
	void Print()const {
		cout << "Train number: " << number << endl;
		cout << "Departure time: ";
		DepTime.Print();
		cout << "Destination station: " << station << endl;
	}
	string getNumber() const {
		return number;
	}

	Time getTime()const {
		return DepTime;
	}
	void setDepTime(const Time& time) {
		DepTime = time;
	}
	string getStation() const {
		return station;
	}
	friend ostream& operator<<(ostream& os, const Train& train);
	friend istream& operator>>(istream& is, Train& train);
};

ostream& operator<<(ostream& os, const Train& train) {
	os << train.number << " " << train.DepTime << " " << train.station;
	return os;
}
istream& operator>>(istream& is, Train& train) {
	is >> train.number >> train.DepTime >> train.station;
	return is;
}

class Railway {
private:
	vector<Train> trains;
public:
	Railway() { }
	Railway(vector<Train> trains) {
		this->trains = trains;
	}
	void PrintAll()const {
		for (int i = 0; i < trains.size(); i++) {
			trains[i].Print();
			cout << endl;
		}
	}
	void Print(string number)const {
		int i = 0;
		while (trains[i].getNumber() != number) {
			i++;
		}
		trains[i].Print();
	}
	void AddTrain(const Train& train) {
		trains.push_back(train);
	}

	void SetTime(Time time, string number) {
		for (Train& train : trains) {
			if (train.getNumber() == number) {
				train.setDepTime(time);
				return;
			}
		}
		cerr << "Error: Train with number '" << number << "' not found." << endl;
	}
	void PrintByStation(string st)const {
		for (int i = 0; i < trains.size(); i++) {
			if (trains[i].getStation() == st) {
				trains[i].Print();
			}
		}
	}
	friend ostream& operator<<(ostream& os, const Railway& railway);
	friend istream& operator>>(istream& is, Railway& railway);
};

ostream& operator<<(ostream& os, const Railway& railway) {
	for (const auto& train : railway.trains) {
		os << train << endl;
	}
	return os;
}

istream& operator>>(istream& is, Railway& railway) {
	Train train;
	while (is >> train) {
		railway.trains.push_back(train);
	}
	return is;
}



int main()
{
	Railway rw;
	Time time1 = { 10, 30, 0 };
	Train train1("Express001", time1, "StationA");
	rw.AddTrain(train1);

	Time time2 = { 12, 45, 0 };
	Train train2("Local002", time2, "StationB");
	rw.AddTrain(train2);;
	rw.PrintAll();
	rw.Print("Local002");
	cout << endl;
	rw.PrintByStation("StationA");
	cout << endl;
	Time newTime = { 11, 30, 0 };
	rw.SetTime(newTime, "Express001");
	rw.PrintAll();
	cout << endl;
	ofstream outFile("railway_data.txt");
	if (outFile.is_open()) {
		outFile << rw;
		outFile.close();
		cout << "Railway data has been saved to file: railway_data.txt\n" << endl;
	}
	else {
		cerr << "Error: Unable to open file for writing." << endl;
	}
	rw = Railway();
	ifstream inFile("railway_data.txt");
	if (inFile.is_open()) {
		inFile >> rw;
		inFile.close();
		cout << "Railway data has been loaded from file: railway_data.txt\n" << endl;
	}
	else {
		cerr << "Error: Unable to open file for reading." << endl;
	}

	rw.PrintAll();
}

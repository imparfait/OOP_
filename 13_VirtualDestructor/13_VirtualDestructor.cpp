#include <iostream>
#include <windows.h>   
using namespace std;
 
void gotoxy(int x, int y)
{
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

class Shape {
public:
	virtual void Print()const = 0;
};

struct Point {
	int x;
	int y;
	Point() :x{ 0 }, y{ 0 } {};
	Point(int x, int y) :x{ x }, y{ y } {};
};

class Line:public Shape {
private:
	Point p1;
	Point p2;
public:
	Line(int x1, int y1, int x2, int y2) :p1{ x1,y1 }, p2{ x2,y2 } {};
	void Print()const override {
		gotoxy(p1.x,p1.y);
		cout << "O" <<endl;
		gotoxy(p2.x, p2.y);
		cout << "O" << endl;
	}
};

class Rectangl :public Shape {
private:
	Point p;
	int width;
	int length;
public:
	Rectangl() : width{ 0 }, length{ 0 } {};
	Rectangl(int x, int y, int w, int l) : p{ x,y }, width{ w }, length{ l } {};
	void Print()const override {
		gotoxy(p.x,p.y);
		for(int i=0;i<width;i++){
			gotoxy(p.x, p.y + i);
			for (int j = 0; j < length; j++) {
				cout << "-";
			}
		}
	}
};

class PolyLine :public Shape {
private:
	Point* ps;
	int count;
public:
	PolyLine() :ps{ nullptr }, count{0} {};
	PolyLine(Point* p, int c) : count{ c } {
		ps = new Point[count];
		for (int i = 0; i < count; i++) {
			ps[i] = p[i];
		}
	}
	void Print()const override {
		for (int i = 0; i < count; i++) {
			gotoxy(ps[i].x, ps[i].y);
			cout << "O" << endl;
		}
	}
	~PolyLine()
	{
		delete[] ps;
	}
};

int main()
{
	Line l(1, 2, 4, 4);
	l.Print();
	Rectangl rect(16, 2, 5, 10);
	rect.Print();

	Point p1{ 3, 10 };
	Point p2{ 21, 12 };
	Point p3{ 16, 15 };
	Point* p = new Point[3]{ p1, p2, p3 };
	PolyLine pl{ p,3 };
	pl.Print();
}
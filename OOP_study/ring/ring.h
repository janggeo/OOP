#include<iostream>
using namespace std;

class Point
{
	private:
		int xpos, ypos;
	public:
		Point(const int x,const int y);	
		void ShowPointInfo() const;
};

class Circle
{
	private:
		Point pos;
		int Rad;
	public:
		Circle(const int x,const int y,const int r);
		void ShowInfo() const;
};

class Ring
{
	private:
		Circle InC;
		Circle OuC;
	public:
		Ring(const int x1,const int y1,const int r1,const int x2,const int y2,const int r2);
		void ShowRingInfo() const;
};
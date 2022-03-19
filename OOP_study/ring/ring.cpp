#include "ring.h"
#include <iostream>

using namespace std;

Point::Point(const int x,const int y)
	:xpos(x),ypos(y){};
void Point::ShowPointInfo() const
{
	cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
}

Circle::Circle(const int x,const int y,const int r)
	:pos(x,y),Rad(r){};

void Circle::ShowInfo() const
{
	cout<<"radius: "<<Rad<<endl;
	pos.ShowPointInfo();
}

Ring::Ring(const int x1,const int y1,const int r1,const int x2,const int y2,const int r2)
	:InC(x1,y1,r1),OuC(x2,y2,r2) {};

void Ring::ShowRingInfo() const
{
	cout<<"Inner Circle Info..."<<endl;
	InC.ShowInfo();
	cout<<"Outter Circle Info..."<<endl;
	OuC.ShowInfo();
}
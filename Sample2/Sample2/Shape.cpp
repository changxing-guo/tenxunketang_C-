#include "Shape.h"
#include <iostream>

using namespace std;

void Shape::setWidth(int w)
{
	this->width_ = w;
}

void Shape::setHeight(int h)
{
	this->height_ = h;
}

//派生类内部调用基类成员受基类的限制
int Rectangle::getArea()
{
	return width_ * height_;
}

Date::Date(int y, int m, int d) :
	year_(y), mouth_(m), day_(d)
{
}

Date::~Date()
{
}

void Date::printDate()
{
	printf("%d-%d-%d\n", year_, mouth_, day_);
}

Date_Europe::Date_Europe(int y, int m, int d)
	:Date(y, m, d)
{
}
void Date_Europe::printDate()
{
	printf("%d-%d-%d\n", day_, mouth_, year_);
}

void Date_Europe::print(bool isEurope)
{
	if (isEurope)
	{
		printDate();
	}
	else
	{
		//通过类名限定符在派生类中使用基类的同名成员
		Date::printDate();
	}
}

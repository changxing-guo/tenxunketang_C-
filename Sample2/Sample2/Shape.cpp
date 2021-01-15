#include "Shape.h"


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
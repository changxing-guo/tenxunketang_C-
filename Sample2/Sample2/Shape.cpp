#include "Shape.h"


void Shape::setWidth(int w)
{
	this->width_ = w;
}

void Shape::setHeight(int h)
{
	this->height_ = h;
}

//�������ڲ����û����Ա�ܻ��������
int Rectangle::getArea()
{
	return width_ * height_;
}
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

//�������ڲ����û����Ա�ܻ��������
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
		//ͨ�������޶�������������ʹ�û����ͬ����Ա
		Date::printDate();
	}
}

int BaseTest::getI()
{
	return i_;
}

void Y1::test()
{
	int temp;
	temp = getI();
	temp = i_;
	//temp = x_;//���ɷ���
}

void Y2::test()
{
	int temp;
	temp = getI();
	temp = i_;
	//temp = x_;//���ɷ���
}

void Y3::test()
{
	int temp;
	temp = getI();
	temp = i_;
	//temp = x_;//���ɷ���
}

void Y4::test()
{
	//��ΪY3��˽�м̳У�����getI��i_����Y3��˵��private
	int temp;
	//temp = getI();	//���ɷ���
	//temp = i_;		//���ɷ���
	//temp = x_;		//���ɷ���
}

void Y5::test()
{
	int temp;
	temp = getI();
	temp = i_;
	//temp = x_;//���ɷ���
}

void Y6::test()
{
	int temp;
	temp = getI();
	temp = i_;
	//temp = x_;//���ɷ���
}

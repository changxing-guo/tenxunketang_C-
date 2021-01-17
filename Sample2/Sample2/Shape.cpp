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

C::C()
{
	cout << "����C����" << endl;
}

C::~C()
{
	cout << "����C����" << endl;
}

BaseT2::BaseT2()
{
	cout << "����BaseT2����" << endl;
}

BaseT2::~BaseT2()
{
	cout << "����BaseT2����" << endl;
}

D::D()
{
	cout << "����D����" << endl;
}

D::~D()
{
	cout << "����D����" << endl;
}

Base2::Base2(int a, int b)
{
	cout << "Base2::Base2(int a, int b)" << endl;
}

Base2::Base2(int a)
{
	cout << "Base2::Base2(int a)" << endl;
}

Base2_1::Base2_1(int a, int b, int c, int d, int e)
	: Base2(a, b), d_(c)
{
	cout << "Base2_1(int a, int b, int c, int d, int e)" << endl;
}

int Base3::getI()
{
	return i_;
}

void Base3::setI(int i)
{
	i_ = i;
}

void Base3::print()
{
	cout << "Base3 print" << endl;
}

void Base3_1::setJ(int j)
{
	j_ = j;
}

int Base3_1::getIJ()
{
	return i_ + j_;
}

void Base3_1::print()
{
	Base3::print();
	//cout << "Base3_1 print" << endl;
}

void Base4::showI()
{
	cout << "i = " << i_ << endl;
}

void Base4::showA()
{
	cout << "a = " << a_ << endl;
}

void Base5::showJ()
{
	cout << "j = " << j_ << endl;
}

void Base5::showA()
{
	cout << "a = " << a_ << endl;
}

void Base6::set(int x, int y)
{
	i_ = x;
	j_ = y;
}

void Base6::setA(int a1, int a2)
{
	Base4::a_ = a1;
	Base5::a_ = a2;
}

void Base6::show()
{
	showI();
	showJ();
}

void Base6::show_A()
{
	Base4::showA();
	Base5::showA();
}

void Base7_1::show1()
{
	cout << "base7_1 i address " << &i << endl;
}

void Base7_2::show2()
{
	cout << "base7_2 i address " << &i << endl;
}

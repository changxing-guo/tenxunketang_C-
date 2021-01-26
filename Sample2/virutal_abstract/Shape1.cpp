#include "Shape1.h"
#include <iostream>

using namespace std;

Shape1::Shape1()
{
	cout << "构造Shape1" << endl;
}


Shape1::~Shape1()
{
	cout << "析构Shape1" << endl;
}

test1::test1()
{
	cout << "构造test1" << endl;
}

double test1::getArea()
{
	cout << "test1::getArea" << endl;
	return 0.0;
}

test1::~test1()
{
	cout << "析构test1" << endl;
}

test2::test2()
{
	cout << "析构test2" << endl;
}

double test2::getArea()
{
	cout << "test2::getArea" << endl;
	return 0.0;
}

void test2::testVirtual()
{
}

test2::~test2()
{
	cout << "析构test2" << endl;
}

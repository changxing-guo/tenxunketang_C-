#include "Demo.h"
#include <iostream>

using namespace std;

Demo::Demo()
{
	cout << "Demo()" << endl;
}
Demo::Demo(int a)
{
	cout << "Demo(int a)" << endl;
	m_a = a;
}

Demo::Demo(int a, int b)
{
	cout << "Demo(int a, int b)" << endl;
	m_a = a;
	m_b = b;
}


Demo::Demo(const Demo & obj)
{
	cout << "Demo(const Demo & obj)" << endl;
	//m_a = obj.m_a;
	//m_b = obj.m_b;
}

void Demo::print(void)
{
	cout << "m_a = " << m_a << ", m_b = " << m_b << endl;
}

void Demo::setA(int a)
{
	m_a = a;
}

int Demo::getA()
{
	return m_a;
}

Demo::~Demo()
{
	cout << "~Demo()" << endl;
	//print();
}

#include "Demo2.h"
#include <iostream>


// 类的成员中又有类的对象的时候的初始化
// 初始化是是否可以使用变量？可以
Demo2::Demo2(): m_a(10), m_b(20), m_c(10)
{
	printf("Demo2 \n");
}


Demo2::~Demo2()
{
	printf("~Demo2 \n");
}

Demo2_A::Demo2_A(int v): m_c(1)
{
	m_val = v;
	printf("Demo2_A m_val = %d\n", m_val);
}

int Demo2_A::getValue()
{
	return m_val;
}

Demo2_A::~Demo2_A()
{
	printf("~Demo2_A m_val = %d\n", m_val);
}

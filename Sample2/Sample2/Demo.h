#pragma once
class Demo
{
	int m_a;
	int m_b;
public:
	Demo();
	Demo(int a);
	Demo(int a, int b);
	//赋值构造函数
	Demo(const Demo &obj);
	//~Demo();
};


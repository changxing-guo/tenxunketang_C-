#pragma once
class Demo
{
	int m_a;
	int m_b;
public:
	Demo();
	Demo(int a);
	Demo(int a, int b);
	//��ֵ���캯��
	Demo(const Demo &obj);
	//~Demo();
};


#pragma once

class Demo2_A {
	int m_val = 10;
	const int m_c;
public :
	Demo2_A(int v);
	int getValue();
	~Demo2_A();
};

class Demo2
{
public :
	Demo2_A m_a;
	Demo2_A m_b;
	const int m_c;

public:
	Demo2();
	~Demo2();
};


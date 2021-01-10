#pragma once

class Demo2_A {
	int m_val = 10;
	const int m_c;
public :
	Demo2_A(int v);
	int getValue();
	~Demo2_A();
};

class Demo2_B {
	int m_a;
	int m_b;
	int m_c;

public :
	Demo2_B(int _a, int _b);
	Demo2_B(int _a, int _b, int _c);
	void demoPrint();
	~Demo2_B();
};

class Demo2_C {
	int m_a = 1;
public :
	//Demo2_C();
	~Demo2_C();
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


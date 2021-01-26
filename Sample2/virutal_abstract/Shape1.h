#pragma once
class Shape1
{
public:
	Shape1();
	virtual double getArea() = 0;
	virtual ~Shape1();

};

class test1 : public Shape1
{
public:
	test1();
	double getArea();
	virtual void testVirtual() = 0;
	~test1();

protected:
	int x_;
	int y_;
};

class test2 :public test1
{
public:
	test2();
	double getArea();
	void testVirtual();
	~test2();
protected:
	int x_;
	int y_;
};


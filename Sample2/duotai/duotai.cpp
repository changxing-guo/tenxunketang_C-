#include <iostream>

using namespace std;

/*
静态联编：
	通过派生类对象调用同名成员函数
	通过指针基类调用同名成员函数

	1、通过派生类对象调用同名成员函数
		在派生类中可以定义和基类的成员函数同名的成员函数，这是对基类进行改造。
	是派生类增加新的行为的一种常用的方法
		在程序编译的时候，就可以确定派生类对象具体调用哪个同名的成员函数。这是
	通过静态联编实现的多态

	结论：
		派生类对象可以直接调用本类中与基类成员函数同名的函数，不存在二义性。
		在编译时就能确定通过对象调用哪个函数，属于静态联编
		

	2、通过指针基类调用同名成员函数
		从继承的角度看，派生类对象是基类对象的一个具体的特例，或者说，派生类对象
	是某一种特定类型的基类对象

		
*/

class Shape
{
public:
	double getArea()
	{
		cout << "基类的getArea函数" << endl;
		return 0.0;
	};
	void print()
	{
		cout << "基类的print函数" << endl;
	};

};

class Circle :public Shape
{
public:
	Circle(int x, int y, double r)
		:x_(x), y_(y), r_(r)
	{
	}

	double getArea()
	{
		return 3.14 * r_ * r_;
	}

	void print()
	{
		cout << "圆心是："
			<< " x_  = " << x_
			<< ", y_ = " << y_
			<< ". radius = " << r_ << endl;
	}
protected:
	int x_;		//圆心的坐标
	int y_;
	double r_;	//圆的半径
};

class Rectangle :public Shape
{
protected:
	int width_;
	int height_;

public:
	Rectangle(int width, int height)
		:width_(width), height_(height)
	{
	}
	double getArea()
	{
		return width_ * height_;
	}

	void print()
	{
		cout << "width_ = " << width_
			<< ", height_ = " << height_ << endl;
	}
};

int main(void)
{
	// 1、通过派生类对象调用同名成员函数
	Circle c(1, 2, 3);
	cout << "c area = " << c.getArea() << endl;	//静态联编
	c.print();
	printf("\n");

	Rectangle r(22, 33);
	cout << "r area = " << r.getArea() << endl;	//静态联编
	r.print();
	printf("\n");

	//2、通过指针基类调用同名成员函数
	Shape sh;
	sh = c;
	cout << "sh area = " << sh.getArea() << endl;	//静态联编
	sh.print();
	printf("\n");

	Shape *sh2;
	sh2 = &c;
	cout << "sh2 area = " << sh2->getArea() << endl;	//静态联编
	sh2->print();

	system("pause");
	return 0;
}
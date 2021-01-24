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

/*
虚函数
	在类的定义中声明虚函数，格式如下：
		virtual 返回值类型 函数名（参数表）
		在函数原型中声明函数时虚函数后，具体定义这个函数时就不需要再说明了

	在基类定义中直接定义虚函数的格式是：
		virtual 返回值类型 函数名（参数表）
		{
			函数体
		}

	基类中的同名函数声明或定义为虚函数后，派生类的同名函数无论是不是用virtual
	来说明，都将自动的成为虚函数

	但是从程序可读性考虑，一般都会在这些函数的声明或定义是，用virtual来加以说明

*/

class Shape
{
public:
	virtual double getArea()
	{
		cout << "基类的getArea函数" << endl;
		return 0.0;
	};
	virtual void print()
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

	virtual double getArea()
	{
		return 3.14 * r_ * r_;
	}

	virtual void print()
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
	virtual double getArea()
	{
		return width_ * height_;
	}

	virtual void print()
	{
		cout << "width_ = " << width_
			<< ", height_ = " << height_ << endl;
	}
};

void printGetArea(Shape *sh)
{
	cout << "area = " << sh->getArea() << endl;
}

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
	// 直接赋值的方式，此方式无法实现
	Shape sh;
	sh = c;
	cout << "sh area = " << sh.getArea() << endl;	//静态联编
	sh.print();
	printf("\n");

	//通过指向基类对象的指针访问和基类成员函数同名的派生类成员函数
	Shape *sh2;
	sh2 = &c;
	cout << "sh2 area = " << sh2->getArea() << endl;	//静态联编
	sh2->print();
	printf("\n");

	//用派生类对象初始化的基类对象的引用访问和基类成员函数同名的派生类成员函数
	Shape &sh3 = c;
	//sh2 = &c;
	cout << "sh3 area = " << sh3.getArea() << endl;	//静态联编
	sh3.print();

	/*
	2打印为：
		基类的getArea函数
		sh area = 0
		基类的print函数

		sh2 area = 28.26
		圆心是： x_  = 1, y_ = 2. radius = 3

		sh3 area = 28.26
		圆心是： x_  = 1, y_ = 2. radius = 3
	*/

	/*
	总结：要实现运行时的多态，需要以下条件

	通过指向基类对象的指针访问和基类成员函数同名的派生类成员函数
	或者用派生类对象初始化的基类对象的引用访问和基类成员函数同名的派生类成员函数
	派生类的继承方式必须是公有继承
	基类中的同名成员函数必须定义为虚函数
	*/
	// 动态联编的另一种演示
	printf("\n\n");
	printGetArea(&c);
	printGetArea(&r);

	system("pause");
	return 0;
}
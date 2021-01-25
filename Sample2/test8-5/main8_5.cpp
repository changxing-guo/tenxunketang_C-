#include <iostream>


/*
虚析构函数：
	如果用动态创建的派生类对象的地址初始化基类的指针，创建的过程不会有问题。
仍然是先调用基类构造函数，在执行派生类的构造函数
	但是，在用delete运算符删除这个指针的时候，由于指针是指向基类的，通过
静态联编，只会调用基类的析构函数，释放基类成员所占用的空间，而派生类成员所占用
的空间将不会被释放

使用场景：
	为了解决派生类对象释放不彻底的问题，必须将基类的析构函数定义为虚析构函数。
	此后，无论派生类对象是不是用virtual来说明，也都是虚析构函数。
	在用delete来释放基类指针时，就会通过动态联编调用派生类的析构函数

虚函数和虚析构函数：
	虚函数会调用派生类的多态函数
	虚析构函数基类和派生类的析构函数都会调用


*/
using namespace std;

class Shape
{
public:
	Shape()
	{
		cout << "构造Shape" << endl;
	}

	// 虚析构函数
	virtual ~Shape()
	{
		cout << "析构Shape" << endl;
	}

	virtual void print()
	{
		cout << "shape print" << endl;
	}
};

class Circle : public Shape
{
public:
	Circle(int x, int y, double r)
		:x_(x), y_(y), radius_(r)
	{
		cout << "构造Circle" << endl;
	}

	// 虚析构函数
	virtual ~Circle()
	{
		cout << "析构Circle" << endl;
	}

	virtual void print()
	{
		cout << "Circle print" << endl;
	}

private:
	int x_;
	int y_;
	double radius_;
};

int main(void)
{
	{
		cout << "派生类正常构造和析构" << endl;
		Circle c1(20, 21, 22);
		/*
		构造Shape
		构造Circle
		析构Circle
		析构Shape
		*/
	}

	{
		cout << "通过基类指向的派生类的构造和析构" << endl;
		Shape *shape_ptr;
		shape_ptr = new Circle(1, 2, 3.0);

		delete shape_ptr;
	}
	system("pause");
	return 0;
}

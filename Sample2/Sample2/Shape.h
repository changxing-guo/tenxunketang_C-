﻿#pragma once
class Shape
{
public:
	void setWidth(int width);
	void setHeight(int height);

	//派生类内部调用基类成员受基类的限制。private,protected,public
protected:
	int width_;
	int height_;
};

//派生类
//派生类内部可以访问的是基类中public和protected限制的成员（数据成员和函数）
class Rectangle :public Shape
{
public:
	int getArea();
};

//继承的语法
class Date
{
public:
	Date(int y = 0, int m = 0, int d = 0);
	~Date();
	void printDate();

protected:
	int year_ = 2021;
	int mouth_ = 1;
	int day_ = 1;
};

class Date_Europe :public Date
{
public:
	Date_Europe(int y = 1, int m = 1, int d = 1);
	void printDate();
	void print(bool isEurope);
};

//继承访问控制规则
/*
	继承访问控制	基类成员访问控制	在派生类中的访问控制
	public			public				public
					protected			protected
					private				private

	protected		public				protected
					protected			protected
					private				private

	private			public				private
					protected			private
					private				public

	无论采用什么样的派生方式，派生类中都不能访问基类的私有成员
*/
class BaseTest
{
public:
	int getI();

protected:
	int i_ = 0;
private:
	int x_ = 0;
};

class Y1 :public BaseTest//公有派生，i是受保护，getI是公有
{
	void test();
};

//保护派生，i是受保护，getI变成了受保护成员，其他类不能访问
class Y2 :protected BaseTest
{
	void test();
};

//私有派生，i和getI都变成了私有成员
class Y3 :private BaseTest
{
	void test();
};

//此时Y3所有成员是私有，所以Y4不能访问Y3的所有成员
class Y4 :public Y3
{
	void test();
};

class Y5 :public Y2
{
	void test();
};

class Y6 :public Y1
{
	void test();
};

/*
继承与构造函数，析构函数

	构造函数与析构函数的调用次序

	1、构造函数的调用次序
		在创建一个派生类的对象时
			先调用其基类的构造函数
			在调用本类对象成员的构造函数
			最后再调用本类的构造函数

	2、析构函数的调用次序
		先调用本类的析构函数
		在调用本类对象成员的析构函数
		最后再调用其基类的析构函数
*/

class C
{
public:
	C();
	~C();
};

class BaseT2
{
public:
	BaseT2();
	~BaseT2();
};

class D :public BaseT2
{
public:
	D();
	~D();
private:
	C obj_;
};

//向基类构造函数传递实际参数
/*
	通过向派生类构造函数传递实际参数以及初始化参数列表来间接实现传递的
	带初始化列表的派生类构造函数的一般形式
*/

class Base2
{
private:
	int a_;
	int b_;
public:
	Base2(int a);
	Base2(int a, int b);
};

class Base2_1 :public Base2
{
private:
	int c_;
	Base2 d_;

public:
	Base2_1(int a, int b, int c, int d, int e);
};

//恢复访问控制方式
class Base3
{
public:
	void setI(int i);
	int getI();
	void print();
protected:
	int i_;
};

class Base3_1 : private Base3
{
public:
	Base3::setI;	//访问声明,很少使用，只是说明有这种用法
	void setJ(int j);
	int getIJ();
	void print();
protected:
	int j_;
};

//继承成员的重定义
/*
	派生类中定义了一个函数原型与继承成员函数一样的成员函数，
	但语义上修改了成员函数的实现
*/

//多重继承的应用背景
/*
多重继承的名字的冲突问题
	名字冲突：指两个基类具有相同名字的成员时，在派生类中这个名字会产生
二义性，即编译程序无法确定派生类的对象使用改名字时应调用哪一类中的版本。
	名字冲突的解决办法：
		作用域预算符指明基类
*/
class Base4
{
public:
	void showI();
	void showA();
protected:
	int i_;
	int a_;
};

class Base5
{
public:
	void showJ();
	void showA();
protected:
	int j_;
	int a_;
};

class Base6 :public Base4, public Base5
{
public:
	void set(int x, int y);
	void setA(int a1, int a2);
	void show();
	void show_A();
};

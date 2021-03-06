﻿#pragma once

class Demo2_A {
	int m_val = 10;
	const int m_c;
public:
	Demo2_A(int v);
	int getValue();
	~Demo2_A();
};

class Demo2_B {
	int m_a;
	int m_b;
	int m_c;

public:
	Demo2_B(int _a, int _b);
	Demo2_B(int _a, int _b, int _c);
	void demoPrint();
	~Demo2_B();
};

class Demo2_C {
private:
	int m_a = 1;
	static int m_b;
	static Demo2_C * single; //指向类的静态指针
public:
	static int m_s;
	int m_d;
public:
	//Demo2_C();
	//单件模式
	static Demo2_C * getInstance();
	//静态成员函数
	static void Demo2_C::setB(int _b);
	static int getB();
	~Demo2_C();
};

class Demo2
{
public:
	Demo2_A m_a;
	Demo2_A m_b;
	const int m_c;

public:
	Demo2();
	~Demo2();
};

class Car {
	static int m_test;
public:
	int m_price;
	int m_ctest;

	void setPrice(int price);
	void setPrice_1(int m_price);
	void Hello();

	//const修改成员函数,指针指向的值不能变（即类的变量值）
	void setA(int a) const; // Car_setA(const Car * this, int a);

	//void const setB(int b);

	//友元函数测试
private:
	int cost;	//成交价
	void setCost(int p);

	friend void buyCar(Car *car);
	friend class SaleCar;
};
//c++类本质的实现相当于下面c的实现
//this就是默认的隐藏参数

struct  CCar
{
	int m_price;
};
void setCPrice(struct CCar * cp, int p);

//思考：既然类中的方法会重新定义，假如我们在外部定义相同的方法会报错吗？
void setPrice(int price);

//答案：不会
//G++编译器会默认将类中的setPrice_1改为Car_setPrice_1
//编译后已经没有setPrice_1()方法。所以在类外面可以重新定义相同的

//思考：类中添加静态变量。sizeof（类）会不会变大
//答案，不会，静态成员放在全局变量，不属于类
int testCarSize();

void buyCar(Car *car);

class SaleCar {
public:
	SaleCar();
	void buyCar();
	int getPrice();
	int getCost();
private:
	Car qq;
};

class BuyCar {

};

//运算符重载
class Complex {

public:
	double m_real;
	double m_image;

	Complex();
	Complex(double real, double image);
	Complex add(const Complex &c);

	Complex operator +(const Complex &c);
	Complex operator -(const Complex &c);
	Complex operator *(const Complex &c);
	Complex operator /(const Complex &c);

	Complex operator +(const double real);

	//二元运算符之友元函数
	//作为友元函数重载
	/*
	1、关于友元函数运算符
	-为了实现类对象的各种运算，除了将运算符重载为类的成员函数外，还可以将它重载为类的友元函数
	-在有些情况下，只有将运算符重载为类的友元函数才能解决某些问题
	Complex a, b(2.3:
	a = b + 2;
	a = a + b;

	2、重载二元运算符为类的友元函数时需要两个参数
	friend T1 operate (T2 a, T3 b);
	*/
	friend Complex operator +(Complex &c1, Complex &c2);
	friend Complex operator +(const double real, Complex &c);

	void display();
};

//重载一元运算符之成员函数方式
class Time
{
private:
	int hour_;
	int minute_;
	int second_;

public:
	Time();
	Time(int hour, int minute, int second);

	//秒自增 ++time;
	Time operator ++();
	Time operator ++(int);

	void display();
};

//重载一元运算符之友元函数方式
class Time_F
{
private:
	int hour_;
	int minute_;
	int second_;

public:
	Time_F();
	Time_F(int hour, int minute, int second);

	//秒自增 ++time;
	friend void operator ++(Time_F &t);
	friend void operator --(Time_F &t, int);
	void display();
};

//特殊运算符重载之赋值运算符= 异常原因分析
class String
{
public:
	String(char *s);
	~String();
	void print();
private:
	char *m_ptr;
	int m_len;
};

//特殊运算符重载之赋值运算符=（2）
class String_A
{
public:
	String_A(char *s);
	void print();
	//拷贝构造函数
	String_A(String_A &other);
	//一般只有成员变量指向malloc或者new申请的内存才考虑是否需要重载赋值运算符
	String_A &operator =(const String_A &s);
	~String_A();
private:
	char *m_ptr;
	int m_len;
};

//特殊运算符重载之赋值运算符=（3）,重载的小技巧
/*
	将operator设置为private可以阻止对象赋值；
	在operator-实现中药检查自赋值
		if (this -- &obj)
			return (*this);
	拷贝构造函数与赋值运算符的区别
		拷贝构造函数要创建一个新对象
		赋值预算符则是改变一个已存在的对象的值

	注意：使用了=，未必就会调用赋值运算符重载。（声明）
*/

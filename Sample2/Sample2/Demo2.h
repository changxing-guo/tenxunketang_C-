#pragma once

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
private :
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
public :
	SaleCar();
	void buyCar();
	int getPrice();
	int getCost();
private :
	Car qq;
};

class BuyCar {

};



#pragma once
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


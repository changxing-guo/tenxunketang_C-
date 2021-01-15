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


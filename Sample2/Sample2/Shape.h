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


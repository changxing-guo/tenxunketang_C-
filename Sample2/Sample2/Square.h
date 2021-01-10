#pragma once
#include "point.h"

class Square
{
private:
	int m_x;			//正方形左下方的x坐标
	int m_y;			//正方形左下方的y坐标
	int m_length;		//正方形的边长

public:
	/*
	有关构造函数
	（1）构造函数定义及使用
		1）与类名相同
		2）定义是可以有参数
		3）没有任何返回类型的声明
	（2）构造函数的作用
		1）自动调用
		2）在一些情况下则需要手动调用构造函数

	有关析构函数
	（3）析构函数定义及使用
		1）定义
		2）构造函数没有参数也没有返回类型的声明
		3）析构函数在对象销毁时自动被调用
	（4）析构函数调用机制
		c++编译器自动调用
	*/
	Square();
	Square(int p);
	// 析构函数永远不能带参数
	~Square();

	void setLength(int len);
	int getLength();
	void setPosition(int _x, int _y);
	int getPositionX();
	int getPositionY();

	// 判断点是否在此正方形内部
	bool isContain(point &p);
};


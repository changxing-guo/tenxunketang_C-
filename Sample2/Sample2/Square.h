#pragma once
#include "point.h"

class Square
{
private:
	int m_x;			//正方形左下方的x坐标
	int m_y;			//正方形左下方的y坐标
	int m_length;		//正方形的边长

public:
	void setLength(int len);
	int getLength();
	void setPosition(int _x, int _y);
	int getPositionX();
	int getPositionY();

	// 判断点是否在此正方形内部
	bool isContain(point &p);
};


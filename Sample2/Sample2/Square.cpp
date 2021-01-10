#include "Square.h"
#include <iostream>

Square::Square()
{
	printf("这是Square构造函数\n");
}

Square::Square(int p)
{
	printf("这是Square构造函数 p = %d\n", p);
}

Square::~Square()
{
	printf("这是Square析构函数\n");
}

void Square::setLength(int len)
{
	m_length = len;
}

int Square::getLength()
{
	return m_length;
}

void Square::setPosition(int _x, int _y)
{
	m_x = _x;
	m_y = _y;
}

int Square::getPositionX()
{
	return m_x;
}

int Square::getPositionY()
{
	return m_y;
}

bool Square::isContain(point & p)
{
	int p_x = p.getPositionX();
	int p_y = p.getPositionY();

	int m_x_max = m_x + m_length;
	int m_y_max = m_y + m_length;

	if (p_x >= m_x && p_x << m_x_max
		&& p_y >= m_y && p_y <= m_y_max) {
		return true;
	}
	return false;
}

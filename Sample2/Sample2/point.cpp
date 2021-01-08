#include "point.h"

void point::setPosition(int _x, int _y)
{
	m_x = _x;
	m_y = _y;
}

int point::getPositionX()
{
	return m_x;
}

int point::getPositionY()
{
	return m_y;
}

#pragma once
#include "point.h"

class Square
{
private:
	int m_x;			//���������·���x����
	int m_y;			//���������·���y����
	int m_length;		//�����εı߳�

public:
	void setLength(int len);
	int getLength();
	void setPosition(int _x, int _y);
	int getPositionX();
	int getPositionY();

	// �жϵ��Ƿ��ڴ��������ڲ�
	bool isContain(point &p);
};


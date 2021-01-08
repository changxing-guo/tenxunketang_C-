#pragma once
#include "point.h"

class Square
{
private:
	int m_x;			//���������·���x����
	int m_y;			//���������·���y����
	int m_length;		//�����εı߳�

public:
	/*
	�йع��캯��
	��1�����캯�����弰ʹ��
		1����������ͬ
		2�������ǿ����в���
		3��û���κη������͵�����
	��2�����캯��������
		1���Զ�����
		2����һЩ���������Ҫ�ֶ����ù��캯��

	�й���������
	��3�������������弰ʹ��
		1������
		2�����캯��û�в���Ҳû�з������͵�����
		3�����������ڶ�������ʱ�Զ�������
	��4�������������û���
		c++�������Զ�����
	*/
	Square();
	Square(int p);
	// ����������Զ���ܴ�����
	~Square();

	void setLength(int len);
	int getLength();
	void setPosition(int _x, int _y);
	int getPositionX();
	int getPositionY();

	// �жϵ��Ƿ��ڴ��������ڲ�
	bool isContain(point &p);
};


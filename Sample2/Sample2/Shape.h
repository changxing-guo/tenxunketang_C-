#pragma once
class Shape
{
public:
	void setWidth(int width);
	void setHeight(int height);

	//�������ڲ����û����Ա�ܻ�������ơ�private,protected,public
protected:
	int width_;
	int height_;
};

//������
//�������ڲ����Է��ʵ��ǻ�����public��protected���Ƶĳ�Ա�����ݳ�Ա�ͺ�����
class Rectangle :public Shape
{
public:
	int getArea();
};


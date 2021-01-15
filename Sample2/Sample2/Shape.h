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

//�̳е��﷨
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


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

//�̳з��ʿ��ƹ���
/*
	�̳з��ʿ���	�����Ա���ʿ���	���������еķ��ʿ���
	public			public				public
					protected			protected
					private				private

	protected		public				protected
					protected			protected
					private				private

	private			public				private
					protected			private
					private				public

	���۲���ʲô����������ʽ���������ж����ܷ��ʻ����˽�г�Ա
*/
class BaseTest
{
public:
	int getI();

protected:
	int i_ = 0;
private:
	int x_ = 0;
};

class Y1 :public BaseTest//����������i���ܱ�����getI�ǹ���
{
	void test();
};

//����������i���ܱ�����getI������ܱ�����Ա�������಻�ܷ���
class Y2 :protected BaseTest
{
	void test();
};

//˽��������i��getI�������˽�г�Ա
class Y3 :private BaseTest
{
	void test();
};

//��ʱY3���г�Ա��˽�У�����Y4���ܷ���Y3�����г�Ա
class Y4 :public Y3
{
	void test();
};

class Y5 :public Y2
{
	void test();
};

class Y6 :public Y1
{
	void test();
};

/*
�̳��빹�캯������������

	���캯�������������ĵ��ô���

	1�����캯���ĵ��ô���
		�ڴ���һ��������Ķ���ʱ
			�ȵ��������Ĺ��캯��
			�ڵ��ñ�������Ա�Ĺ��캯��
			����ٵ��ñ���Ĺ��캯��

	2�����������ĵ��ô���
		�ȵ��ñ������������
		�ڵ��ñ�������Ա����������
		����ٵ�����������������
*/

class C
{
public:
	C();
	~C();
};

class BaseT2
{
public:
	BaseT2();
	~BaseT2();
};

class D :public BaseT2
{
public:
	D();
	~D();
private:
	C obj_;
};

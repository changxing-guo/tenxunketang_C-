#include <iostream>
#include "Square.h"
#include "Teacher.h"
#include "Demo.h"

using namespace std;

void test1() {
	Square square;
	square.setPosition(1, 1);
	square.setLength(3);

	point p1, p2, p3;

	p1.setPosition(1, 1);
	p2.setPosition(2, 2);
	p3.setPosition(4, 5);

	bool test;
	test = square.isContain(p1);
	cout << "p1 is exit = " << test << endl;

	test = square.isContain(p2);
	cout << "p2 is exit = " << test << endl;

	test = square.isContain(p3);
	cout << "p3 is exit = " << test << endl;
}

void test2() {
	//���Դ������Ĺ��캯��
	Square square(10);
}

void test3() {
	Teacher t(22, "jack");
	t.setAppend("jack is a good!");
	printf("age = %d, info = %s\n", t.getAge(), t.getInfo());
	printf("append is %s\n", t.getAppend());
}


// ���캯���ĵ��÷�ʽ�͵���
void test4() {
	//�޲ι��캯��
	Demo a;				// Ĭ�Ϲ���
	Demo a1 = Demo();	// ��ʽ��
	printf("\n");

	//�вι��캯�����ܹ�������
	Demo b(1);			//C++������Ĭ�ϵ����вι��캯��
	Demo b1(1, 2);
	printf("\n");

	// "="������ǿ��
	Demo c = 1;			//C++������Ĭ�ϵ����вι��캯��
	Demo c1 = (1, 2);	//Demo c1 = 2;�൱�ڱ��ʽ��ȡ���һ��ֵ
	printf("\n");

	Demo d = Demo(1);
	Demo d1 = Demo(1, 2);
	printf("\n");

	//��ֵ���캯��
	Demo e = d1;
	printf("\n");
}

//��ֵ�����������캯������ʹ�ó���
//1)��һ�ֳ�����ʹ�õȺŸ�ֵ
void test5() {
	Demo a(1, 2);
	a.print();
	printf("\n");

	Demo b = a;//�����û�и�ֵ���캯����C++��������ʹ��Ĭ�ϵĸ�ֵ���캯��
	b.print();
	printf("\n");

	Demo c(3, 4);//��ֵ���캯�����ҽ������������ʱ�����
	c.print();
	c = a;	//�������ķ�������
	c.print();
	printf("\n");
}

//2)�ڶ��ֳ�����ʹ�����Ÿ�ֵ
void test6() {
	Demo a(1, 2);
	a.print();
	printf("\n");

	Demo b(a); //���ø�ֵ���캯��
	b.print();
	printf("\n");
}

//3)�����ֳ�������Ķ�����Ϊ�������βΣ�����ø�ֵ���캯��
void disPlay(Demo d) {
	d.print();
}

void test7() {
	Demo a(3, 2);
	disPlay(a);//���ø�ֵ���캯��
}

//4)�����ֳ�������Ķ�����Ϊ�����ķ���ֵ,����ø�ֵ���캯���𣿻�
Demo getObj() {
	Demo a(10, 20);
	a.print();
	return a;
}

void test8() {
	//1��û�ж�����շ��صĶ��󣬻ᴴ��һ����������
	//getObj();

	//2��ʹ�ú������صĶ����ʼ���µĶ���
	//Demo b = getObj();//�����˸�ֵ���캯��
	//b.print();

	//3��ʹ�ú������صĶ���ֵ����һ���������᣿
	Demo c(1, 2);
	c.print();
	printf("\n");

	//������һ����������������������˸�ֵ���캯��������ֵ��c������Լ�����
	//c++�������Լ�͵͵���ģ�һ��Ҫ��ס
	c = getObj();
	printf("\n");

	c.print();
}

//ǳ��Ĭ�Ϲ��캯��
class Demo1 {
	int m_a;
	int m_b;
	//Ĭ�Ͽ������캯����Գ�Ա����ִ�м򵥵�ֵ�����������Ա��������ָ����ô��
	//char *p;
	
public :
	//Ĭ�Ϲ��캯������Բ������г�ʼ�����������ֵ���ǵ��û����ʧ��

	//�й��캯������Ա�������Բ���ʼ���ģ�������ֵ�������
	Demo1() {};
	void setA(int a);
	int getA();
};

void Demo1::setA(int a)
{
	m_a = a;
}

int Demo1::getA()
{
	return m_a;
}

void test9() {
	Demo1 d1, d2;

	d1.setA(1);
	d2.setA(2);

	//ʹ��Ĭ�Ϲ��캯�����Բ���ֵ���п���
	Demo1 d3 = d1;

	cout << d1.getA() << endl;
	cout << d2.getA() << endl;
	cout << d3.getA() << endl;
}

//ǳ��C++������������������
//Ĭ����ʽ���ã���ʼ������

//���캯�����ù����о�
/*
	1��������û�ж����κ�һ�����캯��ʱ��c++���������ṩĬ�Ϲ��캯����Ĭ�Ͽ������캯��
	2�������ж���ɿ������캯��ʱ��c++�����������ṩ�޲������캯��
	3�������ж���������ķǿ������캯���������������ṩ���вι��캯�����޲ι��캯������
	c++�����������ṩĬ���޲ι��캯��
	4��Ĭ�Ͽ������캯����Ա�����򵥸�ֵ
	�ܽ᣺ֻҪ��д���캯������ô�������
*/


int main(void) {

	test9();
	return 0;
}

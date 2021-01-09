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

int main(void) {

	test8();
	return 0;
}
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
	//测试带参数的构造函数
	Square square(10);
}

void test3() {
	Teacher t(22, "jack");
	t.setAppend("jack is a good!");
	printf("age = %d, info = %s\n", t.getAge(), t.getInfo());
	printf("append is %s\n", t.getAppend());
}


// 构造函数的调用方式和调用
void test4() {
	//无参构造函数
	Demo a;				// 默认构造
	Demo a1 = Demo();	// 显式的
	printf("\n");

	//有参构造函数，总共有三种
	Demo b(1);			//C++编译器默认调用有参构造函数
	Demo b1(1, 2);
	printf("\n");

	// "="功能增强，
	Demo c = 1;			//C++编译器默认调用有参构造函数
	Demo c1 = (1, 2);	//Demo c1 = 2;相当于表达式，取最后一个值
	printf("\n");

	Demo d = Demo(1);
	Demo d1 = Demo(1, 2);
	printf("\n");

	//赋值构造函数
	Demo e = d1;
	printf("\n");
}

int main(void) {

	test4();
	return 0;
}
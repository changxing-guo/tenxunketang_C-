#include <iostream>
#include "Square.h"
#include "Teacher.h"

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

int main(void) {

	test3();
	return 0;
}
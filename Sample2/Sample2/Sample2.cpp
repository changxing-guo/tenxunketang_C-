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

//赋值（拷贝）构造函数四种使用场景
//1)第一种场景，使用等号赋值
void test5() {
	Demo a(1, 2);
	a.print();
	printf("\n");

	Demo b = a;//如果类没有赋值构造函数，C++编译器会使用默认的赋值构造函数
	b.print();
	printf("\n");

	Demo c(3, 4);//赋值构造函数当且仅当创建对象的时候调用
	c.print();
	c = a;	//这个是类的符号重载
	c.print();
	printf("\n");
}

//2)第二种场景，使用括号赋值
void test6() {
	Demo a(1, 2);
	a.print();
	printf("\n");

	Demo b(a); //调用赋值构造函数
	b.print();
	printf("\n");
}

//3)第三种场景，类的对象作为函数的形参，会调用赋值构造函数
void disPlay(Demo d) {
	d.print();
}

void test7() {
	Demo a(3, 2);
	disPlay(a);//调用赋值构造函数
}

//4)第四种场景，类的对象作为函数的返回值,会调用赋值构造函数吗？会
Demo getObj() {
	Demo a(10, 20);
	a.print();
	return a;
}

void test8() {
	//1、没有对象接收返回的对象，会创建一个匿名对象
	//getObj();

	//2、使用函数返回的对象初始化新的对象
	//Demo b = getObj();//调用了赋值构造函数
	//b.print();

	//3、使用函数返回的对象赋值给另一个变量，会？
	Demo c(1, 2);
	c.print();
	printf("\n");

	//创建了一个匿名对象，匿名对象调用了赋值构造函数，他赋值给c对象后自己销毁
	//c++编译器自己偷偷做的，一定要记住
	c = getObj();
	printf("\n");

	c.print();
}

//浅析默认构造函数
class Demo1 {
	int m_a;
	int m_b;
	//默认拷贝构造函数会对成员变量执行简单的值拷贝，如果成员变量中有指针怎么办
	//char *p;
	
public :
	//默认构造函数不会对参数进行初始化，如果不赋值就是调用会编译失败

	//有构造函数，成员变量可以不初始化的，但他的值是随机的
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

	//使用默认构造函数，对参数值进行拷贝
	Demo1 d3 = d1;

	cout << d1.getA() << endl;
	cout << d2.getA() << endl;
	cout << d3.getA() << endl;
}

//浅析C++编译器构造析构方案
//默认隐式调用，初始化参数

//构造函数调用规则研究
/*
	1）当类中没有定义任何一个构造函数时，c++编译器会提供默认构造函数和默认拷贝构造函数
	2）当类中定义可拷贝构造函数时，c++编译器不会提供无参数构造函数
	3）当类中定义了任意的非拷贝构造函数（即：当类中提供了有参构造函数或无参构造函数），
	c++编译器不会提供默认无参构造函数
	4）默认拷贝构造函数成员变量简单赋值
	总结：只要你写构造函数，那么你必须用
*/


//6、4 深拷贝和浅拷贝
/*
	默认复制构造函数可以完成对象的数据成员简单的赋值
	对象的成员变量是由指针指示的内存地址，默认复制构造函数仅作复制指针的值
*/

void test10() {
	Teacher A("jack");
	cout << "name = " << A.getName() << endl;

	Teacher b = A;
	cout << "name = " << b.getName() << endl;
	//程序结束时，两次释放了name指针，导致异常
}


int main(void) {

	test10();
	return 0;
}

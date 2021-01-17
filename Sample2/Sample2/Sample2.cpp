#include <iostream>
#include "Square.h"
#include "Teacher.h"
#include "Demo.h"
#include "Demo2.h"
#include "Shape.h"

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

public:
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
	Teacher A("Jack");
	cout << "name = " << A.getName() << endl;

	Teacher b = A;//浅拷贝，复制指针的值
	cout << "name = " << b.getName() << endl;
	//程序结束时，两次释放了name指针，导致异常
}

/*
	浅拷贝程序c++提供的解决方法
		显式提供拷贝构造函数
		显式操作重载=号操作，不适用编译器提供的浅copy.
		默认的=号等同于浅拷贝
*/

//构造函数初始化列表
/*
1、为什么要有初始化列表
	1.1
	如果我们有一个类成员，它本身是一个类或者一个结构，而且这个成员只有一个带参数的构造函数，没有默认构造函数
	这时要对这个类成员进行初始化，就必须调用这个类成员的带参数的构造函数

	如果没有初始化列表，那么直接报错

	1.2
	类成员中有const修改，必须在对象初始化的时候，就给此变量赋值
	当类成员中哪有一个const对象时，或者是一个引用时，他们也必须通过成员初始化列表进行初始化
*/
void test11() {
	Demo2 d2;
	printf("d2.a = %d, d2.b = %d\n", d2.m_a.getValue(), d2.m_b.getValue());
}

// 构造函数中调用构造函数
void test12() {
	Demo2_B(1, 2);
	//system("pause");
}

/*
6,8 对象的动态建立和释放
	1、new 和 delete基本用法
		是运算符，不是函数，因此执行效率高

	2、c++兼容malloc和free，但是建议用户不用malloc和free

*/
// 分配基础类型
void test13() {
	// 以前的方式
	int *p = (int *)malloc(sizeof(int));
	*p = 666;
	free(p);

	int *p1 = new int;
	int *p2 = new int(10);
	*p1 = 6666;
	delete p1;
	delete p2;

	printf("p1 = %d, p2 = %d\n", *p1, *p2);

}
//分配数组
void test14() {
	int *p = (int *)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++) {
		p[i] = i;
	}
	free(p);

	int *p1 = new int[10];
	//删除数组所占的内存比较特别
	delete[] p1;

	char *p2 = new char[100];
	delete[] p2;
}

//分配对象
void test15() {
	//new 和delete执行作用域类的对象时，会调用构造和析构函数
	Demo2_B *d = new Demo2_B(1, 2);
	delete d;
	printf("\n");

	// malloc不会调用构造和析构函数，只是分配空间而已
	Demo2_B *d2 = (Demo2_B *)malloc(sizeof(Demo2_B));
	free(d2);
	printf("\n");

	//如果类没有构造函数，可以创建对象数组
	//如果有构造函数（不带参数），可以创建对象数组
	//以上这两种情况都可以创建对象数组
	Demo2_C *d3 = new Demo2_C[10];
	delete[] d3;
	printf("\n");

	//没有默认构造函数或无参构造函数时。可以创建对象数组。可以使用参数列表
	Demo2_A *d4 = new Demo2_A[2]{ (1), (2) };
	delete[] d4;
	printf("\n");

	//灵活创建对象，可以先定义指针数组，再逐个创建对象
	Demo2_B *d5[5];
	for (int i = 0; i < 5; i++) {
		d5[i] = new Demo2_B(i, i + 1);
	}
	for (int i = 0; i < 5; i++) {
		delete d5[i];
	}
}
/*
	new 和 delete补充
	分配基本类型可以混用（强烈建议不要混用）
	malloc不会调用类的构造函数
	free不会调用类的析构函数

	如无法分配空间，new会返回NULL
*/

/*
静态成员变量

1）定义静态成员变量
	static关键字
	一个类的成员为static时，这个类无论有多少个对象被创建，这些对象共享这个一个static成员
	静态成员局部与类，他不是对象成员

2）静态数据成员初始化
	静态成员初始化与一般数据成员初始化不同，
	<数据类型><类名>::<静态数据成员名>=<值>	//静态变量的初始化

3）应用静态数据成员是，采用如下格式
	<类名>::<静态成员名>	//静态变量的使用方式

	如果创建了对象，也可以用对象来访问
	<对象名.静态成员名>或<对象->静态成员名>

*/
//静态变量声明必须在类和方法的外面
int Demo2_C::m_s = 10;
void test16() {
	Demo2_C c;
	printf("Demo2_C::m_s = %d\n", Demo2_C::m_s);
	printf("Demo2_C::m_s = %d\n", c.m_s);
	printf("\n");

	Demo2_C::m_s = 5;
	printf("Demo2_C::m_s = %d\n", Demo2_C::m_s);
	printf("Demo2_C::m_s = %d\n", c.m_s);
	printf("\n");

	c.m_s = 20;
	printf("Demo2_C::m_s = %d\n", Demo2_C::m_s);
	printf("Demo2_C::m_s = %d\n", c.m_s);

}

/*
类的静态函数和单例模式
*/
int Demo2_C::m_b = 100;	//初始化

void test17() {
	printf("m_B = %d\n", Demo2_C::getB());

	Demo2_C::setB(20);
	printf("m_B = %d\n", Demo2_C::getB());
}

//单例模式测试
Demo2_C * Demo2_C::single = NULL;	//单例模式静态变量初始化
void test18() {
	Demo2_C * d1 = Demo2_C::getInstance();
	Demo2_C * d2 = Demo2_C::getInstance();
	d1->setB(6666);	//这个是静态变量，
	d1->m_d = 1000;	//我们测试下非静态的
	printf("d1->getB = %d\n", d1->getB());
	printf("d2->getB = %d\n", d1->getB());
	printf("d2->m_d = %d\n", d2->m_d);
	printf("\n");

	d2->setB(8888);
	d2->m_d = 2000;
	printf("d1->getB = %d\n", d1->getB());
	printf("d2->getB = %d\n", d1->getB());
	printf("d1->m_d = %d\n", d1->m_d);
	printf("\n");

	//同一个对象
	printf("d1 %p\n", d1);
	printf("d2 %p\n", d2);
}

/*
this 指针及其本质
*/
void test19() {
	Car c;
	c.setPrice(10000);

	//思考。这样调用为什么不会出问题？
	//因为这个方法没有用到this，bmv本质是this
	Car *bmw = NULL;
	bmw->Hello();

	//c++的本质就是CCar的实现
	CCar cc;
	setCPrice(&cc, 20000);
	printf("cc price = %d\n", cc.m_price);

	//测试思考：类中添加静态变量。sizeof（类）会不会变大
	int size = testCarSize();
	printf("car sizeof = %d\n", size);
}

// 友元
/*
友元函数
	1、友元函数通过对象参数访问私有数据成员
	2、类内部都要声明友元函数，声明于位置无关

	思考：为什么要有友元函数？
	打破类的封装，为外部接口留下一个便捷的接口
*/

/*
友元类
	若B类是A类的友元类，则B类的所有成员函数都是A类的成员函数
	友元类通常涉及为一种对数据操作或类之间传递消息的辅助类
*/
void test20() {
	SaleCar sc;
	cout << "sc.price = " << sc.getPrice() << endl;

	sc.buyCar();
	cout << "sc.price = " << sc.getCost() << endl;
}

/*
什么是运算符重载
*/
//重载二元运算符之成员函数方式
void test21() {
	Complex c1(1, 1);
	Complex c2(2, 2);
	Complex c3 = c1.add(c2);
	c3.display();

	Complex c4 = c3 + c2;
	c4.display();

	Complex c5 = c4 - c1;
	c5.display();

	Complex c6 = c5 * c4;
	c6.display();

	Complex c7 = c5 / c4;
	c7.display();

}

//二元运算符之友元函数
void test22() {

	Complex c1(1, 2);
	Complex c2(2, 3);

	Complex c3 = c1 + c2;
	c3.display();

	Complex c4 = c1 + 6;
	c4.display();

	Complex c5 = 6 + c2;
	c5.display();
}

//重载一元运算符之成员函数方式
void test23() {
	Time t1(22, 31, 59);

	++t1;
	t1.display();

}

//重载一元运算符之友元函数方式
void test24() {
	Time_F t1(22, 31, 59);

	++t1;
	t1.display();

}

void test25() {
	Time t1(22, 31, 59);
	Time t2 = t1++;
	t2.display();
	t1.display();

}

void test26() {
	Time_F t1(22, 31, 59);
	t1--;
	t1.display();
}

void test27() {
	String s1("jack");
	s1.print();

	{
		String s2("hello");
		s2 = s1;
		// 此时这儿=好的具体含义
		// s2.m_len = s2.m_len， s2.m_ptr = s1.m_ptr
		s2.print();
	}
	//s2释放后将s1.m_ptr指针的内存释放了，导致s1指针指向的内存被释放，所以打印为乱码
	//同时s2定义是申请的内存也没有被释放，整个程序结束后才会被释放
	s1.print();
	//system("pause");
}
//程序结束后多次释放同一块内存，会导致程序异常


void test28() {
	String_A s1("jack");
	s1.print();

	{
		String_A s2("hello");
		s2 = s1;
		s2.print();
	}
	s1.print();
	//system("pause");
}

void test29()
{
	cout << "s1 test\n";
	String_A s1("jack");
	s1.print();

	cout << "\ns2 test\n";
	String_A s2(s1);
	s2.print();

	//此操作相当于拷贝构造函数
	cout << "\ns3 test\n";
	String_A s3 = s1;//虽然有=，但是s3是新生成的，所以他调用的还是拷贝构造函数
	s3.print();

	cout << "\ns4 test\n";
	//如果你要使用赋值函数，则需要不能在声明变量的同时直接赋值
	String_A s4("hello");
	s4 = s1;
	s4.print();
}

//类的继承测试
void test30()
{
	//派生类的对象调用函数时受继承形式限制
	Rectangle a;
	a.setHeight(10);
	a.setWidth(5);

	cout << a.getArea() << endl;
}

//继承的语法
void test31()
{
	Date a(2021);
	a.printDate();

	Date_Europe b;
	b.printDate();

	Date c(2021, 1, 1);
	c.printDate();

	Date_Europe d(2021, 1, 1);
	d.printDate();

	printf("\n");

	Date_Europe e(2020, 4, 8);
	e.print(true);
	e.print(false);
	printf("\n");

	//使用类名限定符
	Date_Europe f(2020, 4, 8);
	f.Date::printDate();

}

//继承访问控制规则
void test32()
{
	Y1 y1;
	Y2 y2;

	int temp;
	temp = y1.getI();
	//temp = y2.getI();//不能访问

	Y5 y5;
	Y6 y6;
	//temp = y5.getI();//不能访问
	temp = y6.getI();
}

void test33()
{
	D d;
}

void test34()
{
	Base2_1(1, 2, 3, 4, 5);
	/*
		先调用基类构造函数
		在调用派生类内部对象构造函数
		最后调用派生类构造函数
	*/
}

void test35()
{
	Base3_1 a;
	a.setI(5);
	a.setJ(6);
	cout << "i+j = " << a.getIJ() << endl;
	a.print();
}

void test36()
{
	Base6 obj;
	obj.set(1, 2);
	obj.show();
}

int main(void)
{

	test36();
	return 0;
}

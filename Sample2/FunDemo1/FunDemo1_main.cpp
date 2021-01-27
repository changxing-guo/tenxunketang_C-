#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int max(int x, int y)
{
	cout << "int max(int x, int y)" << endl;
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

float max(float x, float y)
{
	cout << "float max(float x, float y)" << endl;
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

//类模板
template <typename T>
T max_t(T x, T y)
{
	cout << "sizeof T = " << sizeof(T) << endl;
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

template <typename T1, typename T2>
void  max_t1(T1 x, T2 y)
{
	cout << "sizeof T = " << sizeof(T1) << endl;
	//return 0;
}

template <typename T>
T max_value(T x, T y, T z)
{
	cout << "max_value(T x, T y, T z)" << endl;
	T temp;
	temp = x > y ? x : y;
	return temp > z ? temp : z;
}

int test1(void)
{
	int a = 1;
	int b = 2;
	int c = max(a, b);
	cout << "c = " << c << endl;

	float f1 = 21;
	float f2 = 20;
	float f3 = max(f1, f2);
	cout << "f3 = " << f3 << endl;

	double d1 = 30;
	double d2 = 44;
	double d3 = max_t(d1, d2);
	cout << "d3 = " << d3 << endl;

	char c1 = max_t('a', 'A');
	cout << "c1 = " << c1 << endl;

	//求取三个数中的最大值
	cout << "求取三个数中的最大值" << endl;
	cout << max_value(12, 34, 23) << endl;
	cout << max_value(12.0, 34.2, 23.4) << endl;
	cout << max_value('a', 'b', 'c') << endl;

	//system("pause");
	return 0;
}

// 编写一个带有两个形式参数的函数模板，可以按指定的操作数类型相乘
template <typename P1, typename P2>
P1 cal(P1 x, P2 y)	// 有两个参数化类型名：P1和P2
{
	return (x * (P1)y);
}

void test2()
{
	int w = 2;
	float z = 1.5;

	cout << cal(w, z) << endl;
	cout << cal(z, w) << endl;
}

// 函数模板的形式参数表中除了使用参数化类型名（T array)以外
// 还可以使用确定类型的参数（int num）
template <class T>
void ArrayInput(T array, int num)
{
	cout << "输入" << num << "个" << typeid(T).name()
		<< "\b" << "型数据类型" << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> array[i];
	}
}

void test3()
{
	int number;
	char charArray[3];

	number = sizeof(charArray) / sizeof(char);
	ArrayInput(charArray, number);

	for (int i = 0; i < number; i++)
	{
		cout << charArray[i] << " ";
	}
	printf("\n\n");

	int intArray[3];
	number = sizeof(intArray) / sizeof(int);
	ArrayInput(intArray, number);

	for (int i = 0; i < number; i++)
	{
		cout << intArray[i] << " ";
	}
	printf("\n\n");

	float floatArray[3];
	number = sizeof(floatArray) / sizeof(float);
	ArrayInput(floatArray, number);

	for (int i = 0; i < number; i++)
	{
		cout << floatArray[i] << " ";
	}
	printf("\n\n");

}

//重载函数模板
/*
重载函数模板可以是函数模板和另一个参数数目不同的函数模板的重载
也可以是函数模板和非模板函数的重载，一般所说的函数模板重载是指后一种情况

	- 函数模板和非模板函数重载，可以解决函数模板不支持参数自动转换的问题
	- 当所使用的参数类型（不是类类型）不支持函数模板中某些操作时，就需要为
	这样的参数专门编写响应的非函数模板。和已经定义的函数模板形成重载的关系


*/
// 函数重载
template <typename T>
T max_value(T x, T y)
{
	cout << "max_value(T x, T y)" << endl;
	return x > y ? x : y;
}

void test4()
{
	max_value(1, 2);
	max_value(1, 2, 3);
}
// 比较结构体的大小
typedef struct student
{
	char name[20];
	float score;

}Student;
// 非模板函数重载，可以解决函数模板不支持参数自动转换的问题
// 所以要自定义非模板函数
Student max_value(Student s1, Student s2, Student s3)
{
	Student temp;
	temp = s1.score > s2.score ? s1 : s2;
	return temp.score > s3.score ? temp : s3;
}

void test5()
{
	Student s1;
	strcpy(s1.name, "jack");
	s1.score = 100;
	Student s2;
	strcpy(s2.name, "gcx");
	s2.score = 120;
	Student s3;
	strcpy(s3.name, "sr");
	s3.score = 99;

	Student s4 = max_value(s1, s2, s3);
	cout << s4.name << " : " << s4.score << endl;

}

// 类模板
template <class T1, class T2>
class MyClass
{
private:
	T1 x;
	T2 y;
	int z;

public:
	MyClass(T1 a, T2 b);
	void display();
	void setX(T1 a);
	void setZ(int c);
};

/*
在类模板的外部定义类模板的成员函数时的格式
	- 首先要使用类模板的头部，以表明类模板定义了几个参数化类型名
	- 作用域预算符“::”签名的类名用类模板名代替，而且也要在尖括号中注明所有类模板的参数化类型名
	- 函数的参数表或自动变量的定义，则是可以使用参数化类型名，也可以不使用
*/

template <class T1, class T2>
MyClass<T1, T2>::MyClass(T1 a, T2 b)
	:x(a), y(b)
{
}

template <class T1, class T2>
void MyClass<T1, T2>::display()
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}

template <class T1, class T2>
void MyClass<T1, T2>::setX(T1 a)
{
	x = a;
}

template <class T1, class T2>
void MyClass<T1, T2>::setZ(int c)
{
	z = c;
}

void test6()
{
	MyClass<int, float> s1(6, 10.1);
	s1.display();
	printf("\n");

	MyClass<char, char *> s2('A', "this is a test");
	s2.display();
}


int main(void)
{
	test6();
	system("pause");
	return 0;
}
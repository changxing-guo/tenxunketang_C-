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

int main(void)
{
	test3();
	system("pause");
	return 0;
}
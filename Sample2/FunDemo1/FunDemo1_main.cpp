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

int main(void)
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

	system("pause");
	return 0;
}
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

void test1()
{
	vector<int> int_vector;
	// 1、容器
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int temp = rand() % 100;
		int_vector.push_back(temp);
	}

	cout << "排序前" << endl;
	for (auto it = int_vector.begin(); it != int_vector.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n\n");

	cout << "排序后" << endl;
	sort(int_vector.begin(), int_vector.end());
	for (auto it = int_vector.begin(); it != int_vector.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n\n");
}

class People
{
public:
	People(string name)
	{
		name_ = name;
	}

	bool operator < (const People &other)
	{
		return (this->name_.compare(other.name_) < 0);
	}

	string &getName()
	{
		return name_;
	}

private:
	string name_;
};

//测试自定义对象
void test2()
{
	vector<People> people_vector;
	people_vector.push_back(People(string("jack")));
	people_vector.push_back(People(string("sr")));
	people_vector.push_back(People(string("lqh")));

	cout << "排序前" << endl;
	for (auto it = people_vector.begin(); it != people_vector.end(); it++)
	{
		cout << it->getName().c_str() << endl;
	}
	printf("\n\n");

	cout << "排序后" << endl;
	sort(people_vector.begin(), people_vector.end());
	for (auto it = people_vector.begin(); it != people_vector.end(); it++)
	{
		cout << it->getName().c_str() << endl;
	}
	printf("\n\n");
}

int main(void)
{
	test2();

	system("pause");
	return 0;
}
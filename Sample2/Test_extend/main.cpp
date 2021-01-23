#include <iostream> 

using namespace std;

//雇员类
class employee
{
protected:
	char *name;				// 姓名
	int individualEmpNo;	// 个人编号
	int grade;				// 等级
	float accumPay;			// 月薪总额
	static int employeeNo;	// 本公司职业编号目前的基数

public:
	employee()
	{
		char str[30];
		cout << "请输入员工姓名：";
		cin >> str;
		// 申请字符串数组
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str) + 1, str);
		individualEmpNo = ++employeeNo;
		grade = 1;
		accumPay = 0;
	}

	~employee()
	{
		delete[] name;
	}

	void pay() {};

	// 升级，提升的级数由incre指定
	void promore(int incre)
	{
		grade += incre;
	}

	void displayStatus() {};
};

int employee::employeeNo = 10000;

// 技术人员
class technician : public employee
{
private:
	float hourlyRate;		// 每小时薪酬
	int workHours;			// 一个月工作了多少个小时
public:
	technician()
	{
		hourlyRate = 50;	//每小时薪酬50块钱
	}
	void pay()
	{
		cout << "输入" << name << "工作的时数：";
		cin >> workHours;
		accumPay = hourlyRate * workHours;

		cout << "技术人员：" << name
			<< ", 编号：" << individualEmpNo
			<< ", 月薪：" << accumPay << endl;
	}

	void displayStatus()
	{
		cout << "技术人员：" << name
			<< ", 编号：" << individualEmpNo
			<< "，级别：" << grade
			<< ", 月薪：" << accumPay << endl;
	}
};

// 销售
class salesman : virtual public employee
{
protected:
	float commRate;		//按销售金额提成比列
	float sales;		//当月销售额

public:
	salesman()
	{
		commRate = 0.05;//销售提成比例
	}
	void pay()
	{
		cout << "输入" << name << "销售额：";
		cin >> sales;
		accumPay = commRate * sales;

		cout << "销售人员：" << name
			<< ", 编号：" << individualEmpNo
			<< ", 月薪：" << accumPay << endl;
	}

	void displayStatus()
	{
		cout << "销售人员：" << name
			<< ", 编号：" << individualEmpNo
			<< "，级别：" << grade
			<< ", 月薪：" << accumPay << endl;
	}
};

// 经理人员
class manager : public virtual employee
{
protected:
	float monthlyPay;	//固定月薪

public:
	manager()
	{
		monthlyPay = 10000;
	}

	void pay()
	{
		accumPay = monthlyPay;

		cout << "经理人员：" << name
			<< ", 编号：" << individualEmpNo
			<< ", 月薪：" << accumPay << endl;
	}

	void displayStatus()
	{
		cout << "经理人员：" << name
			<< ", 编号：" << individualEmpNo
			<< "，级别：" << grade
			<< ", 月薪：" << accumPay << endl;
	}
};

// 销售经理
class salesmanmanager : public manager, public salesman
{
public:

	salesmanmanager()
	{
		monthlyPay = 10000;
		commRate = 0.05;
	}

	void pay()
	{
		cout << "输入" << name << "所在部门的总销售额：";
		cin >> sales;
		accumPay = commRate * sales + monthlyPay;

		cout << "销售经理：" << name
			<< ", 编号：" << individualEmpNo
			<< ", 月薪：" << accumPay << endl;
	}

	void displayStatus()
	{
		cout << "销售经理：" << name
			<< ", 编号：" << individualEmpNo
			<< "，级别：" << grade
			<< ", 月薪：" << accumPay << endl;
	}
};

int main(void)
{
	/*{
		technician t1;
		t1.promore(3);
		t1.pay();
		t1.displayStatus();
	}*/

	/*{
		manager m1;
		m1.promore(10);
		m1.pay();
		m1.displayStatus();
	}*/
	/*
	salesman s;
	s.promore(11);
	s.pay();
	s.displayStatus();
	*/

	salesmanmanager s2;
	s2.promore(1);
	s2.pay();
	s2.displayStatus();

	system("pause");
	return 0;
}
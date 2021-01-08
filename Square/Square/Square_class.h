
/*
封装的两层含义
1、把属性和方法进行封装
2、对属性和方法进行访问控制

访问控制：private, protected, public
public: 修饰的成员变量和函数，可以再类内部和外部访问
private：修饰的成员变量和函数，只能在类内部被访问，不能在类的外部被访问
protected：修饰的成员变量和函数，只能在类内部被访问，不能在类的外部被访问，
被他修改的成员和函数可以用在继承和子类里面被访问
*/

/*
class 和 struct的区别
最大的区别就是默认访问控制的权限不一样，如果没有指定访问控制，默认就是public
struct在C++中已经进行了增强，作用和class基本一样
*/

/*
	这是一个正方形的周长面积计算类
*/
class Square_class {
	// 没有声明为public， protected, private, 默认是private
	double length;

public:
	void setLength(double len);	// 设置边长
	double getLength();			// 获取边长
	double getArea();			// 获取面积
	double getGirth();			// 获取周长
};

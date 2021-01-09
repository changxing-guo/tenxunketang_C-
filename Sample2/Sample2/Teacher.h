#pragma once
class Teacher
{
	int m_age;		// 年龄
	char *m_name;	// 姓名
	char *m_resume;	// 信息
	char *m_append;	// 附加资料

public:
	//Teacher();
	Teacher(const char *name);
	Teacher(int age, const char *resume);
	int getAge();
	char *getName();
	char *getInfo();
	void setAppend(const char * text);
	char * getAppend();
	~Teacher();
};


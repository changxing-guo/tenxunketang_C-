#pragma once
class Teacher
{
	int m_age;		// ����
	char *m_name;	// ����
	char *m_resume;	// ��Ϣ
	char *m_append;	// ��������

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


#pragma once
class Teacher
{
	int m_age;		// ����
	char *m_resume;	// ��Ϣ
	char *m_append;	// ��������

public:
	//Teacher();
	Teacher(int age, const char *resume);
	int getAge();
	char *getInfo();
	void setAppend(const char * text);
	char * getAppend();
	~Teacher();
};


#include "Teacher.h"
#include <iostream>


/*Teacher::Teacher()
{
}*/

Teacher::Teacher(int age, const char * resume)
{
	int len = strlen(resume);
	m_age = age;
	m_resume = (char *)malloc(len + 1);
	strcpy_s(m_resume, len + 1 , resume);

	// ��������ָ��Ĭ��Ϊ��
	m_append = NULL;
}

int Teacher::getAge()
{
	return m_age;
}

char * Teacher::getInfo()
{
	return m_resume;
}

void Teacher::setAppend(const char * text)
{
	// �˺������ܵ��ö�Σ�Ϊ��ֹ�ڴ�й©�����õ�ʱ����free
	if (m_append) {
		free(m_append);
	}
	int len = strlen(text);
	m_append = (char *)malloc(len + 1);
	strcpy_s(m_append, len + 1, text);
}

char * Teacher::getAppend()
{
	if (m_append) {
		return m_append;
	}
	return NULL;
}

Teacher::~Teacher()
{
	if (m_resume) {
		free(m_resume);
		m_resume = NULL;
	}
	if (m_append) {
		free(m_append);
		m_append = NULL;
	}	
}

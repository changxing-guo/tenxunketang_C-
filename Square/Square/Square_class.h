
/*
��װ�����㺬��
1�������Ժͷ������з�װ
2�������Ժͷ������з��ʿ���

���ʿ��ƣ�private, protected, public
public: ���εĳ�Ա�����ͺ��������������ڲ����ⲿ����
private�����εĳ�Ա�����ͺ�����ֻ�������ڲ������ʣ�����������ⲿ������
protected�����εĳ�Ա�����ͺ�����ֻ�������ڲ������ʣ�����������ⲿ�����ʣ�
�����޸ĵĳ�Ա�ͺ����������ڼ̳к��������汻����
*/

/*
class �� struct������
�����������Ĭ�Ϸ��ʿ��Ƶ�Ȩ�޲�һ�������û��ָ�����ʿ��ƣ�Ĭ�Ͼ���public
struct��C++���Ѿ���������ǿ�����ú�class����һ��
*/

/*
	����һ�������ε��ܳ����������
*/
class Square_class {
	// û������Ϊpublic�� protected, private, Ĭ����private
	double length;

public:
	void setLength(double len);	// ���ñ߳�
	double getLength();			// ��ȡ�߳�
	double getArea();			// ��ȡ���
	double getGirth();			// ��ȡ�ܳ�
};

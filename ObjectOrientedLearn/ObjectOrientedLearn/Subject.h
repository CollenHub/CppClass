#ifndef _SUBJECT_
#define _SUBJECT_
using namespace std;
#include<vector>
class Subject
{
	int m_value;
	//��������
	vector<Observer*> m_views;
	
public:
	void attach(Observer* obs)
	{
		m_views.push_back(obs);
}
	void set_val(int value)
	{
		m_value = value;
		notify();
	}
	void notify()
	{
		for (int i = 0; i < m_views.size(); ++i)
		{
			m_views[i]->update(this, m_value);
		}
	}
private:

};
/// <summary>
/// ���Ա��̳���Ϊ�۲��һ����
/// </summary>
class Observer
{
public:
	virtual void update(Subject* sub, int value)=0;

private:

};


#endif // !_SUBJECT_


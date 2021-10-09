#include <iostream>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "SThread.h"
using namespace std;

void* creatFun(void *arg);


class UserData
{
public:/*public fun*/
	UserData();
	~UserData();

	int startWork();
private:/*private fun*/
	static void CreatTask(void *arg);
	void pthread_fun();

private:/*private members*/
	bool m_work;
	int  m_num;
	CSThread  *m_task;
};


UserData::UserData(): m_work(true), m_num(10), m_task(NULL)
{

}

UserData::~UserData()
{

}

void UserData::pthread_fun()
{
	printf("m_work:%d, m_num:%d.\n", m_work, m_num);
	while(m_num)
	{
		printf("m_work:%d, m_num:%d.\n", m_work, m_num);
		m_num --;
	}
	
}

void UserData::CreatTask(void *arg)
{
	printf("called, arg(%p).\n", arg);
	if(arg)
	{
		UserData *ud = reinterpret_cast<UserData*>(arg);
		printf("ud:%p.\n", ud);
		ud->pthread_fun();
	}
}

int UserData::startWork()
{
	printf("this:%p.\n", this);
	m_task = new CSThread(CreatTask, (void*)this);
	int ret = m_task->StartTask();
	printf("StartTask return:%d.\n", ret);

	// printf("kill.\n");
	// m_task->Join();
}



int main()
{
	UserData ud;

    ud.startWork();


    sleep(5);

	return 0;
}
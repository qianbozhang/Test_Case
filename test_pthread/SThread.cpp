#include "SThread.h"
#include <unistd.h>
#include <stdio.h>

CSThread::CSThread(): m_bRunning(false), m_UserFun(NULL), m_UserData(NULL)
{

}

CSThread::CSThread(UserFun func, void* pUserData): m_bRunning(false), m_UserFun(func), m_UserData(pUserData)
{
	
}

CSThread::~CSThread()
{

}

int CSThread::StartTask()
{
	printf("StartTask:called.\n");
	if(m_bRunning)
	{
		return ERR_ALREADYRUNNING;
	}

    //线程属性
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	//创建脱离线程
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	int ret = pthread_create(&m_tObj, &attr, ThreadFunction, this);
	if(ret != 0)
	{
		return ERR_CANTSTARTTHREAD;
	}
	//线程创建好以后，释放线程属性
   pthread_attr_destroy(&attr);
	return 0;
}

int CSThread::Kill()
{
	if(!m_bRunning)
	{
		return ERR_NOTRUNNING;
	}

	m_bRunning = false;

	int ret = pthread_join(m_tObj, NULL);
	if(ret != 0)
	{
		return ERR_CANTKILLTHREAD;
	}
	return 0;
}

void CSThread::Join()
{
	pthread_join(m_tObj, NULL);
}

void CSThread::Sleep(unsigned long millliseconds)
{
	usleep(millliseconds * 1000);
}


void* CSThread::ThreadFunction(void *pThr)
{
	printf("ThreadFunction:called.\n");
	int ret = 0;
	CSThread *pThread = reinterpret_cast<CSThread*>(pThr);

	pThread->m_bRunning = true;

	if(pThread->m_UserFun != NULL)
	{
		printf("user fun.\n");
		pThread->m_UserFun(pThread->m_UserData);
	}else
	{
		printf("default fun.\n");
		pThread->RunThread();
	}

	pThread->m_bRunning = false;

	pthread_detach(pThread->m_tObj);
	pThread->m_tObj = (pthread_t)-1;

	pthread_exit(&ret);
	return 0;
}

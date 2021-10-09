#include "SThread.h"
#include <unistd.h>
#include <stdio.h>

CSThread::CSThread(): m_bRunning(false), m_UserFun(NULL), m_UserData(NULL), m_tObj(NULL)
{

}

CSThread::CSThread(UserFun func, void* pUserData): m_bRunning(false), m_UserFun(func), m_UserData(pUserData), m_tObj(NULL)
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

	int ret = pthread_create(&m_tObj, NULL, ThreadFunction, this);
	if(ret != 0)
	{
		return ERR_CANTSTARTTHREAD;
	}
	printf("threadId:%ld.\n", m_tObj);

	return 0;
}

int CSThread::StopTask()
{
    if(m_tObj != (pthread_t)NULL)
    {
    	int ret = pthread_join(m_tObj, NULL);
		if(ret != 0)
		{
			return ERR_CANTKILLTHREAD;
		}
    }
	
	return 0;
}


void* CSThread::ThreadFunction(void *pThr)
{
	printf("ThreadFunction:called.\n");
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
    //当线程结束后回收资源
    if( pThread->m_tObj != (pthread_t)NULL )
    {
    	printf("pthread_detach && pthread_exit\n");
    	pthread_detach(pThread->m_tObj);
		pThread->m_tObj = (pthread_t)-1;
    }
    pthread_exit(NULL);
	return 0;
}

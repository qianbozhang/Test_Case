#ifndef _STHREAD_H_
#define _STHREAD_H_

#include <pthread.h>


#define ERR_CANTINITMUTEX    -1
#define ERR_CANTSTARTTHREAD  -2
#define ERR_USERFUNNOTSET    -3
#define ERR_NOTRUNNING       -4
#define ERR_ALREADYRUNNING   -5
#define ERR_CANTKILLTHREAD   -6

typedef pthread_t  ThreadHandle;

typedef void (*UserFun)(void *UserData);

class CSThread
{
public:
	CSThread();
	CSThread(UserFun func, void* pUserData);
	virtual ~CSThread();


    int StartTask();
    int StopTask();

protected:
	virtual void RunThread()
	{

	}

private:
	//disable copy and assign
	CSThread(const CSThread &thr);
	CSThread& operator = (const CSThread& thr);

    //thread fun.
	static void* ThreadFunction(void* pThr); 

private:
	ThreadHandle    m_tObj;
	bool            m_bRunning;

	UserFun         m_UserFun;
	void            *m_UserData;
};

#endif
#ifndef JJLOG_H
#define JJLOG_H

#include <iostream>
#include <pthread.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <errno.h>

using namespace std;

#define DEBUG 10
#define SYSTEM 30
#define ERROR 50


//push log to logqueue of jjlogger. 
//by using singleton, every log will always written by same logger thread
#define JJLOG(level, arg) do{\
	JJLogger* pLogger = JJLogger::Instance();\
	char ThrId[16]; \
	snprintf(ThrId, sizeof(ThrId), "%08X", (unsigned int) pthread_self()); \
	ostringstream *pOSS = pLogger->Newoss(ThrId); \
	(*pOSS) << arg << " [" << __FILE__ << ":" << __LINE__ << "]\n"; \
	pLogger->Write(level, pOSS); \
} while(0)

#define SETLOGLEVEL(level) do{\
	JJLogger* pLogger = JJLogger::Instance();\
	pLogger->SetLogLevel(level);\
} while(0)


class JJLogger {
	public:
		JJLogger();
		static JJLogger* Instance();
		void Write(int plevel, ostringstream* pLog);
		ostringstream* Newoss(char* pThreeadId);
		void* RunLogger();
		void SetLogLevel(int parg);

	private:
		
		queue<ostringstream* >	m_logqueue;
		pthread_t 		m_PID;
		pthread_mutex_t		m_threadmutex;
		pthread_mutex_t		m_filemutex;
		int			m_queuelimit;
		char			m_filename[256];
		static JJLogger*	m_spInstance;

		int			m_level;
};

#endif

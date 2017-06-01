#include "JJlog.h"

//JJlogger support one type of log for one process. thus, we use singletone
JJLogger* JJLogger::m_spInstance = NULL;

void* LoggerThread(void* pArg){
	JJLogger* pLogger = (JJLogger*) pArg;
	pLogger->RunLogger();
	return NULL;
}

JJLogger::JJLogger(){
	m_level = 30; //default as SYSTEM
	m_queuelimit = 20000; //for limiting growth of queue
	sprintf(m_filename, "%s", "test.log"); // todo: change log name

	pthread_attr_t threadAttr;
	pthread_attr_init (&threadAttr);
	pthread_attr_setdetachstate(&threadAttr, PTHREAD_CREATE_DETACHED);
	pthread_attr_setstacksize(&threadAttr, 1024*1024);
	m_threadmutex = PTHREAD_MUTEX_INITIALIZER;
	m_filemutex = PTHREAD_MUTEX_INITIALIZER;

	if(pthread_create(&m_PID, &threadAttr, LoggerThread, (void*)this) !=0){
		cout << "JJLogger::pthread_create fail." << "Error no[" << errno
			<< "] msg [" << strerror(errno) << "]" << endl;
		sleep(1);
		exit(0);
	}
}

JJLogger* JJLogger::Instance(){
	if (m_spInstance)
		return m_spInstance;

	if (NULL == m_spInstance) {
		m_spInstance = new JJLogger;
	}

	return m_spInstance;
}

void* JJLogger::RunLogger(){
	ostringstream* currlog;
	FILE* fp;
	while(1){
		usleep(100);
		currlog = NULL;
		pthread_mutex_lock(&m_threadmutex);
		if(!m_logqueue.empty()){
			currlog = m_logqueue.front();
			m_logqueue.pop();
		}
		pthread_mutex_unlock(&m_threadmutex);
		
		if(currlog != NULL){
			pthread_mutex_lock(&m_filemutex);
			fp = fopen(m_filename, "a");
			if(NULL == fp){
				cout << "file open error. errno[" << errno << "] errmsg [" 
					<< strerror(errno) << "]" << endl;
				pthread_mutex_unlock(&m_filemutex);
				continue;
			}

			if(!fwrite(currlog->str().c_str(), 1, currlog->str().length(), fp)){
				cout << "fwrite error. errno[" << errno << "] errmsg [" 
					<< strerror(errno) << "]" << endl;
			}
			//delete currlog;
			fclose(fp);
			pthread_mutex_unlock(&m_filemutex);
		}
		//usleep(100);
	}
}

//make postfix of new log. current thread id + current time
ostringstream* JJLogger::Newoss(char* pThreadId){
	ostringstream* pOSS = new ostringstream;
	struct timeval tv;
	struct tm st;

	char strDateTimeUsec[32];
	gettimeofday(&tv, NULL);
	localtime_r(&tv.tv_sec, &st);
	snprintf(strDateTimeUsec, sizeof(strDateTimeUsec), "%04d%02d%02d-%02d%02d%02d.%06ld"
			, st.tm_year+1900, st.tm_mon+1, st.tm_mday, st.tm_hour, st.tm_min, st.tm_sec, tv.tv_usec);
	
	char buffer[128];
	sprintf(buffer, "%s %s] ", pThreadId, strDateTimeUsec);
	(*pOSS) << buffer;
	return pOSS;
}


void JJLogger::Write(int plevel, ostringstream* pLog){
	if(plevel < m_level){
		return;
	}

	pthread_mutex_lock(&m_threadmutex);

	//if logqueue if full, discard current log. 
	if(m_logqueue.size() > (unsigned int)m_queuelimit){
		cout << "log queue full." << endl;
		delete pLog;
	}else{
		m_logqueue.push(pLog);
	}

	pthread_mutex_unlock(&m_threadmutex);
}


void JJLogger::SetLogLevel(int parg){
	m_level = parg;
	return;
}


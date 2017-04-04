#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

void call_from_thread(int tid){
	cout << "start thread " << tid << endl;
}

int value;
mutex value_mutex;

void increase_value(){
	value_mutex.lock();
	value++;
	cout << value << endl;
	value_mutex.unlock();
}


int main(){
	thread t[10];

	//start 10 thread
	for(int i = 0; i<10; ++i){
		t[i] = thread(increase_value);
	}

	cout << "start main " << endl;

	for(int i = 0; i<10; ++i){
		t[i].join();
	}

}

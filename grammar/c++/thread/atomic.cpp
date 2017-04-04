#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>

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

void increase_atomic(atomic<int>* arg){
	arg->fetch_add(1);
	cout << "atom arg : " << *arg << endl;
}


int main(){
	thread t[10];
	atomic<int> atomarg;
	atomarg = 1;

	//start 10 thread
	for(int i = 0; i<10; ++i){
		//t[i] = thread(increase_value);
		t[i] = thread(increase_atomic, (&atomarg));
	}

	cout << "start main " << endl;

	for(int i = 0; i<10; ++i){
		t[i].join();
	}

}

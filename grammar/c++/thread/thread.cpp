#include <iostream>
#include <thread>

using namespace std;

void call_from_thread(int tid){
	cout << "start thread " << tid << endl;
}

int main(){
	thread t[10];

	//start 10 thread
	for(int i = 0; i<10; ++i){
		t[i] = thread(call_from_thread, i);
	}

	cout << "start main " << endl;

	for(int i = 0; i<10; ++i){
		t[i].join();
	}

}

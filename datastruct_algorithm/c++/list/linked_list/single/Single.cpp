#include <iostream>
#include <list>
#include <forward_list>

using namespace std;

int main(){
	forward_list<int> SLL;

	//add 5 node
	for(int i = 4; i >= 0; i--){
		SLL.push_front(i);
	}

	SLL.push_front(-1);
	SLL.push_front(-2);

	int cnt =0;
	for(auto i : SLL){
		cout << "List[" << cnt << "] : " << i << endl;
		cnt++;
	}

	
	cout << endl << " insert 3000 after [2] " << endl ;
	auto i = SLL.begin();
	i++;
	i++;
	SLL.insert_after(i, 3000);

	cnt = 0;
	for(auto i : SLL){
		cout << "List[" << cnt << "] : " << i << endl;
		cnt++;
	}

	cout << endl << " destroy list " << endl ;
	SLL.clear();
	cnt = 0;
	for(auto i : SLL){
		cout << "List[" << cnt << "] : " << i << endl;
		cnt++;
	}

	
	return 0;
}

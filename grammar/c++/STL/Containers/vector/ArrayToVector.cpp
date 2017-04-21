#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main(){


	vector<int> dataVec;

	int dataArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	unsigned dataArraySize = sizeof(dataArray) / sizeof(int);

	// Method 1: Copy the array to the vector using back_inserter.
	{
		copy(&dataArray[0], &dataArray[dataArraySize], back_inserter(dataVec));
	}
	cout << "===== copy ====" << endl;
	for(int i: dataVec){
		cout << i << " " ;
	}
	cout << endl;

	dataVec.clear();
	// Method 2: Same as 1 but pre-extend the vector by the size of the array using reserve
	{
		dataVec.reserve(dataVec.size() + dataArraySize);
		copy(&dataArray[0], &dataArray[dataArraySize], back_inserter(dataVec));
	}
	cout << "===== reserve & copy  ====" << endl;
	for(int i: dataVec){
		cout << i << " " ;
	}
	cout << endl;


	dataVec.clear();
	// Method 3: Memcpy
	{
		dataVec.resize(dataVec.size() + dataArraySize);
		memcpy(&dataVec[dataVec.size() - dataArraySize], &dataArray[0], dataArraySize * sizeof(int));
	}
	cout << "===== Memcpy  ====" << endl;
	for(int i: dataVec){
		cout << i << " " ;
	}
	cout << endl;


	dataVec.clear();
	// Method 4: vector::insert
	{
		dataVec.insert(dataVec.end(), &dataArray[0], &dataArray[dataArraySize]);
	}
	cout << "===== insert ====" << endl;
	for(int i: dataVec){
		cout << i << " " ;
	}
	cout << endl;



	dataVec.clear();
	// Method 5: vector + vector
	{
		vector<int> dataVec2(&dataArray[0], &dataArray[dataArraySize]);
		dataVec.insert(dataVec.end(), dataVec2.begin(), dataVec2.end());
	}
	cout << "===== vector+vector ====" << endl;
	for(int i: dataVec){
		cout << i << " " ;
	}
	cout << endl;
}

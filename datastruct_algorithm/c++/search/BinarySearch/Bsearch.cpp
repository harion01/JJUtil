#include <iostream>
#include <vector>
#include <algorithm>
#include "Score.h"

using namespace std;

pair<int,double> BinarySearch(vector<pair<int, double> >* Scores, double Target){
	int left = 0;
	int right = Scores->size();
	int mid = 0;
	pair<int, double> ret;

	while(left<=right){
		mid = (left+right)/2;
		cout << "loop - mid:" << Scores->at(mid).second  << " / target : " << Target << endl;
	
		if(Target == Scores->at(mid).second ){
			ret = Scores->at(mid);
			return ret;
		}else if(Scores->at(mid).second > Target){
			right = mid-1;
		}else if(Scores->at(mid).second < Target){
			left = mid+1;
		}
	}

	ret = make_pair(0,0);
	return ret;
}

bool comp(const pair<int,double> &a, const pair<int,double> &b){
	return a.second < b.second;
}

int main(){
	vector<pair<int, double> > scores;
	unsigned int Size = sizeof(DataSetOri)/sizeof(DataSetOri[0]);

	for(int i = 0 ; i < Size ; i++){
		scores.push_back(make_pair(DataSetOri[i].number , DataSetOri[i].score));
	}
	sort(scores.begin(), scores.end(), comp);
	
	pair<int, double> ans;
	ans = BinarySearch(&scores, 671.78);
	cout << "ret : " << ans.first << " / " << ans.second << endl;

}

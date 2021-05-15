#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> x, pair<int,int> y){
	if(x.first == y.first)
		return x.second<y.second;
	else
		return x.first<y.first;
}

int main(){
	
	int n;
	cin >> n;
	vector<pair<int,int> > v;
	int tempX, tempY;
	for(int i=0;i<n;i++){
		cin >> tempX >> tempY;
		v.push_back(pair<int,int>(tempX,tempY));
	}
	
	sort(v.begin(),v.end(),compare);
	
	for(int i=0;i<v.size();i++){
		cout << v[i].first << " " << v[i].second << "\n";
	}
	
	
	return 0;
}

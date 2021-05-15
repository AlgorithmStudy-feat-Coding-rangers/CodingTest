#include<iostream>
#include<vector> 
#include<algorithm>

using namespace std;

vector<pair<int, int>> v;
int n; 

bool compare(pair<int, int> a, pair<int, int> b){
		if(a.first == b.first)
			return a.second < b.second;
		else
			return a.first < b.first;
	
}

int main(){
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int x,y;
		cin >> x >> y;
		v.push_back(pair<int, int>(x,y));
	}
	
	sort(v.begin(), v.end(), compare);
	
	for(int i = 0; i < n; i++){
		cout << v[i].first << " " << v[i].second << "\n";
	}
}

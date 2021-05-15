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
	vector<pair<int,int> >v(n); 
	
	for(int i=0;i<n;i++){
		cin >> v[i].first >> v[i].second;
	}
	
	// i : bar
	for(int i=0;i<n;i++){
		int minIndex = i;
	    // j : bar 오른쪽 배열에서 최솟값 찾기 
	    for(int j=i;j<n;j++){
	      if(compare(v[j],v[minIndex])){
	        minIndex = j;
	      }
	    }
	    
	    // [i] [j] swap 
	    pair<int,int> temp = v[i];
	    v[i] = v[minIndex];
	    v[minIndex] = temp;
	}


	for(int i=0;i<v.size();i++){
		cout << v[i].first << " " << v[i].second << "\n";
	}
	
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string x, string y){
	if(x.size()==y.size())
		return x<y;
	return x.size()<y.size();
}

bool isCheck(vector<string>& v, string s){
	for(int i=0;i<v.size();i++){
		if(v[i]==s){
			return false;
		}
	}
	return true;
}

int main(){
	
	int n;
	cin >> n;
	vector<string> v;
	string temp;
	for(int i=0;i<n;i++){
		cin >> temp;
		if(isCheck(v,temp)){
			v.push_back(temp);
		}
	}
	
	sort(v.begin(),v.end(),compare);
	
	for(int i=0;i<v.size();i++){
		cout << v[i] << "\n";
	}
	
	
	return 0;
}

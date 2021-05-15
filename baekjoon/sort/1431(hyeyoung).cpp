#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getNumberSum(string s){
	int sum = 0;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i] && s[i]<='9' ){
			sum +=  s[i] - '0';
		}
	}
	return sum; //숫자 있으면 sum 반환 
}

bool compare(string x, string y){
	if(x.size()==y.size()){ //길이 같으면 
		int xSum = getNumberSum(x);
		int ySum = getNumberSum(y);
		if(xSum==ySum){  
			return x<y; //사전순 비교 
		}else{
			return xSum<ySum; //자리수합  
		}
	}
	return x.size()<y.size(); //길이 짧은거 우선 
}

int main(){
	
	int n;
	cin >> n;
	vector<string> v;
	string temp;
	for(int i=0;i<n;i++){
		cin >> temp;
		v.push_back(temp);
	}
	
	sort(v.begin(),v.end(),compare);
	
	for(int i=0;i<v.size();i++){
		cout << v[i] << "\n";
	}
	
	return 0;
}

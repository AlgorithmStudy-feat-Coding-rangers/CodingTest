#include<iostream>
#include<vector> 
#include<algorithm>
#include<cstring>

using namespace std;

vector<string> v;
int n; 

bool compare(string a, string b){
		if(a.length() == b.length())
			return a < b;
		else
			return a.length() < b.length();
	
}

int main(){
	
	cin >> n;

	
	for(int i = 0; i < n; i++){
		string str = "";
		cin >> str;		
		
		v.push_back(str);	
		
		for(int j = 0; j < v.size()-1; j++){
			if(str == v[j]){
				v.pop_back();
			}	
		}	
		
	}

	sort(v.begin(), v.end(), compare);
	
	for(int i = 0; i < v.size(); i++){
		
		cout << v[i] << "\n";
	}
}

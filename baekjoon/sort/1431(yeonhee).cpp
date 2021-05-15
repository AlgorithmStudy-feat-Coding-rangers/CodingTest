#include<iostream>
#include<vector> 
#include<algorithm>

using namespace std;

vector<string> v;
int n;  

bool compare(string a, string b){
		if(a.length() == b.length()){ // 길이 같으면 
			int countA = 0;
			int countB = 0;
			
			for(int i = 0; i < a.size(); i++){
				int numA = a.at(i)-'0';
				int numB = b.at(i)-'0';
				
				if(numA >= 0 && numA <= 9){
					countA += numA;
				}
				
				if(numB >= 0 && numB <= 9){
					countB += numB;
				}
			}
			if(countA == countB){
				return a < b;
			}else{
				return countA < countB;	
			}
		}else
			return a.length() < b.length(); // 짧은 것 먼저  
	
}

int main(){
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		string str = "";
		cin >> str;	
		
		v.push_back(str);	
	}
	
	sort(v.begin(), v.end(), compare);
	
	for(int i = 0; i < n; i++){
		cout << v[i] << "\n";
	}
}

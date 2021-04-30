#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	
	string str;
	bool minus = false;
	int result = 0;
	string num = "";

	cin >> str; //식을 문자열로  입력받기
	
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '+' || str[i] == '-'){	
			if(minus){
				result -= stoi(num); // string -> int 
			}else{
				result += stoi(num);
			}
	
			num = ""; //초기화 (이미 연산을 했으므로) 
			
			if (str[i] == '-') // 
				minus = true; 
			cout << result << endl;			
			continue;
		}
		
		// 숫자가 연속해서 나오는 동안 string으로 한 수로 붙이기 
		num += str[i];	 	
		
	}
	
	//마지막 남은 숫자 처리  
	if(minus){
		result -= stoi(num); // string -> int 
	}else{
		result += stoi(num);
	}
	
	cout << result;
}

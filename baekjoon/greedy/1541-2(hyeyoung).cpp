#include <iostream>
#include <string>
using namespace std;

int main(){
	
	string input;
	cin >> input;
	
	string number[50];
	string sign[50];
	
	for(int i=0;i<50;i++){
		number[i]=""; sign[i]="";
	} 
	
	int start = 0;
	int nIndex = 0;
	int sIndex = 0;
	for(int i=0;i<input.length();i++){
		if(input[i] == '+' || input[i]=='-'){
			number[nIndex++] = input.substr(start,(i-start));
			sign[sIndex++] = input[i];
			start = i+1;
		}
	}
	number[nIndex] = input.substr(start, input.length()-start);	 
	
	bool minus = false;
	int result = stoi(number[0]);
	for(int i=0;i<50;i++){
		if(sign[i]=="")	break;
		if(!minus && sign[i]=="+"){
			if(number[i+1]!="")
				result += stoi(number[i+1]);
		}else { // 한번이라도 -나오면 그 이후로 쭉 - 
			minus = true;
			if(number[i+1]!="")
				result -= stoi(number[i+1]);
		}
	}

	cout << result;
	
	return 0;
}

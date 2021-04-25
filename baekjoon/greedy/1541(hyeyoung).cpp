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
	for(int i=0;i<50;i++){
		if(sign[i]=="")	break;
		if(sign[i]=="-"){
			if(!minus){minus=true;}
		}
		else if(minus&&sign[i]=="+"){
			number[i] = to_string(stoi(number[i]) + stoi(number[i+1]));
			for(int j=i+1;j<50;j++){
				if(number[j]=="") break;
				number[j]=number[j+1];
			}
			for(int j=i;j<50;j++){
				if(sign[j]=="") break;
				sign[j]=sign[j+1];
			}
			i--;
		}
	}
	
	int result = stoi(number[0]);
	for(int i=0;i<50;i++){
		if(sign[i]=="") break;
		if(sign[i]=="+"){
			if(number[i+1]!="")
				result += stoi(number[i+1]);
		}else if(sign[i]=="-"){
			if(number[i+1]!="")
				result -= stoi(number[i+1]);
		}
	}
	cout << result;
	
	return 0;
}

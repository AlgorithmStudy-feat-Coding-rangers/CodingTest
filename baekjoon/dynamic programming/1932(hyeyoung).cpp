// 시간 초과 
#include <iostream>
using namespace std; 

int map[501][501];
int n;

int max(int i,int j){
		
	if(i==(n-1)) //맨 아래층이면 현재값만 return 
		return map[i][j];
	
	int d1 = max(i+1,j);
	int d2 = max(i+1,j+1);
		
	// 현재값 + 앞으로의 값 
	if(d1>d2){
		return map[i][j]+d1;
	}	
	else{
		return map[i][j]+d2;
	}
		
}

int main(){

	cin >> n;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			cin >> map[i-1][j];
		}
	} 
	
	cout << max(0,0);
	
	return 0;
}

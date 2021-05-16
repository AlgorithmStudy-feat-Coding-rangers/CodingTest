#include <iostream>
using namespace std; 

int map[501][501]; // 삼각형 값 
int dp[501][501]; // 최댓값  
int n;

int max(int i,int j){
		
	if(i==(n-1)){
		// 맨아래층이면 현재값만 return
		dp[i][j] = map[i][j];
		return dp[i][j]; 
	}
	if(dp[i][j]!=-1){
		// 전에 계산된 적 있으면 그 값 return
		return dp[i][j]; 
	}
	
	int d1 = max(i+1,j); // 왼쪽 선택 시 최댓값 
	int d2 = max(i+1,j+1); // 오른족 선택 시 최댓값 
		
	// 현재값 + 앞으로의 값 
	if(d1>d2){
		dp[i][j] = map[i][j]+d1;
	}	
	else{
		dp[i][j] = map[i][j]+d2;	
	}
	return dp[i][j];	
}

int main(){

	cin >> n;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			cin >> map[i-1][j];
			dp[i-1][j] = -1; // dp 초기화 
		}
	} 
	
	cout << max(0,0);
	
	return 0;
}

#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int dp[501][501]; //결과 저장용 리스트  

int max(int n1, int n2){
	return n1 > n2 ? n1 : n2;
}

int main(){
	int n;
	cin >> n;
	
	int t;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			scanf("%d", &dp[i][j]);
		}
	} 
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0){ // 가장 왼쪽 일 경우  
				dp[i][j] = 	dp[i][j] + dp[i-1][j];
			}else if( i == j ){ // 가장 오른쪽 일 경우 
				dp[i][j] = dp[i-1][j-1] + dp[i][j];
			}else{// max 값으로 지정  
				dp[i][j] = max(dp[i-1][j]+dp[i][j], dp[i-1][j-1]+dp[i][j]);
			}
		
		}
	} 
	
	int result = 0;
	
	for(int i = 0; i < n; i++){
		result = max(result, dp[n-1][i]);
	}
	
	cout << result;
}

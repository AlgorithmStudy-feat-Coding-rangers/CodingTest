#include <iostream>
using namespace std; 

int map[501][501]; // �ﰢ�� �� 
int dp[501][501]; // �ִ�  
int n;

int max(int i,int j){
		
	if(i==(n-1)){
		// �ǾƷ����̸� ���簪�� return
		dp[i][j] = map[i][j];
		return dp[i][j]; 
	}
	if(dp[i][j]!=-1){
		// ���� ���� �� ������ �� �� return
		return dp[i][j]; 
	}
	
	int d1 = max(i+1,j); // ���� ���� �� �ִ� 
	int d2 = max(i+1,j+1); // ������ ���� �� �ִ� 
		
	// ���簪 + �������� �� 
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
			dp[i-1][j] = -1; // dp �ʱ�ȭ 
		}
	} 
	
	cout << max(0,0);
	
	return 0;
}

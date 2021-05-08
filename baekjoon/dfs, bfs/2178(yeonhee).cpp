#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int n,m;
int map[101][101] = {0};

//상하좌우  
int dx[4] = {0, 0, -1, 1}; 
int dy[4] = {1, -1, 0, 0};


void bfs(int x, int y){
	
		queue<pair<int, int>> q;
     	q.push(pair<int,int>(x,y)); //큐에 쌍으로 값 넣기 

		while(!q.empty()){
			int currentX = q.front().first; // 현재 x 위치 확인  
			int currentY = q.front().second; // 현재 y 위치 확인  
			
			q.pop(); // 큐에서 제거  
				 
			//상하좌우로 움직이는 좌표  
			for(int i = 0; i < 4; i++){
				int afterX = currentX + dx[i]; 
				int afterY = currentY + dy[i]; 
				
				// 미로 범위 밖으로 나가면 무시 
				if(afterX < 0 || afterX > n || afterY < 0 || afterY > m){
					continue;
				} 
				
				if(map[afterX][afterY] == 1){
					map[afterX][afterY] = map[currentX][currentY] + 1; // 이전 방문값 + 1 = 다음 방문
					q.push(pair<int,int>(afterX,afterY));
				}
			
			}
		}
}


int main(){
 
	cin >> n >> m;

	//입력받은 미로 배열  
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%1d", &map[i][j]); // 공백 없이 붙은 입력 받기 
		}
	}
	
	
	bfs(1, 1);
	
	cout << map[n][m];
}

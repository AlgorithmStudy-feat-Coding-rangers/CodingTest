#include<iostream>
using namespace std;

int graph[1000][1000] = {0};
int visited[1000] = {0};

int result = 0; 

void dfs(int x, int n){

	visited[x] = 1; // 현재 노드 방문 표시  
	for(int i = 0; i < n; i++){
		if(visited[i] == 0 && graph[x][i] == 1) {
				dfs(i, n); 
		}
	}
}

int main(){
	int n, m; //정점의 개수 n, 간선의 개수 m  
	cin >> n >> m;
	
	//입력받은 컴퓨터 수 만큼 인접행렬 초기화  
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			graph[i][j] = 0;
		}
	}
	
	int u, v; // 간선의 양 끝점 u ,v
	for(int i = 0; i < m; i++){
			cin >> u >> v;
			graph[u-1][v-1] = 1;
			graph[v-1][u-1] = 1;
	}

	for(int i = 0; i < n; i ++){
		if(visited[i] != 1){
			result ++;
			dfs(i,n);
		}
	
	}

	
	cout << result;
}

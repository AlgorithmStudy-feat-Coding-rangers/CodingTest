#include <iostream>
using namespace std;

bool list[1000][1000]; // 2차원 배열롷 그래프 연결 관계 표현, 가중치 없으므로 type:bool 
bool visited[1000]; 

void f(int start, int node){
	visited[start] = true;
	for(int i=0;i<node;i++){
		if(list[start][i] && !visited[i]){ // start와 연결된 애들 중 아직 방문하지 않은 애 
			f(i, node);
		}
	}
}

int main(){
	
	int node;
	int link;
	cin >> node >> link;
	
	for(int i=0;i<node;i++){
		for(int j=0;j<node;j++){
			list[i][j] = false;
		}
		visited[i] = false;
	}
	
	int t1,t2;
	for(int i=0;i<link;i++){
		cin >> t1 >> t2;
		list[t1-1][t2-1] = true;
		list[t2-1][t1-1] = true;
	}
	
	int result = 0;
	for(int i=0;i<node;i++){
		if(!visited[i]){
			f(i,node); // i번째 애 통해 갈 수 있는 노드 다 방문 -> 연결 요소 1개 
			result++; // 연결 요소 개수 증가 
		}
	}
	
	cout << result;
	
	return 0;
}

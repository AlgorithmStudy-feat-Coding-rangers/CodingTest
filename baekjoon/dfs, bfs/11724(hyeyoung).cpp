#include <iostream>
using namespace std;

bool list[1000][1000]; // 2���� �迭�� �׷��� ���� ���� ǥ��, ����ġ �����Ƿ� type:bool 
bool visited[1000]; 

void f(int start, int node){
	visited[start] = true;
	for(int i=0;i<node;i++){
		if(list[start][i] && !visited[i]){ // start�� ����� �ֵ� �� ���� �湮���� ���� �� 
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
			f(i,node); // i��° �� ���� �� �� �ִ� ��� �� �湮 -> ���� ��� 1�� 
			result++; // ���� ��� ���� ���� 
		}
	}
	
	cout << result;
	
	return 0;
}

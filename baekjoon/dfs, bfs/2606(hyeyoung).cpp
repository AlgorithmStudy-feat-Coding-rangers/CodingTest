#include <iostream>
using namespace std;

bool list[100][100];
bool visited[100];

void f(int started, int node){
	visited[started] = true;
	for(int i=0;i<node;i++){
		if(list[started][i] && !visited[i]){
			f(i,node);
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
	
	
	f(0,node);
	
	int result = 0;
	for(int i=1;i<node;i++){
		if(visited[i]){
			result++;
		}
	}
	cout << result;
	return 0;
	
}

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int map[100][100];
int visited[100][100];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} }; // ��,��,��,��  
int maxX = 0;
int maxY = 0;

bool isValid(int x,int y){
	if( visited[x][y]==0 && 0<=x && x<maxX && 0<=y && y<maxY && map[x][y]==1){ 
		return true;
	}else{
		return false;
	} 
}

int bfs(int x, int y){
	
	int distance = 1; // ���� ��ġ ���� 
	queue< pair<int,int> > q = queue< pair<int, int> >();
	
	q.push( pair<int,int>(x,y) );
	visited[x][y] = 1;
	
	while(!q.empty()){
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();
		
		if(currentX == maxX-1 && currentY == maxY-1){ // ������ ���� 
			break;
		}
		
		for(int i=0;i<4;i++){ // ��, ��, ��, �� 
			if(isValid(currentX+dir[i][0],currentY+dir[i][1])){
				q.push( pair<int,int>(currentX+dir[i][0],currentY+dir[i][1]) );
				visited[currentX+dir[i][0]][currentY+dir[i][1]] = visited[currentX][currentY]+1; // ������+1 
			}
		}
	}
	
	return visited[maxX-1][maxY-1];
	
} 

int main(){
	
	int x,y;
	cin >> maxX >> maxY ;

	for(int i=0;i<maxX;i++){
		string temp = "";
		cin >> temp;
		for(int j=0;j<maxY;j++){
			map[i][j] = temp[j] - '0';
			visited[i][j] = 0;
		}
	} 	
	
	cout << bfs(0,0); 
	
	
	return 0;
} 

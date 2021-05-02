#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[100][100] = {0, };
bool visited[100][100] = {0, };

//»óÇÏÁÂ¿ì
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int start_x, int start_y){
    queue<pair<int, int>> q;
    q.push(pair<int, int>(start_x, start_y));
    visited[start_x][start_y] = true;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        //»óÇÏÁÂ¿ìÀÇ °æ·Î Å½»ö
        for(int i=0; i<4; i++){
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            if(map[nx][ny]==1 && !visited[nx][ny] && 0<=nx && nx<N
                && 0<=ny && ny<M){
                map[nx][ny] = map[x][y] + 1;
                visited[nx][ny] = true;
                q.push(pair<int, int>(nx, ny));
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            scanf("%1d", &map[i][j]);
    }
    
    bfs(0, 0);
    
    cout << map[N-1][M-1];
    
    return 0;
}

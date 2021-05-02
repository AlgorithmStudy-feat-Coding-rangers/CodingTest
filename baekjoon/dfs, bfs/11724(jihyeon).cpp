#include <iostream>
using namespace std;

int N, M;
bool map[1000][1000] = {0, };
bool visited[1000] = {0, };

void dfs(int u){
    visited[u] = 1;
    
    for(int v=0; v<N; v++){
        if(map[u][v]==1 && !visited[v])
            dfs(v);
    }
}

int main()
{
    cin >> N >> M;
    
    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        map[x-1][y-1] = 1;
        map[y-1][x-1] = 1;
    }
    
    int result = 0;
    
    for(int i=0; i<N; i++){
        if(!visited[i]){
            result++;
            dfs(i);
        }
    }

    cout << result;
    
    return 0;
}

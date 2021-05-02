#include <iostream>
using namespace std;

bool map[99][99] = {0, };
bool visited[99] = {0, };

int result = 0;

void dfs(int c, int N){
    visited[c] = 1;
    result++;
    
    for(int i=0; i<N; i++){
        if(map[c][i]==1 && !visited[i])
            dfs(i, N);
    }
}

int main()
{
    int N;
    int network_N;
    
    cin >> N;
    cin >> network_N;
    
    for(int i=0; i<network_N; i++){
        int x, y;
        cin >> x >> y;
        map[x-1][y-1] = 1;
        map[y-1][x-1] = 1;
    }
    
    dfs(0, N);

    //출발점인 1은 뺀다
    cout << result-1 << "\n";
    
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int map[500][500] = {0, };
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> map[i][j];
        }
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j==0)
                map[i][j] += map[i-1][j];
            else if(j == i)
                map[i][j] += map[i-1][j-1];
            else
                map[i][j] += max(map[i-1][j], map[i-1][j-1]);
        }
    }
    
    int max = 0;
    
    for(int i=0; i<n; i++){
        if(map[n-1][i] > max)
            max = map[n-1][i];
    }
    
    cout << max << "\n";
    
    return 0;
}

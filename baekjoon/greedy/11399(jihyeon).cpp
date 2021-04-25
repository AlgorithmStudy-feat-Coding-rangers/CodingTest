#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++)
        cin >> v[i];
        
    sort(v.begin(), v.end());
    
    int result = 0;
    int before = 0;
    for(int i=0; i<N; i++){
        before = before + v[i];
        result += before;
    }
        
    cout << result << "\n";
    
    return 0;
}
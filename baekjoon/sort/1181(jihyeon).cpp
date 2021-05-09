#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    if(a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

int main()
{
    int N;
    cin >> N;

    vector<string> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end(), cmp);
    
    cout << v[0] << "\n";

    for (int i = 1; i < N; i++){
        if(v[i-1] == v[i])
            continue;
        else
            cout << v[i] << "\n";
    }
}

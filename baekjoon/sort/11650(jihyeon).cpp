#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>a, pair<int, int> b){
    if(a.first < b.first)
        return true;
    else if(a.first == b.first){
        return a.second < b.second;
    }
    return false;
}

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> vec(N);

    for (int i = 0; i < N; i++)
        cin >> vec[i].first >> vec[i].second;
    
    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < N; i++)
        cout << vec[i].first << " " << vec[i].second << "\n";
}
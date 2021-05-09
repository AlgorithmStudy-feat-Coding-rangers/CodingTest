#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

int sum(string s){
    int sum = 0;
    for(int i=0; i<s.length(); i++){
        if('0' <= s[i] && s[i]<= '9')
            sum += s[i] - '0';
    }
    return sum;
}

bool cmp(string a, string b){
    if(a.length() == b.length()){
        int sum_a = sum(a);
        int sum_b = sum(b);
        
        if(sum_a != sum_b) //2번 조건
            return sum_a < sum_b;
        else //3번 조건
            return a<b;
    }
    
    //1번 조건
    return a.length() < b.length();
}

int main(){
   int N;
    cin >> N;

    vector<string> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end(), cmp);
    
    for (int i = 0; i < N; i++)
            cout << v[i] << "\n";
}
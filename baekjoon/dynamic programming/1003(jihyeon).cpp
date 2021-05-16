#include <iostream>
using namespace std;

int zero_count[41] = {0, };
int one_count[41] = {0, };
    
void fibonacci(int N){
    for(int i=2; i<=N; i++){
        zero_count[i] = zero_count[i-1] + zero_count[i-2];
        one_count[i] = one_count[i-1] + one_count[i-2];
    }
}

int main()
{
    int T;
    cin >> T;
    
    zero_count[0] = 1, zero_count[1] = 0;
    one_count[0] = 0, one_count[1] = 1;
    
    for(int i=0; i<T; i++){
        int N;
        cin >> N;
        fibonacci(N);
        cout << zero_count[N] << " " << one_count[N] << "\n";
    }

    return 0;
}

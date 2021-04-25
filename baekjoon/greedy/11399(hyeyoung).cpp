#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	int list[n];
	for(int i=0;i<n;i++){
		cin >> list[i];
	}
	sort(list,list+n);

	int result = 0;
	for(int i=0;i<n;i++){
		result += list[i]*(n-i);
	}
	cout << result;
	return 0;
}

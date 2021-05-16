#include <iostream>
using namespace std;

int list[41][2]; //0,1

int main(){
	int tC;
	cin >> tC;
	
	list[0][0]=1; list[0][1]=0; //f(0)
	list[1][0]=0; list[1][1]=1; //f(1)
	for(int i=2;i<41;i++){
		list[i][0] = list[i-1][0] + list[i-2][0];
		list[i][1] = list[i-1][1] + list[i-2][1];
	}
	
	int n;
	for(int i=0;i<tC;i++){
		cin >> n;
		cout << list[n][0] << " " << list[n][1] << "\n";
	}
	
	return 0;
}

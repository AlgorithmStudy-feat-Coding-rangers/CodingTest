#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> x, pair<int,int> y){
	if(x.first == y.first)
		return x.second<y.second;
	else
		return x.first<y.first;
}

int partition(vector<pair<int,int> >& v, int left, int right){
    int pivotValue = left;
    int storeIndex = pivotValue;
 
    for (int i = left + 1; i <= right; i++){
        if (compare(v[i],v[pivotValue])){ //[pivotValue]가 [i]보다 크면 
            storeIndex++;
            
            pair<int,int> temp = v[i];
		    v[i] = v[storeIndex];
		    v[storeIndex] = temp;
        }
    }
    
    pair<int,int> temp = v[pivotValue];
	v[pivotValue] = v[storeIndex];
	v[storeIndex] = temp;
    pivotValue = storeIndex;
 
    return pivotValue;
}
 
void quickSort(vector<pair<int,int> >& v, int left, int right){
    if (left < right){
        int pivot = partition(v, left, right);
        quickSort(v, left, pivot - 1);
        quickSort(v, pivot + 1, right);
    }
}

int main(){
	
	int n;
	cin >> n;
	
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++){
		cin >> v[i].first >> v[i].second;
	}
	
	quickSort(v, 0,n-1);

	for(int i=0;i<v.size();i++){
		cout << v[i].first << " " << v[i].second << "\n";
	}
	
	return 0;
}

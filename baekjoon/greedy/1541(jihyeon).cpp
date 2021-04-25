#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool isSub = false;
    int result = 0;
    for(int i=0; i<s.length(); i++){
        string tmp = "";
        
        while('0' <= s[i] && s[i] <= '9'){
            tmp += s[i];
            i++;
        }
        
        int num = stoi(tmp);
        
        if(!isSub){
            if(s[i] == '-')
                isSub = true;
            result += num;
        }
        else
            result -= num;
    }
    
    cout << result << "\n";
    
    return 0;
}
class Solution {
public:
    string letter[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> result;
    
    void dfs(int digit, int index, string digits, string s){
        if(s.length() == digits.length()){
            result.push_back(s);
            return;
        }
        
        for(int i=0; i<letter[digit].length(); i++)
            dfs(digits[index+1]-'0', index+1, digits, s+letter[digit][i]);
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits != "")
            dfs(digits[0]-'0', 0, digits, "");
        
        return result;
    }
};
​
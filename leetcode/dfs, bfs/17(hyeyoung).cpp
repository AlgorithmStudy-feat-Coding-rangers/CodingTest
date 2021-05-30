class Solution {
public:
    string value[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> v = vector<string>();
    
    void put(string s, int sIndex, int contentIndex, string digits){
        // 총 (digits.length)자리의 s의 sIndex를 수정할 것임
        // 넣을 내용은 value[contentIndex]
        if(digits.length() == sIndex){
            v.push_back(s);
            return;
        }
        
        string content = value[contentIndex];
        for(int i=0;i<content.length();i++){
            put(s+content[i],sIndex+1,digits[sIndex+1]-'0',digits);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits!=""){

            put("",0,digits[0]-'0',digits);
        }
        
        return v;
    }
};

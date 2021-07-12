class Solution {
    HashMap<Integer,String> phoneNum = new HashMap<Integer,String>(){{//초기값 지정
        put(2,"abc");
        put(3,"def");
        put(4,"ghi");
        put(5, "jkl");
        put(6, "mno");
        put(7, "pqrs");
        put(8, "tuv");
        put(9, "wxyz");
    }};
    
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<String>();
        
        if(digits.length() != 0){
            calculation(result, digits, 0, "");
        }
        return result;
    }
    
    private void calculation(List<String> result, String digits, int i, String resultString){
        if(i == digits.length()){
            result.add(resultString);
            return;
        }
        
        String valueChars = phoneNum.get(digits.charAt(i) - '0');
        for(char c : valueChars.toCharArray()){
            calculation(result, digits, i + 1, resultString + c);
        }
    }
}

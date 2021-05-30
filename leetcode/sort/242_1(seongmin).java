class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length())
            return false;
        
        List<String> list = new ArrayList(); 
        
        String [] sArray = s.split("");
        for(String tmp : sArray){
            list.add(tmp);
        }
        
        String [] tArray = t.split("");
        for(String tmp : tArray){
            if(!list.contains(tmp))
                return false;
            else{
                list.remove(tmp);
            }
        }
        return true;
    }
}
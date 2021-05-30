class Solution {
    public boolean isAnagram(String s, String t) {
        char[] sArray = s.toCharArray();
        Arrays.sort(sArray);
        String sortedS = new String(sArray);
        char[] tArray = t.toCharArray();
        Arrays.sort(tArray);
        String sortedT = new String(tArray);
        
        return sortedS.equals(sortedT);
    }
}
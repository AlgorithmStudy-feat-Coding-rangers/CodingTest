class Solution {
    public int countGoodRectangles(int[][] rectangles) {
     List<Integer> minValues = new ArrayList<Integer>();
        for(int i = 0; i< rectangles.length; i++){
            if(rectangles[i][0] < rectangles[i][1]){
                minValues.add(rectangles[i][0]);
            }
            else{
                minValues.add(rectangles[i][1]);     
            }
        }
        
        int max = minValues.get(0);
        for(int i = 1; i< minValues.size(); i++){
            if(max < minValues.get(i)){
                max = minValues.get(i);
            }
        }
        
        int count = 0;
        for(int i = 0; i< minValues.size(); i++){
            if(max == minValues.get(i)){
                count++;
            }
        }
        
        return count;
    }
}
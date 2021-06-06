class Solution {
    public int countGoodRectangles(int[][] rectangles) {
        int size = rectangles.length;
        int[] minValues = new int[size];
        for(int i = 0; i< rectangles.length; i++){
            if(rectangles[i][0] < rectangles[i][1]){
                minValues[i] = rectangles[i][0];
            }
            else{
                minValues[i] = rectangles[i][1];     
            }
        }
        
        int max = minValues[0];
        for(int i = 1; i< minValues.length; i++){
            if(max < minValues[i]){
                max = minValues[i];
            }
        }
        
        int count = 0;
        for(int i = 0; i< minValues.length; i++){
            if(max == minValues[i]){
                count++;
            }
        }
        
        return count;
    }
}
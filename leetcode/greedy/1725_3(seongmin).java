class Solution {
    public int countGoodRectangles(int[][] rectangles) {
        int size = rectangles.length;
        int max = 0;
        int count = 0;
        for(int i = 0; i< rectangles.length; i++){
            int length = Math.min(rectangles[i][0], rectangles[i][1]);
            if(max < length){
                max = length;
                count = 1;
            }else if(max == length){
                count++;
            }
        }
        return count;
    }
}
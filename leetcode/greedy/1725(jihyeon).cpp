class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max = 0;
        vector<int> num;
        int count = 0;
        for(int i=0; i<rectangles.size(); i++){
            int cur = min(rectangles[i][0], rectangles[i][1]);
            num.push_back(cur);
            
            if(cur > max){
                max = cur;
                count = 0;
            }
            
            if(cur == max)
                count++;
        }
        
        return count;
    }
};
class Solution {
public:
    int maxArea(vector<int>& heights) { 

        int maxWater = 0;
        int st = 0, end = heights.size() - 1;

        while(st < end){

            int w = end - st;
            int h = min(heights[st], heights[end]);
            int waterArea = w * h;
            maxWater = max(maxWater, waterArea);

            heights[st] < heights[end] ? st++ : end--;
        }
        
        return maxWater;
        
    }
};

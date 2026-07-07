class Solution {
public:
    int maxArea(vector<int>& heights) { 

        int maxWater = 0;
        
        for(int i = 0; i < heights.size(); i++){
            for(int j = i + 1; j < heights.size(); j++){
                int w = j - i;
                int h = min(heights[i], heights[j]);
                int waterArea = w * h;
                maxWater = max(maxWater, waterArea);
            }
        }

        return maxWater;
        
    }
};

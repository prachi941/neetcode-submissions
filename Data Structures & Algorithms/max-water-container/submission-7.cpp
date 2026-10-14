class Solution {
public:
    int maxArea(vector<int>& heights) {

        int i = 0;
        int j = heights.size() - 1;

        int maxWater = 0;
        int waterArea = 0;

        while(i < j) {

           waterArea = (j - i) * min(heights[i], heights[j]);

            if(heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }

            maxWater = max(maxWater, waterArea);
        }

        return maxWater;
    }
};

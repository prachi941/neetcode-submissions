class Solution {
public:
    int maxArea(vector<int>& heights) {

        //have to take out area
        //so calculation of height and width
        //have to choose the smaller height amoung the chosen bars 
        //have to maximize width for maxArea
        // for area h and w 

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

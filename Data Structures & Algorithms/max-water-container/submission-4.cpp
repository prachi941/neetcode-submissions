class Solution {
public:
    int maxArea(vector<int>& heights) {

        int st = 0;
        int end = heights.size() - 1;

        int most_area = 0;

        while(st < end) {

            int width = end - st;
            int height = min(heights[st], heights[end]);

            int area = width * height;

            most_area = max(most_area, area);

            
            if(heights[st] < heights[end]) {
                st++;
            } else {
                end--;
            }
        }

        return most_area;
    }
};

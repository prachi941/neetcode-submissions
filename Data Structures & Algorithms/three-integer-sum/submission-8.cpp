class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());// 2 pointer approach will only work when array is sorted

        for(int i = 0; i < nums.size() - 2; i++) {// fix one number; find other two (nums[i] = -(nums[j] + nums[k])) 

            if(i > 0 && nums[i] == nums[i - 1]) { //move past duplicates
                continue;
            }

            //our pointers
            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j - 1]) {//move past duplicates
                        j++;
                    }

                    while(j < k && nums[k] == nums[k + 1]) {//move past duplicates
                        k--;
                    }
                }

                else if (sum < 0) {
                    j++;
                }

                else{
                    k--;
                }
            }
        }

        return ans;
        
    }
};

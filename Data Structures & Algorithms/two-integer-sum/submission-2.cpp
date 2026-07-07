class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        
        int first, second /* (complement) */; 

        for(int i = 0; i < nums.size(); i++){
            first = nums[i];
            second = target - first;

            if(m.find(second) != m.end()){
            
             return {m[second],i}; 
                
            }

            m[nums[i]] = i; // inserting both key and index
            //m[nums[0]] = 0;
            //m[3] = 0; 
            //{3 : 0} this way map stores key +  its index
            
        }

    }
};

//here first 3 ; comple 4 does not exist yet in map; then 4; comple 3 exists; so as 3 is our comple or sec_no and it has smaller index ie 0 gives its index first so m[sec],i

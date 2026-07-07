class Solution {
public:

    bool ls(vector<int>& a, int n, int num) {

            for(int i = 0; i < n; i++){

                if(a[i] == num){
                    return true;
                }
            }
            return false;
        }

    int longestConsecutive(vector<int>& a) { 
        
        int n = a.size();

        if(n == 0){
            return 0;
        }

        int longest = 1;
            
            for (int i = 0; i < n; i++){
            int x = a[i];
            int count = 1;

            while(ls(a, n, x + 1)){
                x = x + 1;
                count = count + 1;

            }
            longest = max(longest, count);
        }

        return longest;
      
    }
};

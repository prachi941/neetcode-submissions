class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        

        int rows = mat.size();
        int cols = mat[0].size();

        int st = 0;
        int end = rows - 1;

        int row = -1;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            if(tar >= mat[mid][0] && tar <= mat[mid][cols - 1]) {
                row = mid;
                break;
            } 
            
            else if(tar < mat[mid][0]) {
                end = mid - 1;
            }

            else {
                st = mid + 1;
            }
        }


        if(row == -1) {
            return false;
        }


        st = 0;
        end = cols - 1;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            if(mat[row][mid] == tar) 
            return true;

            else if(mat[row][mid] < tar) 
            st = mid + 1;

            else
            end = mid - 1;
        }

        return false;
    }
};

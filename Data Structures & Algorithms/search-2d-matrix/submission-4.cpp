//first for finding row bin Search on rows
//then bin search on the desired row for finding col

class Solution {
public:
    bool searchCol(vector<vector<int>>& mat, int tar, int mid) {

        int stRow = 0;

        int n = mat[0].size();
        int endRow = n - 1;

        while(stRow <= endRow) {

            int midCol = stRow + (endRow - stRow) / 2;

            if(tar == mat[mid][midCol]) {
                return true;
            } else if (tar > mat[mid][midCol]) {
                stRow = midCol + 1;
            } else {
                endRow = midCol - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat, int tar) {
    
        int m = mat.size();
        int n = mat[0].size();

        int st = 0;
        int end = m - 1;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            if( tar >= mat[mid][0] && tar <= mat[mid][n - 1]) {         return searchCol(mat, tar, mid);
            } else if(tar > mat[mid][n - 1]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }

        }

         return false;
    }
};

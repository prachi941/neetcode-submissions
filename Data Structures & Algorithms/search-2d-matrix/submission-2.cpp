class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        
        // by imagining 2D as flattened array of size(m * n)
        // in flattened arr, we will have a single idx [] but we need to find a 2D idx [][] in real

        // so we use:
        // row = mid / cols;  mid is basically the imagined 1D arr idx
        // col = mid % cols;

        int m = mat.size(); // rows
        int n = mat[0].size(); // cols

        int st = 0;
        int end = m * n - 1;

        while(st <= end) {

            int mid = st +(end - st) / 2;

            // Convert 1D index to 2D index
            int row = mid / n;
            int col = mid % n;

            if(mat[row][col] == tar) {
                return true;
            }

            else if (tar < mat[row][col]) {
                end = mid - 1;
            }

            else {
                st = mid + 1;
            }
        }

        return false;
    }
};

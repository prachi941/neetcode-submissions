class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int tar) {

        int m = matrix.size(), n = matrix[0].size();

        int startRow = 0, endRow = m - 1;

        while(startRow <= endRow){

            int midRow = (startRow + endRow) / 2;

            if(matrix[midRow][0] <= tar  && tar <= matrix[midRow][n - 1]){

                int st = 0, end = n - 1;

                while(st <= end){
                    
                int mid = (st + end) / 2;

                if(matrix[midRow][mid] == tar){
                    return true;
                }

                else if(matrix[midRow][mid] < tar){
                    st = mid + 1;
                }
                 else{
                    end = mid - 1;
                }

            }

            return false;

        }

            else if (matrix[midRow][0] < tar) {
                startRow = midRow + 1;

            } else {
                endRow = midRow - 1;
            }

        }

        return false;
        
    }
};

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int m= mat.size();
        int n= mat[0].size();
        
        int row=0;
        int col= n-1;
        
        while(row<m && col>=0){
            if(mat[row][col]== x){
                return true;
            }
            else if(mat[row][col]< x)
                row++;
            else
                col--;
        }
        return false;
    }
};
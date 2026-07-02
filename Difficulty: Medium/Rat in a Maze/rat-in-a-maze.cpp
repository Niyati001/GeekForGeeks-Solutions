class Solution {
  public:
    void solve(int row, int col, vector<vector<int>>& maze, int n, vector<vector<int>>& vis, string path, vector<string>& ans){
        if(row== n-1 && col== n-1){
            ans.push_back(path);
            return;
        }
        vis[row][col]= 1;
        
        // DOWN
        if(row+1< n && maze[row+1][col]==1 && !vis[row+1][col])
            solve(row+1, col, maze, n, vis, path+ 'D', ans);
            
        // left
        if(col>=0 && maze[row][col-1]==1 && !vis[row][col-1])
            solve(row, col-1, maze, n, vis, path+ 'L', ans);
            
        // RIGHT
        if(col+1< n && maze[row][col+1]==1 && !vis[row][col+1])
            solve(row, col+1, maze, n, vis, path+ 'R', ans);
        
        // up
        if(row-1>=0 && maze[row-1][col]== 1 && !vis[row-1][col])
            solve(row-1, col, maze, n, vis, path+'U', ans);
            
        vis[row][col]=0;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n= maze.size();
        
        vector<string> ans;
        
        if(maze[0][0]== 0) return ans;
        
        vector<vector<int>>vis(n, vector<int>(n, 0));
        
        solve(0,0, maze, n, vis, "", ans);
        return ans;
    }
};
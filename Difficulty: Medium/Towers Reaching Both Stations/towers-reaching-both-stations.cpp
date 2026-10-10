class Solution {
  public:
    int n, m;
    vector<vector<int>> p, q;
    
    int dx[4]= {-1, 1, 0, 0};
    int dy[4]= {0, 0, -1, 1};
    
    void dfs(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& visited)
    {
        visited[i][j]=1;
        
        for(int k=0; k<4; k++){
            int x= i+ dx[k];
            int y= j+ dy[k];
            
            if(x<0 || x>=n || y<0 || y>=m) continue;
            
            if(visited[x][y]) continue;
            
            if(mat[x][y]>= mat[i][j])
                dfs(x, y, mat, visited);
        }
    }
    
    int countCoordinates(vector<vector<int>>& mat) {
        n= mat.size();
        m= mat[0].size();
        
        p.assign(n, vector<int>(m, 0));
        q.assign(n, vector<int>(m, 0));
        
        for(int j=0; j<m; j++){
            if(!p[0][j])
                dfs(0, j, mat, p);
        }
        
        for(int i=0; i<n; i++){
            if(!p[i][0])
                dfs(i, 0, mat, p);
        }
        
        for(int j=0; j<m; j++){
            if(!q[n-1][j])
                dfs(n-1, j, mat, q);
        }
        
        for(int i=0; i<n; i++){
            if(!q[i][m-1])
                dfs(i, m-1, mat, q);
        }
        
        int ans=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(p[i][j] && q[i][j])
                    ans++;
            }
        }
        return ans;
    }
};
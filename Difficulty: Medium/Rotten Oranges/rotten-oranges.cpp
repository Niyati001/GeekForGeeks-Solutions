class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n= mat.size();
        int m= mat[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int fresh=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1)
                    fresh++;
                    
                else if(mat[i][j]== 2){
                    q.push({{i, j}, 0});
                    vis[i][j]= 1;
                }
            }
        }
        
        int time=0;
        
        int dr[]= {-1, 0, 1, 0};
        int dc[]= {0, 1, 0, -1};
        
        while(!q.empty()){
            auto node= q.front();
            q.pop();
            
            int r= node.first.first;
            int c= node.first.second;
            int t= node.second;
            
            time= max(time, t);
            
            for(int i=0; i<4; i++){
                int nr= r+ dr[i];
                int nc= c+ dc[i];
                
                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && mat[nr][nc]== 1){
                    vis[nr][nc]=1;
                    fresh--;
                    q.push({{nr, nc}, t+1});
                }
            }
        }
        if(fresh>0) return -1;
        return time;
    }
};
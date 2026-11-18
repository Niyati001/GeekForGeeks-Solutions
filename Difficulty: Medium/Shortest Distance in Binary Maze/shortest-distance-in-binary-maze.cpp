class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        int n= mat.size();
        int m= mat[0].size();
        
        if(mat[src[0]][src[1]]==0 || mat[dest[0]][dest[1]]==0)
            return -1;
            
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int dr[]= {-1, 0, 1, 0};
        int dc[]= {0, 1, 0, -1};
        
        queue<pair<pair<int, int>, int>> q;
        
        vis[src[0]][src[1]]=1;
        
        q.push({{src[0], src[1]}, 0});
        
        while(!q.empty()){
            auto front= q.front();
            q.pop();
            
            int r= front.first.first;
            int c= front.first.second;
            int dist= front.second;
            
            if(r== dest[0] && c== dest[1])
                return dist;
                
            for(int i=0; i<4; i++){
                int nr= r+ dr[i];
                int nc= c+ dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({{nr, nc}, dist+1});
                }
            }
        }
        return -1;
    }
    
};

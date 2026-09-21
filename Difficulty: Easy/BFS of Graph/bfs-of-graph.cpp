class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int V= adj.size();
        int vis[V]= {0};
        queue<int> q;
        vector<int> bfs;
        
        vis[0]=1;
        q.push(0);
        
        while(!q.empty()){
            int front= q.front();
            q.pop();
            bfs.push_back(front);
            
            for(int neigh: adj[front]){
                if(!vis[neigh]){
                    q.push(neigh);
                    vis[neigh]= 1;
                }
            }
        }
        return bfs;
    }
};
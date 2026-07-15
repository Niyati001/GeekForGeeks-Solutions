class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // create adjacency list
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        //weight, node, parent
        pq.push({0,0, -1});
        vector<int> vis(V, 0);
        int sum=0;
        
        while(!pq.empty()){
            auto[wt, node, parent]= pq.top();
            pq.pop();
            
            if(vis[node]) continue;
            
            vis[node]=1;
            sum+= wt;
            
            
            //parent node is MST edge
            if(parent!= -1){
                
            }
            
            for(auto it: adj[node]){
                int adjNode= it.first;
                int edgeWt= it.second;
                
                if(!vis[adjNode]){
                    pq.push({edgeWt, adjNode, node});
                }
                
            }
        }
        return sum;
    }
};
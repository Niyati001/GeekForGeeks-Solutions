class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> inDegree(V, 0);
        
        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        queue<int> q;
        
        for(int i=0; i<V; i++){
            if(inDegree[i]== 0){
                q.push(i);
            }
        }
        vector<int> ans;
        
        while(!q.empty()){
            int node= q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto neig: adj[node]){
                inDegree[neig]--;
                if(inDegree[neig]== 0){
                    q.push(neig);
                }
            }
        }
        return ans;
    }
};
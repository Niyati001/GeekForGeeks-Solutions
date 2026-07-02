class Solution {
  public:
    bool isSafe(int node, int clr, vector<vector<int>>&graph, vector<int>& color){
        for(int neighbour: graph[node]){
            if(color[neighbour]== clr)
                return false;
        }
        return true;
    }
    
    bool solve(int node, int v, int m, vector<vector<int>>& graph, vector<int>& color){
        if(node== v) return true;
        
        for(int clr=1;clr<= m; clr++){
            if(isSafe(node, clr, graph, color)){
                color[node]= clr;
                if(solve(node+1, v, m, graph, color)) 
                    return true;
                color[node]= 0;
            }
        }
        return false;
    }
    
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> graph(v);
        
        for(auto &e: edges){
            int u= e[0];
            int v= e[1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> color(v, 0);
        return solve(0, v, m, graph, color);
    }
};
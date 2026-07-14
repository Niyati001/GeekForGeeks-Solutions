class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        vector<int> dist(1000, 1e9);
        queue<pair<int, int>> q;
        
        if(start== end) return 0;
        dist[start]=0;
        q.push({start, 0});
        
        while(!q.empty()){
            int node= q.front().first;
            int steps= q.front().second;
            
            q.pop();
            
            for(auto x: arr){
                int newNode= (node*x)% 1000;
                if(steps+ 1< dist[newNode]){
                    dist[newNode]= steps+1;
                    
                    if(newNode== end){
                        return steps+1;
                    }
                    
                    q.push({newNode, steps+1});
                }
            }
        }
        return -1;
    }
};
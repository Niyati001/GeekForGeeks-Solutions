class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        vector<vector<int>> ans;
        
        int start= newInterval[0];
        int end= newInterval[1];
        int i=0;
        int n= intervals.size();
        
        while(i<n && intervals[i][1]< start){
            ans.push_back(intervals[i]);
            i++;
        }
        
        while(i<n && intervals[i][0]<= end){
            start= min(intervals[i][0], start);
            end= max(intervals[i][1], end);
            
            i++;
        }
        ans.push_back({start, end});
        
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
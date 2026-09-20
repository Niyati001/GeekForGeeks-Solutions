class Solution {
  public:
    bool isIntersect(vector<vector<int>> intervals) {
        // Code Here
        sort(intervals.begin(), intervals.end());
        
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<= intervals[i-1][1]){
                return true;
            }
        }
        return false;
    }
};
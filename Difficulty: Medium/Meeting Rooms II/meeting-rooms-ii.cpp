class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i=0;
        int j=0;
        
        int rooms= 0;
        int maxRooms=0;
        
        while(i< start.size()){
            if(start[i]< end[j]){
                rooms++;
                maxRooms= max(maxRooms, rooms);
                i++;
            }
            else{
                rooms--;
                j++;
            }
        }
        return maxRooms;
    }
};

class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n= s1.size();
        int m= s2.size();
        
        int start=-1;
        int ansLen= INT_MAX;
        
        int i=0;
        
        while(i<n){
            int j=0;
            
            while(i<n && j<m){
                if(s1[i]== s2[j])
                    j++;
                i++;
            }
            if(j<m)
                break;
                
            int end= i-1;
            
            j= m-1;
            
            while(j>=0){
                if(s1[end]== s2[j])
                    j--;
                end--;
            }
            
            int left= end+1;
            
            if(i- left< ansLen){
                ansLen= i- left;
                start= left;
            }
            i= left+1;
        }
        return start== -1? "": s1.substr(start, ansLen);
    }
};

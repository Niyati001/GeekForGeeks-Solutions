class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        vector<int> need(128);
        
        for(char c: p)
            need[c]++;
            
        int required= p.size();
        
        int left=0;
        int count=0;
        
        int start=0;
        int len= INT_MAX;
        
        for(int right=0; right<s.size(); right++){
            if(need[s[right]]>0)
                count++;
                
            need[s[right]]--;
            
            while(count== required){
                if(right-left+1< len){
                    len= right-left+1;
                    start= left;
                }
                need[s[left]]++;
                
                if(need[s[left]]> 0)
                    count--;
                    
                left++;
            }
        }
        return len== INT_MAX? "": s.substr(start, len);
    }
};
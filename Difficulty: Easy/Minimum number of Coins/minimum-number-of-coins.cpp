class Solution {
  public:
    int findMin(int n) {
        int cnt= 0;
        
        cnt+= n/10;
        n%= 10;
        
        cnt+= n/5;
        n%= 5;
        
        cnt+= n/2;
        n%= 2;
        
        cnt+= n/1;
        n%=1;
        
        return cnt;
    }
};
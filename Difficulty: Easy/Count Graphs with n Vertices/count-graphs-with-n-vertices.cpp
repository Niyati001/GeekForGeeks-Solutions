class Solution {
  public:
    long long count(int n) {
        int edges= n*(n-1)/2;
        return (1LL<< edges);
    }
};
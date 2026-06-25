class Solution {
  public:
    int pageFaults(vector<int>& pages, int c) {
        list<int> memory;
        unordered_map<int, list<int>::iterator> mp;
        
        int faults=0;
        
        for(int page: pages){
            //page already exits
            if(mp.find(page)!= mp.end()){
                memory.erase(mp[page]);
                memory.push_back(page);
                mp[page]=-- memory.end();
            }
            //page fault
            else{
                faults++;
                if(memory.size()==c){
                    int lru= memory.front();
                    memory.pop_front();
                    mp.erase(lru);
                }
                memory.push_back(page);
                mp[page]= -- memory.end();
            }
        }
        return faults;
    }
};
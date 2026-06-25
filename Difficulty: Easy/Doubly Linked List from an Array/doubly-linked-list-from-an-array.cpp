/* class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
    Node* createDLL(vector<int>& arr) {
        if(arr.size()== 0) return NULL;
        
        Node* head= new Node(arr[0]);
        Node* prev= head;
        
        for(int i=1; i< arr.size(); i++){
            Node* newNode = new Node(arr[i]);
            prev-> next= newNode;
            newNode-> prev= prev;
            prev= newNode;
        }
        return head;
    }
};
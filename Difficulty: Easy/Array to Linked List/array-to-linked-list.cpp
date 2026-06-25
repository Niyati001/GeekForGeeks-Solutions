/*
// Representation of a node
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* arrayToList(vector<int>& arr) {
        if(arr.size()== 0) return NULL;
        
        Node* head= new Node(arr[0]);
        Node* tail= head;
        
        for(int i=1; i< arr.size(); i++){
            Node* temp= new Node(arr[i]);
            tail-> next= temp;
            tail= temp;
        }
        return head;
    }
};
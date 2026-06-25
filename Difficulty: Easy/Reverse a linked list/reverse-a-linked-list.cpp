/*
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        if(head== NULL || head-> next== NULL) return head;
        
        Node* newHead= reverseList(head-> next);
        
        head-> next-> next= head;
        head-> next= NULL;
        return newHead;
    }
};
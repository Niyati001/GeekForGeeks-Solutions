/* Structure of doubly linked list node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        if(head== NULL || head-> next==NULL) return head;
    
        Node* curr= head;
        Node* temp= NULL;
        
        while(curr!=NULL){
            temp= curr-> next;
            curr-> next= curr-> prev;
            curr-> prev= temp;
            
            head= curr;
            curr= temp;
        }
        return head;
    }
};
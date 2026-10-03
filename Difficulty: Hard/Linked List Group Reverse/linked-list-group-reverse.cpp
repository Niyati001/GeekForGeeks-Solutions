/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* prev= NULL;
        Node* curr= head;
        Node* nextNode= NULL;
        int count=0;
        
        while(curr!= NULL && count<k){
            nextNode= curr-> next;
            curr-> next= prev;
            prev= curr;
            curr= nextNode;
            count++;
        }
        if(nextNode!= NULL){
            head-> next= reverseKGroup(nextNode, k);
        }
        return prev;
    }
};
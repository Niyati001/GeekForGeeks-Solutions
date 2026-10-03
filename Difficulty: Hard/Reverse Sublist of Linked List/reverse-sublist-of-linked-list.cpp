/* Structure of a Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    Node* reverseBetween(int a, int b, Node* head) {
        // code here
        if(head== NULL || a==b) return head;
        
        Node dummy(0);
        dummy.next= head;
        
        Node* prev= &dummy;
        
        for(int i=1; i<a; i++){
            prev= prev-> next;
        }
        
        Node* curr= prev-> next;
        
        for(int i=0; i<b-a; i++){
            Node* nextNode= curr-> next;
            
            curr-> next= nextNode-> next;
            nextNode-> next= prev-> next;
            prev-> next= nextNode;
        }
        return dummy.next;
    }
};
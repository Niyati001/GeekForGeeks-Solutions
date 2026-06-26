/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        if(head== NULL || head-> next== NULL) return head;
        Node* zeroHead= new Node(0);
        Node* oneHead= new Node(0);
        Node* twoHead= new Node(0);
        
        Node* zero= zeroHead;
        Node* one= oneHead;
        Node* two= twoHead;
        
        Node* curr= head;
        while(curr){
            Node* next= curr-> next;
            if(curr-> data== 0) {
                zero-> next= curr;
                zero= zero-> next;
            }
            
            else if(curr-> data== 1){
                one-> next= curr;
                one= one-> next;
            }
            else{
                two-> next= curr;
                two= two-> next;
            }
            curr= curr-> next;
        }
        // connect the lists
        zero-> next= (oneHead-> next) ? oneHead-> next : twoHead-> next;
        one-> next= twoHead-> next;
        two-> next= NULL;
        
        head= zeroHead-> next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
        
    }
};
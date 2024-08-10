/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    
    Node* rotate(Node* head, int k) {
        //CodeGenius
        if(!head) return NULL;
        
        Node *temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        while(--k)
        head=head->next;
        
        Node *newHead=head->next;
        head->next=NULL;
        
        return newHead;
        
        
    }
};
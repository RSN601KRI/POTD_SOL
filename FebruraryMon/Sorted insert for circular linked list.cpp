/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */
 
// This function should return head of
// the modified list
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       //Your code here
       Node *nn = new Node(data);
            if(head==NULL){
                nn->next = nn;
                return nn;
            }
            if(head->data >= data){
                nn->next = head;
                Node * temp = head;
                while(temp->next!=head) temp = temp->next;
                temp->next = nn;
                return nn;
            }
            Node* temp=head;
            while(temp -> next != head && temp -> next -> data < data)
            {
                temp = temp -> next;
            }
            nn ->next = temp -> next;
            temp -> next = nn;
            return head;
    }
};
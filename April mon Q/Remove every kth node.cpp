class Solution {
    public:
    Node* deleteK(Node *head,int K){
      if(K==1)return NULL;
      Node *temp=head,*prev=NULL;
      int c=1;
      while(temp){
          if(c==K){
              prev->next=temp->next;
              c=0;
          }
          else prev=temp;
          c++;
          temp=temp->next;
      }
      return head;
    }
};
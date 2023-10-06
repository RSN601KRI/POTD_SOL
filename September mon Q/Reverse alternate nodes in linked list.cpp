class Solution
{
    public:
    Node*reverse(Node*head) {
        if(!head or !head->next) {
            return head;
        }
        Node*smallHead = reverse(head->next);
        Node*temp = head;
        temp->next->next = head;
        temp->next = NULL;
        return smallHead;
    }
    void rearrange(struct Node *odd)
    {
        Node*first = odd;
        Node*second = odd->next;
        Node*temp = odd->next;
        while(first->next and second->next) {
            first->next = first->next->next;
            first = first->next;
            second->next = second->next->next;
            second = second->next;
        }
        
        // second = reverse(second);
        first->next = reverse(temp);
        
    }
};
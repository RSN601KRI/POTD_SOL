class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        if(head1 == NULL && head2 == NULL) return NULL;
        
        int M = (int)1e4 + 1;
        vector<int> freq(M, 0);
        Node* t = head1;
        while(t != NULL) {
            freq[t->data]++;
            t = t->next;
        }
        t = head2;
        while(t != NULL) {
            freq[t->data]++;
            t = t->next;
        }
        Node* dummy = new Node(-1);
        Node* res = dummy;
        for(int i = 1; i <= 10001; i++) {
            if(freq[i] > 0) {
                Node* temp = new Node(i);
                dummy->next = temp;
                dummy = dummy->next;
            }
        }
        dummy->next = NULL;
        return res->next;
    }
};
/*
Structure of the node of the linked list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code 
         int count = 0;
        unordered_set<int> us; 
        while (head1 != NULL) {
            us.insert(head1->data);
            head1 = head1->next;
        }
    
        
        while (head2 != NULL) {
            if (us.find(x - head2->data) != us.end())
                count++; 
            head2 = head2->next;
        }
        return count;
        
    }
};
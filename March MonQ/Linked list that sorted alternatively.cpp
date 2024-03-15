/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    // Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;
        
        Node* result = nullptr;
        
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        
        return result;
    }
    // Function to perform merge sort on linked list
    void mergeSort(Node** headRef) {
        Node* head = *headRef;
        Node* left;
        Node* right;
        
        // Base case: If the list is empty or has only one node, it is already sorted
        if (!head || !head->next) return;
        
        // Split the list into two halves
        splitList(head, &left, &right);
        
        // Recursively sort the sublists
        mergeSort(&left);
        mergeSort(&right);
        
        // Merge the sorted sublists
        *headRef = merge(left, right);
    }
    void splitList(Node* source, Node** frontRef, Node** backRef) {
        Node* slow = source;
        Node* fast = source->next;
        
        // Advance 'fast' two nodes, and advance 'slow' one node
        while (fast) {
            fast = fast->next;
            if (fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        // 'slow' is before the midpoint in the list, so split it in two at that point.
        *frontRef = source;
        *backRef = slow->next;
        slow->next = nullptr;
    }
    void sort(Node **head)
    {
          mergeSort(head);
    }
};
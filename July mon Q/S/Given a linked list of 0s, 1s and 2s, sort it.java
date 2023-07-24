//{ Driver Code Starts
    #include <bits/stdc++.h>

    using namespace std;
    /* Link list Node */
    struct Node {
        int data;
        struct Node *next;
        Node(int x) {
            data = x;
            next = NULL;
        }
    };
    
    struct Node *start = NULL;
    
    
    // } Driver Code Ends
    /*
     
      Node is defined as
      struct Node {
        int data;
        struct Node *next;
        Node(int x) {
            data = x;
            next = NULL;
        }
    };
    
    */
    class Solution
    {
        public:
        // Function to sort a linked list of 0s, 1s, and 2s.
        Node* segregate(Node* head) {
            if (head == nullptr || head->next == nullptr)
                return head;
    
            int count0 = 0, count1 = 0, count2 = 0;
            Node* current = head;
    
            // Count the occurrences of 0s, 1s, and 2s
            while (current != nullptr) {
                if (current->data == 0)
                    count0++;
                else if (current->data == 1)
                    count1++;
                else
                    count2++;
    
                current = current->next;
            }
    
            // Create a new linked list with sorted values
            current = head;
            while (current != nullptr) {
                if (count0 > 0) {
                    current->data = 0;
                    count0--;
                } else if (count1 > 0) {
                    current->data = 1;
                    count1--;
                } else {
                    current->data = 2;
                    count2--;
                }
    
                current = current->next;
            }
    
            return head;
        }
    };
    
            
    
    
    
    //{ Driver Code Starts.
    
    // Function to sort a linked list of 0s, 1s and 2s
    void printList(struct Node *Node) {
        while (Node != NULL) {
            printf("%d ", Node->data);
            Node = Node->next;
        }
        printf("\n");
    }
    
    /* Drier program to test above function*/
    void insert(int n1) {
        int n, value, i;
        // scanf("%d",&n);
        n = n1;
        struct Node *temp;
        for (i = 0; i < n; i++) {
            scanf("%d", &value);
    
            if (i == 0) {
                start = new Node(value);
                temp = start;
                continue;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
                temp->next = NULL;
            }
        }
    }
    
    int main() {
    
        int n;
    
        int t;
        scanf("%d", &t);
    
        while (t--) {
            scanf("%d", &n);
    
            insert(n);
            Solution ob;
            struct Node *newHead = ob.segregate(start);
            printList(newHead);
        }
    
        return 0;
    }
    // } Driver Code Ends
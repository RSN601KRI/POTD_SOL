/* Link list Node*/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Should return decimal equivalent modulo 1000000007 of binary linked list 
    long long unsigned int decimalValue(Node *head)
    {
        const int MOD = 1000000007;
        long long unsigned int result = 0;

        // Traverse the linked list
        while (head != nullptr) {
            // Left shift the result by 1 and add the current data
            result = (result << 1) % MOD + head->data;
            head = head->next;
        }

        return result;
    }
};

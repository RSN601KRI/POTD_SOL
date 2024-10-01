/* Linked list node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/

/* Multiply contents of two linked lists */
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long num1 = 0, num2 = 0;
        long long mod = 1000000007; // To handle overflow in large numbers

        // Traverse the first linked list and form the number
        while (first != NULL) {
            num1 = (num1 * 10 + first->data) % mod;
            first = first->next;
        }

        // Traverse the second linked list and form the number
        while (second != NULL) {
            num2 = (num2 * 10 + second->data) % mod;
            second = second->next;
        }

        // Multiply the two numbers and return the result modded by 1000000007
        return (num1 * num2) % mod;
    }
};
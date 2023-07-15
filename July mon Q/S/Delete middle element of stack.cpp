#include <stack>

class Solution
{
public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s, int sizeOfStack)
    {
        // Calculate the index of the middle element.
        int mid = sizeOfStack / 2;

        stack<int> tempStack;

        // Push elements from the original stack to the temporary stack
        // until the middle element is reached.
        for (int i = 0; i < mid; i++)
        {
            tempStack.push(s.top());
            s.pop();
        }

        // Skip popping the middle element.
        s.pop();

        // Push the remaining elements back to the original stack.
        while (!tempStack.empty())
        {
            s.push(tempStack.top());
            tempStack.pop();
        }
    }
};
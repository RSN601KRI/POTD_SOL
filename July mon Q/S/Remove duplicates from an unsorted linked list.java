class Solution
{
    // Function to remove duplicates from unsorted linked list.
    public Node removeDuplicates(Node head) 
    {
        if (head == null || head.next == null) {
            return head;
        }

        // Create a HashSet to store unique elements.
        HashSet<Integer> uniqueElements = new HashSet<>();

        Node current = head;
        Node previous = null;

        while (current != null)
        {
            if (uniqueElements.contains(current.data))
            {
                // Duplicate node found, skip it.
                previous.next = current.next;
            }
            else
            {
                // Add the current node data to the HashSet.
                uniqueElements.add(current.data);
                previous = current;
            }
            current = current.next;
        }
        return head;
    }
}
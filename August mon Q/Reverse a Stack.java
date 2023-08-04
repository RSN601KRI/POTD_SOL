class Solution
{ 
    static void reverse(Stack<Integer> s)
    {
        if (s.isEmpty()) {
            return;
        }

        int temp = s.pop();
        reverse(s);
        insertAtBottom(s, temp);
    }

    public static void insertAtBottom(Stack<Integer> s, int x) {
        if (s.isEmpty()) {
            s.push(x);
            return;
        }

        int temp = s.pop();
        insertAtBottom(s, x);
        s.push(temp);
    }

    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        st.push(3);
        st.push(2);
        st.push(1);
        st.push(7);
        st.push(6);

        reverse(st);

        while (!st.isEmpty()) {
            System.out.print(st.pop() + " ");
        }
    }
}
class Solution
{
    Node findparent(Map<Node, Node> map, Node root, int node){
        Queue<Node> q = new LinkedList<>();
        q.offer(root);
        Node target = null;
        while(!q.isEmpty()){
            Node newNode = q.poll();
            if(newNode.data == node){
                target = newNode;
            }
            if(newNode.left != null){
                map.put(newNode.left, newNode);
                q.offer(newNode.left);
            }
            if(newNode.right != null){
                map.put(newNode.right, newNode);
                q.offer(newNode.right);
            }
        }
        return target;
    }
    public int kthAncestor(Node root, int k, int node)
    {
        Map<Node, Node> p_map = new HashMap<>();
        
        Node target = findparent(p_map, root, node);
         System.out.print(p_map.size());
        Queue<Node> q = new LinkedList<>();
        q.offer(target);
        int level = 0;
        while(!q.isEmpty()){
            Node newNode = q.poll();
            if(level == k){
                return newNode.data;
            }
            level++;
            if(p_map.get(newNode) != null){
                q.offer(p_map.get(newNode));
            }
        }
        return -1;
    }
}
// C++ CODE

class NodeValue{
    public:
    int maxVal,minVal,maxSize;
    NodeValue(int minVal,int maxVal,int maxSize){
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxSize = maxSize;
    }
};

class Solution{
    public:
    NodeValue help(Node *root){
        if(!root)return NodeValue(INT_MAX,INT_MIN,0);
        NodeValue left = help(root->left);
        NodeValue right = help(root->right);
        if(left.maxVal<root->data and root->data<right.minVal){
            return NodeValue(min(root->data,left.minVal),max(root->data,right.maxVal),left.maxSize+right.maxSize+1);
        }
        return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	return help(root).maxSize;
    }
};




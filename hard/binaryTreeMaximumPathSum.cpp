class Solution {
public:
    int maxPathSum(TreeNode* root) {
        
        int maxSum = INT_MIN;
        int maxOnRoot = maxPathOnCurrentNode(root , maxSum);
        return maxSum;
        
        
    }
private:
    int maxPathOnCurrentNode(TreeNode* root , int& maxSum){
        if(root==nullptr){
            return 0;
            
        }
       
        int leftSum  = max(0,maxPathOnCurrentNode(root->left , maxSum));
        int rightSum = max(0,maxPathOnCurrentNode(root->right, maxSum));
        
        maxSum = max(maxSum, leftSum + rightSum + root->val);
        
        
        return root->val + max(leftSum , rightSum);
        
    }
};

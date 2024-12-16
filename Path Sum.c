bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }
   
    targetSum -= root->val;
   
    if (root->left == NULL && root->right == NULL) {
        return targetSum == 0;
    }
   
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

Input
root =
[5,4,8,11,null,13,4,7,2,null,null,null,1]
targetSum =
22
Output
true

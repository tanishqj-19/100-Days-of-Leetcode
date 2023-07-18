
class Solution {
    TreeNode* prevNode = nullptr;

    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);

        if(prevNode){
            minDiff = min(minDiff, root->val - prevNode->val);
        }
        prevNode = root;
        inorder(root->right);
    }
public:
    int minDiff = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};

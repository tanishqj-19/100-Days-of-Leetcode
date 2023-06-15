
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int ans = 0;
        int mx = INT_MIN;
        int temp = 0;

        while(!q.empty()){
            int n = q.size();
            temp  = 0;
            level++;
            for(int i=0; i<n; i++){
                
                TreeNode* node = q.front();
                temp += node->val;
                q.pop();

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            
            if(temp > mx){
                mx = temp;
                ans = level;
            }
            
            
        }

        return ans;
    }
};

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        queue<TreeNode*> q;

        q.push(root);
        long long  level = 0, temp = 0;

        while(!q.empty()){
            int n = q.size();
            level++;
            temp = 0;

            for(int i=0; i<n; i++){
                TreeNode* node = q.front(); 
                q.pop();
                temp += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ans.push_back(temp);
        }

        if(ans.size() < k)
            return -1;
        sort(ans.begin(), ans.end(), greater<long long>());
        return ans[k-1];
    }
};

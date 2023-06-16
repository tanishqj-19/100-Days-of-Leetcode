class Solution {
public:
    int numOfWays(vector<int>& nums) {
        
		int n = nums.size();
        
		// Pascal triangle
        triangle.resize(n + 1);
        for(int i = 0; i < n + 1; ++i){
            triangle[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j){
                triangle[i][j] = (triangle[i-1][j-1] + triangle[i-1][j]) % mod;
            }
        }
        
        long long ans = dfs(nums);
        return ans % mod - 1;
    }
    
private:
    long long mod = 1e9 + 7;
    vector<vector<long long>> triangle;
    long long dfs(vector<int> &nums){
        int n = nums.size();
        if(n <= 2) return 1;
        
		
        vector<int> left, right;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
		
		
        long long left_sub = dfs(left) % mod;
        long long right_sub = dfs(right) % mod;
		
		
		int left_len = left.size(), right_len = right.size();
        return (((triangle[n - 1][left_len] * left_sub) % mod) * right_sub) % mod;
    }
};

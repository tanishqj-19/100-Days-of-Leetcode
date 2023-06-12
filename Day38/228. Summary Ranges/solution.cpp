class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0)
            return {};

        int start = nums[0], end = nums[0];

        for(int i=1; i<nums.size(); i++){
            
            if(nums[i] == 1 + nums[i-1]){
                end = nums[i];
            }else{
                
                if(start != end)
                    res.push_back(to_string(start)+ "->" + to_string(end));
                else
                    res.push_back(to_string(start));
                start = nums[i]; end = nums[i];
                
            }
        }
        if(start != end)
            res.push_back(to_string(start)+ "->" + to_string(end));
        else
            res.push_back(to_string(start));
                

        return res;


    }
};

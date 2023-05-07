class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        
        int n = obs.size();
        vector<int> sub;

        for(int i=0; i<n; i++){
            int j = obs[i];
          
            // Finding the Longest Subsequence and storing it into a vector
            // max elements that can be stored at a time is i
            if(sub.empty() || sub[sub.size() - 1] <= j){
                sub.push_back(j);
                obs[i] = sub.size();
            }else{
                //Index of  First greater element than nums[i]
                int idx = upper_bound(sub.begin(), sub.end(), j) - sub.begin(); 
                //Replacing the greater element with j
                sub[idx] = j;
                // Since the first greatest element is replaced we can find that elements before j are all included in the length
                obs[i] = idx + 1;
                
            }
            
        }
      
        return obs;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0, right = height.size()-1, area=0;

        while(left <= right){
            int currArea = 0;
            if(height[left] <= height[right]){
                currArea = height[left] * (right-left);
                left++;
            }else{
                currArea = height[right] * (right-left);
                right--;
            }

            

            area = max(currArea, area);
                
                
        }

        return area;
    }
};

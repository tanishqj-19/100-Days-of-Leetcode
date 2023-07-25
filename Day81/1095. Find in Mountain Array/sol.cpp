
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {


        int n = mountainArr.length();

        int start = 0, end = n-1;
        int mid = (start + end) / 2;
        while(start < end){
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                start = mid+1;
            else
                end = mid;
            mid = (start + end) / 2;
        }
        if(mountainArr.get(mid) == target)
            return mid;
        start = 0, end = mid-1;
        while(start <= end){
            int mid = (start + end) / 2;

            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) > target)
                end = mid-1;
            else
                start = mid + 1;
        }

        start = mid+1, end = n-1;
        while(start <= end){
            int mid = (start + end) / 2;

            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) < target)
                end = mid-1;
            else
                start = mid + 1;
        }


        return -1;
    }
};

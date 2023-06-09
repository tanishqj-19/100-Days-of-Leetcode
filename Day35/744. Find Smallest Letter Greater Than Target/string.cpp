class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        
        if(target >= letters[n-1])
            return letters[0];
        else
            target++;

        int l = 0, h = n-1;
        while(l < h){
            int mid = (l + h) / 2;
            if(letters[mid] == target) return letters[mid];

            if(letters[mid] < target) l = mid + 1;
            else
                h = mid;
        }

        return letters[h];
    }
};

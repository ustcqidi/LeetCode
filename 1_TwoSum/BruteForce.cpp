/**
暴力搜素，时间复杂度o(n^2)
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int i,j;
        vector<int> ret;
        int len = nums.size();
        
        for (i = 0; i < len; i++) {
            for (j = i+1; j < len; j++) {
                int obj = target - nums[i];
                if (obj == nums[j]) {
                    ret.push(i);
                    ret.push(j);

                    return ret;
                }
            }
        }

        return ret;
    }

};
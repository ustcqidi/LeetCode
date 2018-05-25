class Solution {
public:

    vector<int> twoSum(vector<int> &nums, int target) {
        int i;
        vector<int> ret;
        int len = nums.size();

        map<int, int> numsMap;

// 构造hash表
        for (i = 0; i < len; i++) {
            int num = nums[i]; 
            numsMap[num] = i;
        }

// 遍历求解
        for (i = 0; i < len; i++) {
            int obj = target - nums[i];
            if (numsMap.find(obj) != numsMap.end()) {
                int idx = numsMap[obj];
                if (idx != i) {
                    ret.push_back(i);
                    ret.push_back(numsMap[obj]);
                    break;
                }
            }
        }

        return ret;
    }
};
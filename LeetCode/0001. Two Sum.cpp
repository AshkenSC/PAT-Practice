// LeetCode: 1. Two Sum

/*
神奇的LeetCode判定，必须在函数结尾再加个return才能通过
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> hash;
       for (int i = 0; i < nums.size(); ++i) {
           auto it = hash.find(target - nums[i]);
           if (it != hash.end()) {
               return {it->second, i};
           }
           hash[nums[i]] = i;
       }
       return {};
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] + nums[j] == target) {
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
            }
        }
        return answer;	// 神奇的LeetCode判定，必须这里加个return才能通过
    }
};
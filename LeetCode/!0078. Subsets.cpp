/*
0078. Subsets

给定一组不含重复元素的整数数组。返回所有可能的子集。注意：结果不能包含重复子集。

思路：遍历该整数数组。将最终返回的结果集合记做result。
每次遍历到一个新数，result中就要新增加：由result中所有子集加上当前这个数构成的一系列新集合。
例如，输入[1,2,3]，遍历到了3，此时result里为[[], 1, 2, 12]。那么result里就要新增以下子集：1, 12, 23, 123。
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> emptySet;
        result.push_back(emptySet);
        for (int i = 0; i < nums.size(); i++) {
            // 向当前结果集合里所有子集（除了空集）添加当前元素, 获得若干新子集，再将他们加入result中
            int currentResultSize = result.size();
            for (int j = 0; j < currentResultSize; j++) {
                vector<int> newSubset = result[j];
                newSubset.push_back(nums[i]);
                result.push_back(newSubset);
            }
        }
        return result;
    }
};

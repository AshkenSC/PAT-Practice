/*
设置字典，记录每个数字的出现次数。当有一个数的出现次数达到N次，循环中止并返回值。

注意：
1）对于map，用insert方式插入时，出现过的key不会被覆盖，而是报错；使用[]的方式则可以覆盖。
*/

#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int, int> occurCount;
        for (int i = 0; i < A.size(); i++) {
            occurCount[A[i]] = occurCount[A[i]] + 1;
            if (occurCount[A[i]] == A.size() / 2) {
                return A[i];
            }
        }
        return A[0];    // 虽然永远都用不到，但是这里不写一个，LeetCode就会报错。
    }
};

int main() {

    Solution sol;
    vector<int> A = { 5,1,5,2,5,3,5,4 };
    int res = sol.repeatedNTimes(A);
    cout << res;

    return 0;
}